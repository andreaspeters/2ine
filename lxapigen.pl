#!/usr/bin/perl -w

use warnings;
use strict;
use File::Basename;

my %typesizes = (
    'LONG' => 4,
    'ULONG' => 4,
    'SHORT' => 2,
    'USHORT' => 2,
    'HVIO' => 2,
    'HKBD' => 2,
);

sub typesize {
    my $t = shift;
    return 4 if ($t =~ /\AP/);  # pointers are 4 bytes (16:16).
    die("Unknown type '$t', please update \%typesizes\n") if not defined $typesizes{$t};
    return $typesizes{$t};
}

chdir(dirname(__FILE__)) or die("failed to chdir to script location: $!\n");

processDir("native");
processDir("native/doscalls");

sub processDir {
  my $dirname = $_[0];
  opendir(DIRH, $dirname) or die("Failed to opendir '$dirname': $!\n");
while (readdir(DIRH)) {
    next if not /\.h\Z/;
    next if /\Aos2/;
    next if /\-lx\.h\Z/;

    my $module = $_;
    my $header = "$dirname/$module";
    $module =~ s/\.h\Z//;
    open(IN, '<', $header) or die("Failed to open '$header' for reading: $!\n");

    print("$module ...\n");

    my %ordinalmap = ();
    my $has16bitfns = 0;

    while (<IN>) {
        chomp;
        next if not /OS2APIINFO/;
        my $line = $_;

        if (/\AOS2EXPORT\s+(.*?)\s+(OS2API|OS2API16)\s+(.*?)\s*\((.*?)\)\s+OS2APIINFO\((.*?)\);/) {
            my %table = (
                'rettype' => $1,
                'apitype' => $2,
                'fn' => $3,
                'args' => $4,
            );
            my $apiinfo = $5;

            my $is16bit = $table{'apitype'} eq 'OS2API16';
            $table{'is16bit'} = $is16bit;
            $has16bitfns |= $is16bit;

            #print("rettype='$rettype' fn='$fn' args='$args' apiinfo='$apiinfo'\n");

            my $fn = $table{'fn'};
            my $ordinal = undef;
            my $expname = undef;
            if ($apiinfo =~ /\A(\d+)\Z/) {
                $ordinal = int($1);
            } else {
                foreach (split(/,/, $apiinfo)) {
                    #print("apiinfoarg: '$_'\n");
                    my ($infokey, $infoval) = /\A(.*?)\=(.*)\Z/;
                    #print("apiinfo key='$infokey' val='$infoval'\n");
                    if ($infokey eq 'ord') {
                        if ($infoval =~ /\A(\d+)\Z/) {
                            $ordinal = int($1);
                        } else {
                            die("Invalid ordinal '$infoval' for '$fn'\n");
                        }
                    } elsif ($infokey eq 'name') {
                        $expname = $infoval;
                    } else {
                        die("unknown OS2APIINFO key '$infokey' for '$fn'\n");
                    }
                }
            }

            $table{'ordinal'} = $ordinal;
            $table{'expname'} = $expname if defined $expname;

            if (defined $ordinalmap{$ordinal}) {
                my $dupfn = $ordinalmap{$ordinal}{'fn'};
                die("Duplicate ordinal #$ordinal between '$fn' and '$dupfn'\n");
            }

            $ordinalmap{$ordinal} = \%table;
        } else {
            die ("Couldn't parse:\n\n  $line\n\n")
        }
    }

    close(IN);

    next if (not %ordinalmap);  # no exported items?

    #use Data::Dumper qw(Dumper); print Dumper \%ordinalmap;


    # Here we go...

    my $finalfname = "$dirname/$module-lx.h";
    my $outfname = "$finalfname-new";
    open(OUT, '>', $outfname) or die("Failed to open '$outfname' for writing: $!\n");

    print OUT <<EOF
/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 */

/* THIS FILE IS AUTOGENERATED. DO NOT EDIT BY HAND. see lxapigen.pl */

/* This is glue code for OS/2 binaries. Native binaries don't need this. */
#if LX_LEGACY

EOF
;

    foreach (sort { $a <=> $b } keys(%ordinalmap) ) {
        my $tableref = $ordinalmap{$_};
        my $fn = $tableref->{'fn'};
        my $argstr = $tableref->{'args'};
        my $rettype = $tableref->{'rettype'};
        my $is16bit = $tableref->{'is16bit'};
        my @args = ();

        if (($argstr ne 'VOID') and ($argstr ne 'void')) {
            @args = split /,/, $argstr;
        }

        # Build a little wrapper that'll pull arguments off the stack and
        #  convert to whatever the native calling conventions are.
        if ($is16bit) {
            print OUT "static $rettype bridge16to32_$fn(uint8 *args) {\n";
            #foreach (@args) {
            # arguments are listed backwards here.
            for my $i (reverse 0..$#args) {
                my $arg = $args[$i];
                my ($t, $n) = $arg =~ /\A\s*(.*?)\s+(.*?)\s*\Z/;
                #print("arg='$_' t='$t' n='$n'\n");
                my $a = ($t =~ /\AP/) ? 'PTRARG' : 'ARG';  # it's a pointer?
                print OUT "    LX_NATIVE_MODULE_16BIT_BRIDGE_$a($t, $n);\n";
            }

            print OUT "    ";
            if (($rettype ne 'void') && ($rettype ne 'VOID')) {
                # Currently it's reasonable to assume the retval will land in EAX.
                print OUT "return ";
            }

            print OUT "$fn(";
            my $comma = '';
            foreach (@args) {
                my ($t, $n) = /\A\s*(.*?)\s+(.*?)\s*\Z/;
                print OUT "$comma$n";
                $comma = ', ';
            }
            print OUT ");\n";

            print OUT "}\n\n";
        }
    }

    if ($has16bitfns) {
        print OUT "LX_NATIVE_MODULE_16BIT_SUPPORT()\n";
        foreach (sort { $a <=> $b } keys(%ordinalmap) ) {
            my $tableref = $ordinalmap{$_};
            next if not $tableref->{'is16bit'};
            my $fn = $tableref->{'fn'};
            print OUT "    LX_NATIVE_MODULE_16BIT_API($fn)\n";
        }

        print OUT "LX_NATIVE_MODULE_16BIT_SUPPORT_END()\n";
        print OUT "\n";
        print OUT "LX_NATIVE_MODULE_DEINIT({\n";
        print OUT "    LX_NATIVE_MODULE_DEINIT_16BIT_SUPPORT();\n";
        print OUT "})\n";
        print OUT "\n";
        print OUT "static int init16_$module(void) {\n";
        print OUT "    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT()\n";

        foreach (sort { $a <=> $b } keys(%ordinalmap) ) {
            my $tableref = $ordinalmap{$_};
            next if not $tableref->{'is16bit'};
            my $fn = $tableref->{'fn'};
            my $argstr = $tableref->{'args'};
            my $argbytes = 0;
            my @args = ();

            if (($argstr ne 'VOID') and ($argstr ne 'void')) {
                @args = split /,/, $argstr;
            }

            foreach (@args) {
                my ($t, $n) = /\A\s*(.*?)\s+(.*?)\s*\Z/;
                $argbytes += typesize($t);
            }
            print OUT "        LX_NATIVE_INIT_16BIT_BRIDGE($fn, $argbytes)\n";
        }

        print OUT "    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT_END()\n";
        print OUT "    return 1;\n";
        print OUT "}\n\n";
    }

    print OUT "LX_NATIVE_MODULE_INIT(";
    if ($has16bitfns) {
        print OUT "{ if (!init16_$module()) return 0; }";
    }
    print OUT ")\n";

    my $comma = '';
    foreach (sort { $a <=> $b } keys(%ordinalmap) ) {
        my $tableref = $ordinalmap{$_};
        my $fn = $tableref->{'fn'};
        my $expname = $tableref->{'expname'};
        my $ordinal = $tableref->{'ordinal'};
        my $suffix = $tableref->{'is16bit'} ? '16' : '';

        print OUT $comma;
        if (defined $expname) {
            print OUT "    LX_NATIVE_EXPORT${suffix}_DIFFERENT_NAME($fn, \"$expname\", $ordinal)";
        } else {
            print OUT "    LX_NATIVE_EXPORT${suffix}($fn, $ordinal)";
        }
        $comma = ",\n";
    }
    print OUT "\n";

    print OUT <<EOF
LX_NATIVE_MODULE_INIT_END()

#endif /* LX_LEGACY */

/* end of $module-lx.h ... */

EOF
;

    close(OUT);

    if ((system("diff -uN '$finalfname' '$outfname'") == -1) || ($? != 0)) {
        rename($outfname, $finalfname) or die("Failed to rename '$outfname' to '$finalfname': $!\n");
    } else {
        unlink($outfname);  # they match, just delete the new copy so build system doesn't rebuild everything.
    }
}

closedir(DIRH);
}

# end of lxapigen.pl ...

