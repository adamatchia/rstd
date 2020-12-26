#include <file/FileUtils.h>

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string/StringUtils.h>

namespace fs = std::filesystem;

namespace RStd {
namespace FileUtils {

	string read(string filename) {
		
		ifstream file (filename);

		if (!file.good()) {
			file.close();
			throw RSTD_FILE_ERROR;
		}

		string store = "";
		string total = "";

		bool first = true;

		while (getline(file, store)) {
			
			if (first) {
				first = false;
			} else {
				total += "\n";
			}

			total += store;
		}

		file.close();

		return total;

	}

	void write(string filename, string data, bool append) {

		ofstream file;

		if (append) {
			file.open(filename.c_str(), ios::app);
		} else {
			file.open(filename.c_str());
		}

		if (StringUtils::endsWith(data, "\n")) {
			file << data.c_str();
		} else {
			file << data.c_str() << endl;
		}

		file.close();

	}

	void write(string filename, string data) {
		return write(filename, data, false);
	}

	vector<string> ls(string path) {

		vector<string> results;

		for (const auto & entry: fs::directory_iterator(path.c_str()))
			results.push_back( string(entry.path()) );

		return results;

	}

} // namespace FileUtils
} // namespace RStd