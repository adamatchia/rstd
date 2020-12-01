#include <csv/CSVParser.h>
#include <string/StringUtils.h>

#include <vector>
using namespace std;

namespace RStd {
namespace CSVParser {

	Table parse(string raw) {

		Table table;

		vector<string> lines = StringUtils::splitStringMode(raw, '\n', true);

		for (auto &c : lines) {

			vector<string> cells = StringUtils::splitStringMode(c, ',', true);

			table.data.push_back(cells);

		}

		return table;

	}

}
}