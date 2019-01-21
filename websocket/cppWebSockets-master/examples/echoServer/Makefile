hellomake:
	g++ -w -DLOG_TO_STDOUT=1 -DLWS_NO_EXTENSIONS=ON -o echoserver ../../Util.cpp ../../WebSocketServer.cpp echoServer.cpp syslogc.c -l ws2_32 -lwebsockets -I . -I ..\..\..\lws-default-20883362\include -I ..\..\..\wolfssl-3.15.3 -I ..\..\..\wolfssl-3.15.3\wolfssl -L ..\..\..\lws-default-20883362\bin\Release
	