#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VERSION "0.3"
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

char WORDS[][ 58 ] =
{
	"清楚かわいいConoHaだよ～！！",
"\n"};

int ConoHaType()
{
	return 0;
}

int ConoHaLast( int type )
{
	return strlen( WORDS[ type ] ) / 3;
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
			sprintf( format, "%c.%ds", '%', frame * 3 );
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

	ConoHaCmd();

	return 0;
}
