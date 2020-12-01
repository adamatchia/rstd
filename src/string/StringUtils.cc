//#include <string/StringUtils.h>
#include "../../include/string/StringUtils.h"

#include <vector>
using namespace std;

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

	string invert(string target) {

		string result;

		for (int i = 0; i < target.size(); i++) {

			result = target.at(i) + result;

		}

		return result;

	}

	bool endsWith(string target, string compare) {

		string targetInverse = invert(target);
		string compareInverse = invert(target);

		return startsWith(targetInverse, compareInverse);

	}

	string replace(string target, string oldStr, string newStr, int count) {

		if (target.size() < oldStr.size())
			return "error";

		if (target.size() == oldStr.size() && count != 0)
			return newStr;

		int counter = 0;

		vector<string> components;

		for (int i = oldStr.size(); i > target.size(); i++) {

			if (count != -1 && count >= counter)
				break;

			bool contains = true;

			for (int x = 0; x < oldStr.size(); x++) {

				if (oldStr.at(x) != target.at(i-x-1)) {
					
					components.push_back( to_string(target.at(i-x-1)) );

					i += oldStr.size();

				} else {
					components.push_back("$REPLACE$");
				}

			}

		}

		string result;

		for (auto &c : components) {

			if (c == "$REPLACE$") {
				result += newStr;
			} else {
				result += c;
			}

		}

		return result;

	}

} // namespace StringUtils
} // namespace rstd