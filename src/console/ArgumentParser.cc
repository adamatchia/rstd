#include <console/ArgumentParser.h>

#include <string/StringUtils.h>

namespace RStd {
namespace Console {

ArgumentParser::ArgumentParser(int argc, char** argv) {

	vector<string> tokens;

	for (int i = 0; i < argc; i++) {

		if (i == 0)
			continue;

		string arg = string(argv[i]);

		if (StringUtils::startsWith(arg, "--")) {

			this->flags.push_back( StringUtils::replace(arg, "--", "", 1) );
		
		} else if (StringUtils::startsWith(arg, "-")) {

			arg = StringUtils::replace(arg, "-", "", 1);

			vector<string> components = StringUtils::split(arg, "=");

			if (components.size() == 2) {

				this->itemsNames.push_back( components.at(0) );
				this->itemsValues.push_back( components.at(1) );

			}


		} else {

			this->core.push_back(arg);

		}

	}

}

bool ArgumentParser::hasFlag(string flag) {

	for (auto &f : this->flags) {

		if (f == flag) {
			return true;
		}

	}

	return false;

}

} // namespace Console
} // namespace RStd