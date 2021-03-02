//#include <string/StringUtils.h>
#include <string/StringUtils.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <algorithm>

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

		string store;

		for (int i = 0; i < target.size(); i++) {

			string compStr;

			for (int x = 0; x < oldStr.size(); x++) {

				if (i + x + 1> target.size()) {
					break;
				} 

				compStr += target.at(i+x);

			}

			if (compStr == oldStr) {
				
				counter++;

				if (count == -1 || counter <= count) {
					components.push_back(store);
					store = "";
					components.push_back("$REPLACE$");
					i += oldStr.size() - 1;
				}

			} else {
				store += target.at(i);
			}

		}

		components.push_back(store);

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

	bool contains(string target, string compareTo) {

		for (int i = 0; i < target.size(); i++) {

			string compStr;

			for (int x = 0; x < compareTo.size(); x++) {

				if (i + x + 1> target.size()) {
					break;
				} 

				compStr += target.at(i+x);

			}

			if (compStr == compareTo) {
				return true;
			}

		}

		return false;

	}

	int countContains(string target, string compareTo) {

		int count;

		for (int i = 0; i < target.size(); i++) {

			string compStr;

			for (int x = 0; x < compareTo.size(); x++) {

				if (i + x + 1> target.size()) {
					break;
				} 

				compStr += target.at(i+x);

			}

			if (compStr == compareTo) {
				count++;
				i += compareTo.size() - 1;
			}

		}

		return count;

	}

	vector<string> splitStringMode(string target, string splitString, bool stringModeEnabled) {

		vector<string> tokens;

		string store;

		bool stringMode = false;

		// Optimization
		if (splitString.size() == 1) {


			char s = splitString.at(0);

			for (auto &c : target) {

				if (stringModeEnabled) {

					if (c == '"') {
						stringMode = !stringMode;
						continue;
					}

				}

				if ((c == s && !stringMode && stringModeEnabled) || c == s && !stringModeEnabled) {
					tokens.push_back(store);
					store = "";
				} else {
					store += c;
				}

			}


		} else {

			for (int i = 0; i < target.size(); i++) {

				if (stringModeEnabled) {

					if (target.at(i) == '"') {
						stringMode = !stringMode;
						continue;
					}

				}

				string compStr;

				for (int x = 0; x < splitString.size(); x++) {

					if (i + x + 1> target.size()) {
						break;
					} 

					if (stringModeEnabled) {

						if (!stringMode) {
							compStr += target.at(i+x);
						}

					} else {
						compStr += target.at(i+x);
					}

					

				}

				if (compStr == splitString) {
					

					if (store != "")
						tokens.push_back(store);

					store = "";

					i += splitString.size() - 1;

				} else {
					store += target.at(i);
				}

			}

		}

		if (store != "") {
			tokens.push_back(store);
		}

		return tokens;

	}

	vector<string> splitStringMode(string target, char c, bool stringMode) {
		string a;
		a += c;
		return splitStringMode(target, a, stringMode);
	}

	vector<string> split(string target, string splitString) {
		return splitStringMode(target, splitString, false);
	}

	vector<string> split(string target, char splitChar) {
		return splitStringMode(target, splitChar, false);
	}

	string toLower(string target) {

		string result;

		for (auto &c : target) {

			int i = (int) c;

			if (65 <= i && i <= 90) {
				i += 32;
			}

			result += (char) i;

		}

		return result;

	}

	string toUpper(string target) {

		string result;

		for (auto &c : target) {

			int i = (int) c;

			if (97 <= i && i <= 122) {
				i -= 32;
			}

			result += (char) i;

		}

		return result;

	}

	string trim(string target) {

		string result;

		bool passed = false;

		for (auto &c : target) {

			if ((c == ' ' || c == '\n' || c == '\t') && !passed) {
				continue;
			} else {
				passed = true;
				result += c;
			}

		}

		target = invert(result);
		result = "";

		passed = false;

		for (auto &c : target) {

			if ((c == ' ' || c == '\n' || c == '\t') && !passed) {
				continue;
			} else {
				passed = true;
				result += c;
			}

		}

		return invert(result);

	}

	string toTitle(string target) {

		string result;

		target = toLower(target);

		bool first = true;

		for (auto &c : target) {

			if (first) {
				
				first = false;
				
				int i = (int) c;

				if (97 <= i && i <= 122) {
					i -= 32;
				}

				result += (char) i;

			} else {
				result += c;
			}

			if (c == ' ') {
				first = true;
			}

		}

		return result;

	}

	string toCurrency(string target) {

		vector<string> tokens = split(target, '.');

		if (tokens.size() != 2) {
			
			if (tokens.size() == 1) {
				tokens.push_back("00");
			} else {
				return target;
			}

		}

		string a = tokens.at(0);
		string b = tokens.at(1);

		a = invert(a);

		string newA;

		int x = 0;

		for (int i = 0; i < a.size(); i++) {

			char c = a.at(i);

			newA += c;

			x++;

			if (x % 3 == 0 && i != a.size() - 1) {
				newA += ',';
			}

		}

		a = newA;

		a = invert(a);

		return a + "." + b;

	}

	int Atoi(string target) {
		return atoi(target.c_str());
	}

	string Itoa(int target) {
		return to_string(target);
	}

	string randomString(int s) {

		string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		random_device rd;

		mt19937 engine(rd());

		uniform_int_distribution<> dist(0, possible_characters.size()-1);

		string ret = "";

		for(int i = 0; i < s; i++){
	        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
	        ret += possible_characters[random_index];
	    }

	    return ret;

		 
	}

} // namespace StringUtils
} // namespace rstd