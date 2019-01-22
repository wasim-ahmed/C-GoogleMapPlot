
C++ Google Map Plot

Coordinates can be plotted using this project on to the Google Map from a C++ application. Google map is opened in the browser which start the communication
with C++ application on Connect button via web socket. Currently the C++ application is hard coded with the coordinates which are communicated and plotted 
on map. C++ application can be modified to receive the data(coordinates) at real time. 

SetUp

1. Map can be loaded on the same machine or on the network. For opening map on a network we need a web server, for this reason Mongoose Web Server is used.
 So if you want to open map on a network start web server first. By default the home page is index.html & port is 8000. you can change it to port 80 if
 you have admin rights. For changing port & name of index file edit "simplest_web_server.c" and build it.
 
2. The HTML file is coded as a web socket Client (by default provided by Google Chrome web browser)and it expects the connection on local host & port 8888.
 You can change these values[ip address & port number] in index.html

3. The C++ application acts as web socket Server. When it gets the connect request from HTML file connection gets established & it start sending coordinates
	to HTML file (web socket Client) where these coordinates are plotted on to Google map. To make changes in this C++ application edit "echoServer.cpp" and 
	build it using make.
	
4. The communication between Web socket Client & Server is request response. That is Client will request the data @ 1Hz & server will reply with coordinates.
  
	
Execution

1. Start web server : server.exe
2. Load the index.html in Google Chrome: ipaddress:8000 for e.g. if on same machine then use localhost:8000 or if on network XXX.XXX.XXX.XXX:port number
3. Start the web socket server : echoserver.exe
4. Click the connect button on browser to start the communication.

Note : Web Socket application will gets disconnected after sending 10 coordinates

Software component:

1. Web socket C++ application @ https://github.com/mnisjk/cppWebSockets
2. Web socket C++ application requires syslog obtained @ https://github.com/secure-endpoints/syslog-win32
3. Web socket requires wolfssl which is obtained @  https://www.wolfssl.com/
4. Web Socket binaries are obtained from @ https://ci.appveyor.com/project/lws-team/libwebsockets . For official website @ https://libwebsockets.org/ 
5. Mongoose Web Server from @ https://cesanta.com/


The project is build on Windows 10 using MinGw 4.7.2

