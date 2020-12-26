#include <system/SystemUtils.h>

#include <iostream>
#include <stdexcept>
#include <stdio.h>

namespace RStd {
namespace SystemUtils {

	string exec(string command) {

		char buffer[128];
		string result = "";
		FILE* pipe = popen(command.c_str(), "r");
		if (!pipe) throw runtime_error("popen() failed!");
		try {
			while (fgets(buffer, sizeof buffer, pipe) != NULL) {
				result += buffer;
			}
		} catch (...) {
			pclose(pipe);
			throw;
		}
		pclose(pipe);
		return result;

	}

} // namespace RStd
} // namespace SystemUtils