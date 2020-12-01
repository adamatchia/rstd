#include <data/Table.h>
#include <string/StringUtils.h>

namespace RStd {
namespace Data {

	string Table::stats() {

		vector<int> widths;

		for (auto &c : this->data) {

			int width = c.size();

			bool exists = false;

			for (auto &w : widths) {
				if (w==width) {
					exists = true;
				}
			}

			if (!exists)
				widths.push_back(width);

		}

		string result;

		result += "Rows: " + StringUtils::Itoa(this->data.size()) + " ; ";

		result += "Columns: ";

		bool first = true;

		for (auto &w: widths) {
				
			if (first) {
				first = false;
			} else {
				result += ",";
			}

			result += w;
		}

		return result;

	}
	
}
}