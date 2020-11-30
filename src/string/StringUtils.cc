#include <string/StringUtils.h>

namespace RStd {
namespace StringUtils {

	bool startsWith(string target, string compare) {

		if (compare.size() > target.size())
			return false;

		bool starts = true;

		for (int i = 0; i < target.size(); i++) {

			if (compare.size() == i)
				break;

			if (compare.at(i) != target.at(i))
				starts = false;

		}

		return starts;

	}

} // namespace StringUtils
} // namespace rstd