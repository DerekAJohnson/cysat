#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "pic24.h"

#include "uart.h"
#include "testing.h"

/* TODO: Need better way to do this (Don't judge me) */
#define COMMAND(str)        if(strcmp(pcBase,str)==0&&(sMatchCommand = 1))

void interpretTestingCommand( char* pcCommand )
{
    static char pcBase[uartBUFFER_SIZE];
    static char pcArgs[uartBUFFER_SIZE];

    short sMatchCommand = 0;
    short i;

    pcBase[0] = '\0';
    pcArgs[0] = '\0';

    for( i=0; i<uartBUFFER_SIZE; ++i )
    {
        pcBase[i] = pcCommand[i];

        if( pcCommand[i] == ' ' )
        {
            pcBase[i] = '\0';
            sprintf(pcArgs, "%s", &(pcCommand[i+1]));
            break;
        }

        if( pcCommand[i] == '\0' )
        {
            break;
        }
    }

    COMMAND( "echo" )
    {
        vUartPuts( pcArgs );
    }
    COMMAND( "whoami" )
    {
        vUartPuts( "cysat" );
    }
    COMMAND( "ls" )
    {
        vUartPutsError( "Do I look like a UNIX machine?!" );
    }
    COMMAND( "rm" )
    {
        vUartPuts( "Nice try, jerk." );
    }

    if (!sMatchCommand)
    {
        static char pcEchoCommand[uartBUFFER_SIZE + 40];
        sprintf( pcEchoCommand, "I don't understand '%s'", pcBase );
        vUartPutsError( pcEchoCommand );
    }
    
    vUartPuts( "\r\n" );
}