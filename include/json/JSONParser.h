#ifndef RSTD_JSON_JSON_PARSER_H_
#define RSTD_JSON_JSON_PARSER_H_

#include <string>
using std::string;

namespace RStd
{

class JSONParser
{

public:

	JSONParser();

	void parse(string);

}; // class JSONParser

} // namespace RStd

#endif