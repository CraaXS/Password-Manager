#include "passord-manager.hpp"

int main() {
	char l;
	int option;
	std::string user, password, log_user, log_pass;

	std::cout << "Welcome to the passwordmanager" << std::endl;

	while (option != 4) {

		std::cout << "1. Create account" << std::endl;
		std::cout << "2. Save passwords" << std::endl;
		std::cout << "3. Show passwords" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cin >> option;

		switch (option) {
			case 1:
				Logcheck::uspass(user, password);
				Logcheck::enc(password, user);
				std::cout << "Account created successfully" << std::endl << std::endl;
				break;
			case 2:
				int howmany;
				std::cout << "You can save up to 5 passwords" << std::endl;
				std::cout << "How many do you want to save?" << std::endl;
				std::cin >> howmany;
				for (int i = 1; i < howmany + 1; i++) {
					std::cout << "Password " << i << ":" << std::endl;
					std::cin >> password;
					std::ofstream f("passes/pass" + std::to_string(i) + ".txt");
					for (char c : password) {
						f << encrypt[c];
					}
				}
				break;
			case 3:
				std::string acc_pass, acc_user, encpassy;
				std::cout << "Username" << std::endl;
				std::cin >> user;
				std::cout << "Password" << std::endl;
				std::cin >> password;

				std::ifstream f("passes/login.txt");
				std::getline(f, acc_user);
				std::getline(f, acc_pass);
				f.close();
				for (char c : password) {
					encpassy += encrypt[c];
				}

				if (user == acc_user && encpassy == acc_pass) {
					std::string pass, depass;
					for (int i = 1; i < 6; i++) {
						std::ifstream f("passes/pass" + std::to_string(i) + ".txt");
						std::getline(f, pass);
						for (int i = 0; i < pass.length(); i += 5) {
							std::string five = pass.substr(i, 5);
							depass.push_back(decrypt[five]);
						}
						std::cout << depass << std::endl;
						depass = "";
					}
					break;
				} else {
					std::cout << "Wrong username or password" << std::endl;
					break;
				}
		}
	}



	return 0;
}
