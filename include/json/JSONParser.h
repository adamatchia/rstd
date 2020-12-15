#ifndef RSTD_JSON_JSON_PARSER_H_
#define RSTD_JSON_JSON_PARSER_H_

#include <string>
using std::string;

namespace RStd
{

	class JSONObject {
	
	public:
		
		int id = 0;
		int parent = 0;

		JSONObject();

	};

	class JSONParser {

	public:

		JSONParser();

		void parse(string);

	}; // class JSONParser

} // namespace RStd

#endif