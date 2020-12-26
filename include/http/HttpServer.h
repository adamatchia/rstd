#ifndef _RSTD_HTTP_HTTPSERVER_H_
#define _RSTD_HTTP_HTTPSERVER_H_

#include <string>
using namespace std;

#include <http/http.h>

class HttpHandler {

public:

	string response;

	string response_type;

	httplib::Request &req;
	httplib::Response &res;

	HttpHandler();

	void get_cookie(string);

	void send(string);

	virtual void handle();

};

class HttpServer {

public:

	string host;
	int port;

	httplib::Server server;

	HttpServer(string, int);

	void handle_func(string, HttpHandler*);

	void listen_and_serve();

};

#endif