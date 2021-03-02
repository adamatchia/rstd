#ifndef _RSTD_HTTP_HTTPSERVER_H_
#define _RSTD_HTTP_HTTPSERVER_H_

#include <string>
using namespace std;

#include <http/http.h>

namespace RStd
{

class HttpHandler {

public:

	HttpHandler();

	string response;

	string response_type;

	httplib::Request &req;
	httplib::Response &res;


	string get_cookie(string);

	void send(string);

	virtual void handle();

};

class HttpServer {

public:

	string host;
	int port;

	httplib::Server server;

	void handle_func(string, HttpHandler*);

	void listen_and_serve();

	HttpServer(string, int);

};

} // namespace RStd

#endif