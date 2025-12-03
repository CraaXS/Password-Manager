#include "passord-manager.hpp"

int main() {
	char l;
	int option;
	std::string user, password, log_user, log_pass;

	std::cout << "Welcome to the passwordmanager" << std::endl;

	while (option != 5) {
		std::cout << "==================" << std::endl;
		std::cout << "1. Create account" << std::endl;
		std::cout << "2. Save passwords" << std::endl;
		std::cout << "3. Show passwords" << std::endl;
		std::cout << "4. Delete password" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << ": ";
		std::cin >> option;

		switch (option) {
			case 1: {
					Logcheck::uspass(user, password);
					Logcheck::enc(password, user);
					std::cout << "Account created successfully" << std::endl << std::endl;
					break;
				}
			case 2: {
					int howmany;
					std::string oldpass;
					char yn;
					std::cout << "You can save up to 5 passwords" << std::endl;
					std::cout << "Where should the password be saved?" << std::endl;
					std::cin >> howmany;

					std::ifstream f("passes/pass" + std::to_string(howmany) + ".txt");
					std::getline(f, oldpass);
					f.close();

					if (oldpass != "") {
						std::cout << "Password " << howmany << " is already set do you want to replace it? (y for yes and n for no) ";
						std::cin >> yn;
						if (yn == 'y') {
							std::cout << "Password " << howmany << ": ";
							std::cin >> password;
							std::ofstream f("passes/pass" + std::to_string(howmany) + ".txt");
							for (char c : password) {
								f << encrypt[c];
							}
							
							std::cout << "Password " << howmany << " has been set" << std::endl;

						} else if (yn == 'n'){
							std::cout << "password not set" << std::endl;
						} else {
							std::cout << "Wrong input only 'y' or 'n'"  << std::endl;
						}
					} else {

						std::cout << "Password " << howmany << ": ";
						std::cin >> password;
						std::ofstream f("passes/pass" + std::to_string(howmany) + ".txt");
						for (char c : password) {
							f << encrypt[c];
						}
						std::cout << "Password " << howmany << " has been set" << std::endl;
					}


					break;

				}
			case 3: {
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
						int which;
						std::cout << "Which password do you want to see? (1 2 3 4 5)" << std::endl;
						std::cin >> which;
						std::ifstream f("passes/pass" + std::to_string(which) + ".txt");
						std::getline(f, pass);
						f.close();
						for (int i = 0; i < pass.length(); i += 5) {
							std::string five = pass.substr(i, 5);
							depass.push_back(decrypt[five]);
						}
						std::cout << "Your password number " << which << " is " << depass << std::endl;
						break;
					} else {
						std::cout << "Wrong username or password" << std::endl;
						break;
					}
				}

			case 4: {
					std::string acc_pass, acc_user, encpassy;
					int x;

					std::cout << "Username" << std::endl;
					std::cin >> user;

					std::cout << "Password" << std::endl;
					std::cin >> password;

					std::cout << "Which password do you want to delete? " << std::endl;
					std::cin >> x;

					std::ifstream f("passes/login.txt");
					std::getline(f, acc_user);
					std::getline(f, acc_pass);
					f.close();

					for (char c : password) {
						encpassy += encrypt[c];
					}

					if (user == acc_user && encpassy == acc_pass) {
						std::ofstream f("passes/pass" + std::to_string(x) + ".txt");
						f << "";
						f.close();
						std::cout << "Password " << x << " deleted" << std::endl;
					} else {
						std::cout << "Wrong username or password" << std::endl;
					}
					break;

				}
		}
	}



	return 0;
}
