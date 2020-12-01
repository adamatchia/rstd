#ifndef _RSTD_CSVPARSER_H_
#define _RSTD_CSVPARSER_H_

#include "../data/Table.h"
using RStd::Data::Table;

#include <string>
using namespace std;

namespace RStd {
namespace CSVParser {

	Table parse(string);

}
}

#endif