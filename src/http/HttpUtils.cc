#include <http/HttpUtils.h>

#include <http/http.h>

#include <string>
using std::string;

namespace RStd
{

namespace HttpUtils
{

string getHeaderValue(httplib::Request& req, string name)
{

	if (req.has_header(name.c_str())) {
		return req.get_header_value(name.c_str());
	}

	throw -1;

	return "";

}

string getCookie(httplib::Request& req, string name)
{

	string raw = HttpUtils::getHeaderValue(req, "Cookie");

	return raw;

}

} // namespace HttpUtils

} // namespace RStd