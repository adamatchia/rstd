#ifndef _RSTD_TABLE_H_
#define _RSTD_TABLE_H_

#include <vector>
#include <string>
using namespace std;

namespace RStd {
namespace Data {

	class Table {

		public:
			vector<vector<string>> data;
			string stats();

	};

}
}

#endif