#ifndef LOGIN2_HPP
#define LOGIN2_HPP

#include <fstream>
#include <iostream>
#include <map>

inline std::map<char, std::string> encrypt = {{'a', "aslkd"}, {'b', "bslkj"}, {'c', "czuas"}, {'d', "dauza"}, {'e', "eiakl"}, {'f', "fnbsa"}, {'g', "goaus"}, {'h', "hmgna"}, {'i', "iaopw"}, {'j', "jiuaw"}, {'k', "kemas"}, {'l', "lmnas"}, {'m', "moaiw"}, {'n', "nahwq"}, {'o', "oopnq"}, {'p', "paswi"}, {'q', "quart"}, {'r', "rzaha"}, {'s', "spmsa"}, {'t', "taold"}, {'u', "usdsd"}, {'v', "vabsu"}, {'w', "watnd"}, {'x', "xakjd"}, {'y', "yuazs"}, {'z', "zomro"}, {'1', "apwsd"}, {'2', "kalsd"}, {'3', "assdv"}, {'4', "uhasd"}, {'5', "maljs"}, {'6', "axsdn"}, {'7', "mnasd"}, {'8', "jzauw"}, {'9', "uzqqa"}};

inline std::map<std::string, char> decrypt = {{"aslkd", 'a'}, {"bslkj", 'b'}, {"czuas", 'c'}, {"dauza", 'd'}, {"eiakl", 'e'}, {"fnbsa", 'f'}, {"goaus", 'g'}, {"hmgna", 'h'}, {"iaopw", 'i'}, {"jiuaw", 'j'}, {"kemas", 'k'}, {"lmnas", 'l'}, {"moaiw", 'm'}, {"nahwq", 'n'}, {"oopnq", 'o'}, {"paswo", 'p'}, {"quart", 'q'}, {"rzaha", 'r'}, {"spmsa", 's'}, {"taold", 't'}, {"usdsd", 'u'}, {"vabsu", 'v'}, {"watnd", 'w'}, {"xakjd", 'x'}, {"yuazs", 'y'}, {"zomro", 'z'}, {"apwsd", '1'}, {"kalsd", '2'}, {"assdv", '3'}, {"uhasd", '4'}, {"maljs", '5'}, {"axsdn", '6'}, {"mnasd", '7'}, {"jzauw", '8'}, {"uzqqa", '9'}};


class Logcheck {
	public:
		static void uspass(std::string &user, std::string &password) {
			std::cout << "Give the username: ";
			std::cin >> user;
			std::cout << "Give the password for the user: ";
			std::cin >> password;
		}

		static void enc(std::string &password, std::string &user) {
			std::ofstream f("passes/login.txt");
			f << user << std::endl;
			for (char c : password) {
				f << encrypt[c];
			}
			f.close();
		}
};



#endif
