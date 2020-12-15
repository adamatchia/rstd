#include <file/FileUtils.h>

#include <fstream>
#include <filesystem>

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

	void write(string filename, string data) {

		ofstream file (filename);
		file << data;
		file.close();

	}

	vector<string> ls(string path) {

		vector<string> results;

		for (const auto & entry: fs::directory_iterator(path.c_str()))
			results.push_back( string(entry.path()) );

		return results;

	}

}
}