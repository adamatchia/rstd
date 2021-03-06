#include <http/HttpServer.h>
#include <http/HttpUtils.h>
#include <http/http.h>

#include <vector>
#include <string>
using namespace std;


#include <string/StringUtils.h>

namespace RStd
{

//HttpHandler::HttpHandler() {}
	
string HttpHandler::get_cookie(string name) {

	if (!req.has_header("Cookies")) {
		return "";
	}

	string raw = req.get_header_value("Cookies");

	vector<string> cookies_raw = StringUtils::split(raw, ';');

	for (auto &c : cookies_raw) {
		
		c = StringUtils::trim(c);

		vector<string> components = StringUtils::split(c, '=');

		if (components.size() != 2) {
			continue;
		}

		if (components.at(0) == name) {
			return components.at(1);
		}

	}

	return "";

}

HttpServer::HttpServer(string host, int port) {

	this->host = host;
	this->port = port;

}


void HttpServer::handle_func(string path, HttpHandler* handler) {

	server.Get(path.c_str(), [&handler](const httplib::Request &req, httplib::Response &res) {

		handler->req = req;
		handler->res = res;

		handler->handle();

		if (handler->response_type == "") {
			handler->response_type = "text/html";
		}

		if (handler->response != "") {
			res.set_content(
				handler->response.c_str(),
				(size_t)sizeof(handler->response.c_str()),
				handler->response_type.c_str()
			);
		}

	});

}

} // namespace RStd