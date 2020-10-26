#include "metal/metal.hpp"

#include <iostream>

namespace Metal
{
	#define METAL_LEXER_LOG(x) std::cout \
		<< "(" << line_number << ", " << column_number << ") '" \
		<< ch << "' " << x << std::endl;

	Metal::Metal (std::string text)
	{
		this->text = text;

		int line_number = 1;
		int column_number = 1;
		char ch;

		for (long unsigned index = 0; index < text.length(); ++index) {
			ch = text[index];

			switch (ch) {
				case ' ':
					METAL_LEXER_LOG("its a space");
					break;
				default:
					METAL_LEXER_LOG("tts not a space");
			}

			if (ch == '\n') {
				line_number++;
				column_number = 1;
			} else if (ch == '\t') {
				column_number += 4;
			} else {
				column_number++;
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

	#undef METAL_LEXER_LOG
};


