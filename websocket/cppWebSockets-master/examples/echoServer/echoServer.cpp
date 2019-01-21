/** --------------------------------------------------------------------------
 *  echoServer.cpp
 *
 *  A basic example of how to implement a WebSocketServer.  Creats a WS server
 *  bound to port 8080.  It listens for connections, and when a message is 
 *  received, it echos the same message back to the client.
 *
 *  Author    : Jason Kruse <jason@jasonkruse.com> or @mnisjk
 *  Copyright : 2014
 *  License   : BSD (see LICENSE)
 *  -------------------------------------------------------------------------- 
 **/

// Log to stdout for easy debugging.
#define LOG_TO_STDOUT 1

#include "../../Util.h"
#include "../../WebSocketServer.h"

using namespace std;

// For any real project this should be defined separately in a header file
class EchoServer : public WebSocketServer
{
public: 
    EchoServer( int port );
    ~EchoServer( );
    virtual void onConnect(    int socketID                        );
    virtual void onMessage(    int socketID, const string& data    );
    virtual void onDisconnect( int socketID                        );
    virtual void   onError(    int socketID, const string& message );
};

int main( int argc, char **argv )
{
	//init_syslog();
    EchoServer es = EchoServer( 8888 );
    es.run( );
}

EchoServer::EchoServer( int port ) : WebSocketServer( port )
{
}

EchoServer::~EchoServer( )
{
	
}


void EchoServer::onConnect( int socketID )
{
    Util::log( "New connection" );
}

void EchoServer::onMessage( int socketID, const string& data )
{
    // Reply back with the same message
    Util::log( "Received: " + data );
	string dataX[10] = {"18.5783,73.6827","18.5793,73.6857","18.5800,73.6827","18.5810,73.6827","18.5820,73.6827","18.5830,73.6827","18.5840,73.6827","18.5850,73.6827","18.5860,73.6827","18.5870,73.6827"};
	static int i=0;

		this->send( socketID, dataX[i] );
		i++;

		if(i > 10)
		{
			//onDisconnectWrapper(socketID);
			exit(0);
			
		}
		
		
}

void EchoServer::onDisconnect( int socketID )
{
    Util::log( "Disconnect" );
}

void EchoServer::onError( int socketID, const string& message )
{
    Util::log( "Error: " + message );
}


