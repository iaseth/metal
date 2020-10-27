#include <iostream>
#include <fstream>
#include <sstream>

#include "metal/metal.hpp"

int
main (int argc, char const *argv[])
{
	if (argc < 2) {
		std::cout << "Too few arguments.\n";
	} else {
		for (int i = 1; i < argc; ++i) {
			std::ifstream in(argv[i]);
			if (in.is_open()) {
				std::stringstream buffer;
				buffer << in.rdbuf();
				Metal::Metal m{buffer.str()};
				std::cout << "Tokens found in \"" << argv[i] << "\":\n";
				m.print_tokens();
			} else {
				std::cout << "Could not open: " << argv[i] << '\n';
		}
			}
	}
	return 0;
}
