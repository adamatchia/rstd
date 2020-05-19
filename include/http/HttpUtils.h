#ifndef RSTD_HTTP_HTTP_UTILS_H_
#define RSTD_HTTP_HTTP_UTILS_H_

#include "http.h"

#include <string>
using std::string;

namespace RStd
{

namespace HttpUtils
{


string getHeaderValue(httplib::Request& req, string);
string getCookie(httplib::Request& req, string);

} // namespace HttpUtils

} // namespace RStd

#endif