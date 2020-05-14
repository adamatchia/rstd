#include <FileUtils.h>

#include <string>
using std::string;

#include <iostream>
using std::getline;

#include <fstream>
using std::ifstream;
using std::ofstream;

namespace RStd
{

namespace FileUtils
{

string read(string filename)
{
	
	ifstream file (filename);

	if (!file.good()) {
		file.close();
		throw RSTD_FILE_ERROR;
	}

	string store = "";
	string total = "";

	while (getline(file, store)) {
		total += store + "\n";
	}

	file.close();

	return total;

}

void write(string filename, string data)
{

	ofstream file (filename);
	file << data;
	file.close();

}

} // namespace FileUtils

} // namespace RStd