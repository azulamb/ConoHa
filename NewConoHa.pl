#!/usr/bin/perl

use strict;
use warnings;

&Main( 'ConoHaAA.txt' );

sub Main()
{
  my ( $file ) = ( @_ );

  my @conoha;
  unless ( open( FILE, $file ) ){ print "Cannot open \"$file\".\n"; exit( 1 ); }
  @conoha = <FILE>;
  close( FILE );

  foreach ( @conoha ){ chomp( $_ ); }

  my $width = 0;
  foreach ( @conoha )
  {
    my $len = length( $_ );
    if ( $width < $len ){ $width = $len; }
  }

  unless ( open( FILE, 'ConoHa.c' ) ){ print "Cannot open \"ConoHa.c\".\n"; exit( 1 ); }
  my @src = <FILE>;
  my @source;
  while ( @src )
  {
    my $line = shift( @src );
    unless ( $line =~ /^(\#define WIDTH)/ ){ push( @source, $line ); next(); }
    push( @source, sprintf( "#define WIDTH %d\n", $width + 2 ) );
    last();
  }

  while ( @src )
  {
    my $line = shift( @src );
    unless ( $line =~ /^\{/ ){ push( @source, $line ); next(); }
    push( @source, "{\n" );
    my $format = sprintf( "	\"%s-%ds \",\n", '%', $width );
    foreach ( @conoha )
    {
      push( @source, sprintf( $format, $_ ) );
    }
    last();
  }

  while ( @src )
  {
    my $line = shift( @src );
    if ( $line =~ /\"\\n\"\}\;/ ){ last(); }
  }

  push( @source, "\"\\n\"};\n", @src );

  close( FILE );

  unless ( open( FILE, '> ConoHa.c' ) ){ print "Cannot write \"ConoHa.c\".\n"; exit( 1 ); }
  print FILE @source;
  close( FILE );

  unless ( open( FILE, 'README.md' ) ){ print "Cannot open \"README.md\".\n"; exit( 1 ); }
  @src = <FILE>;

  @source = ();

  while ( @src )
  {
    my $line = shift( @src );
    unless ( $line =~ /^(    )/ ){ push( @source, $line ); next(); }
    my $count = 0;
    foreach ( @conoha )
    {
      push( @source, sprintf( "    %s", $_ ) );
      if ( ++$count == 7 ){ push( @source, "     あなたの作業を見守るよ！" ); }
      push( @source, "\n" );
    }
    last();
  }

  while ( @src )
  {
    my $line = shift( @src );
    unless ( $line =~ /^(    )/ ){ last(); }
  }

  push( @source, "\n", @src );

  close( FILE );

  unless ( open( FILE, '> README.md' ) ){ print "Cannot write \"README.md\".\n"; exit( 1 ); }
  print FILE @source;
  close( FILE );
}
