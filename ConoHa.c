#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define VERSION "1.0"
#define WIDTH 24

char CONOHA[][ WIDTH ] =
{
	"    _==:#####:==,      ",
	" --=+#############,    ",
	"  A######A########A    ",
	" |######V##########|   ",
	" |#   `.   .--''###|   ",
	" |# -ZB     -ABq|##|   ",
	" |E  `'      `' |##A   ",
	" |#`-__` -'   _/####|  ",
	"  VaV##HhVVHhq/#=V|/'  ",
	"   []'_/H||HHH'Hh,     ",
	"    'HHVH||HHHHhVE     ",
	"        H`'AHHA[] `A,  ",
	"       /#########A  #A ",
	"        /_'  | |    ## ",
	"       /#|   |#|  _//' ",
	"        []  []/'       ",
"\n"};

unsigned char WORDS[][ 58 ] =
{
	"清楚かわいいConoHaだよ～！！",
"\n"};

int ByteUTF8Char( const unsigned char *str )
{
	if ( (*str >> 1) == 0x7E ) { return 6; }
	if ( (*str >> 2) == 0x3E ) { return 5; }
	if ( (*str >> 3) == 0x1E ) { return 4; }
	if ( (*str >> 4) == 0xE ) { return 3; }
	if ( (*str >> 5) == 0x6 ) { return 2; }
	return 1;
}

int LengthUTF8String( const unsigned char *str )
{
	int length = 0;
	int byte = 0;

	while ( str[ byte ] != '\0' )
	{
		byte += ByteUTF8Char( str + byte );
		++length;
	}

	return length;
}

int ByteUTF8String( const unsigned char *str, int num )
{
	int byte = 0;
	while ( 0 < num-- )
	{
		byte += ByteUTF8Char( str + byte );
	}
	return byte;
}

int ConoHaType()
{
	return 0;
}

int ConoHaLast( int type )
{
	return LengthUTF8String( WORDS[ type ] );
}

int ConoHaDraw( int type, int frame, int vline )
{
	char format[ 16 ];
	int line = 0;

	while ( CONOHA[ line ][ 0 ] != '\n' )
	{
		printf( "%s", CONOHA[ line++ ] );
		if ( line == vline )
		{
			sprintf( format, "%c.%ds", '%', ByteUTF8String( WORDS[ type ], frame ) );
			printf( format, WORDS[ type ] );
		}
		printf( "\n" );
	}
	return line;
}

void ConoHaCmd()
{
	int line = 2;
	int type;
	int frame = 0;
	int last;

	type = ConoHaType();
	last = ConoHaLast( type );

	while( '-' )
	{
		line = ConoHaDraw( type, frame, line / 2 - 1 );
		if ( last <= ++frame ) { break; }
		sleep( 1 );
		printf( "\033[%dA", line ); // Linux only?
	}
}

void VersionCmd()
{
	printf( "ConoHa cmd ver %s.\n", VERSION );
	ConoHaDraw( 0, 0, 0 );
	exit( 0 );
}

void HelpCmd()
{
	printf( "ConoHa command.\n" );
	printf( "ConoHa is main character by ConoHa VPS(http://www.conoha.jp/)\n" );
	printf( "ConoHa has nothing to do with me.\n" );
	printf( "Can download project by https://github.com/HirokiMiyaoka/ConoHa\n" );
	printf( "\n" );
	printf( "-h, --help ... Heplp. Print this page.\n" );
	printf( "-version,  ... Version. Print version,\n" );
	printf( "-v, --v\n" );
	printf( "--V\n" );
	printf( "\n" );
	exit( 0 );
}

void GoodByeSignal( int signal )
{
}

void RegistrationSignal()
{
	//signal( SIGHUP, GoodByeSignal );
	signal( SIGINT, GoodByeSignal );
	//signal( SIGKILL, GoodByeSignal );
	//signal( SIGTERM, GoodByeSignal );
}

int main( int argc, char **argv )
{
	int num = 1;

	while ( num < argc )
	{
		if ( strcmp( argv[ num ], "-v" ) == 0 ||
		     strcmp( argv[ num ], "--v" ) == 0 ||
		     strcmp( argv[ num ], "--version" ) == 0 ||
		     strcmp( argv[ num ], "--V" ) == 0 )
		{
			VersionCmd();
		} else if ( strcmp( argv[ num ], "-h" ) == 0 )
		{
			HelpCmd();
		}
		++num;
	}

	RegistrationSignal();
	ConoHaCmd();

	return 0;
}
