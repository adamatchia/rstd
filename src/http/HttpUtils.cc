#include <http/HttpUtils.h>

#include <http/http.h>

#include <string>
using std::string;

#include <RStd.h>

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

} // namespace HttpUtils

} // namespace RStd