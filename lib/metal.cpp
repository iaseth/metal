#include "metal/metal.hpp"

#include <iostream>

namespace Metal
{
	Metal::Metal (std::string text)
	{
		this->text = text;

		int line_number = 1;
		int column_number = 1;
		char ch;

		for (long unsigned index = 0; index < text.length(); ++index) {
			ch = text[index];
			if (ch == '\n') {
				line_number++;
				column_number = 1;
			} else if (ch == '\t') {
				column_number += 4;
			} else {
				column_number++;
			}

			switch (ch) {
				case ' ':
					std::cout << "Its a space\n";
					break;
				default:
					std::cout << "Its not a space\n";
			}
		}
	}

	Metal::~Metal ()
	{
		//
	}

	void
	Metal::print ()
	{
		std::cout << "Text: " << this->text << std::endl;
	}

	void
	Metal::print_tokens ()
	{
		//
	}
};


