#ifndef _RSTD_ARGUMENT_PARSER_H_
#define _RSTD_ARGUMENT_PARSER_H_

#include <vector>
#include <string>
using namespace std;

namespace RStd {
namespace Console {

	class ArgumentParser {

	private:

		vector<string> flags;

	public:

		vector<string> core;

		vector<string> itemsNames;
		vector<string> itemsValues;

		ArgumentParser(int, char**);

		bool hasFlag(string);

	};

}
}

#endif