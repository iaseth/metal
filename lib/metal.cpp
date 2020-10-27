#include "metal/metal.hpp"

#include <iostream>
#include <cctype>

namespace Metal
{
	#define METAL_LEXER_LOG(x) std::cout \
		<< "(" << line_number << ", " << column_number << ") '" \
		<< ch << "' " << x << std::endl;

	Token::Token (TokenType token_type)
	{
		this->token_type = token_type;
		this->ch = '\0';
	}

	Token::~Token ()
	{
		//
	}

	void
	Token::print ()
	{
		std::cout << "\t(" << this->line_number << ", " << this->column_number << ") ";

		if (this->ch) {
			std::cout << '\'' << this->ch << '\'' << '\n';
		} else {
			std::cout << '"' << this->text << '"' << '\n';
		}
	}

	bool
	Token::isNoneType ()
	{
		if (this->token_type == TokenType::METAL_NONE) {
			return true;
		}
		return false;
	}



	Metal::Metal (std::string text)
	{
		this->text = text;

		int line_number = 1;
		int column_number = 1;
		char ch;

		Token *current_token = nullptr;
		int current_token_length = 1;

		for (long unsigned index = 0; index < text.length(); index += current_token_length) {
			ch = text[index];
			if (current_token == nullptr) {
				current_token = new Token(TokenType::METAL_NONE);
				current_token_length = 1;
			}
			current_token->line_number = line_number;
			current_token->column_number = column_number;

			switch (ch) {
				case ' ':
				case '\t':
				case '\n':
					//METAL_LEXER_LOG("its a space");
					break;
				default:
					//METAL_LEXER_LOG("tts not a space");
					while ((index + current_token_length) < text.size()
						&& std::isalnum(text[index + current_token_length])) {
						current_token_length++;
					}
					current_token->token_type = TokenType::METAL_IDENTIFIER;
			}

			if (!current_token->isNoneType()) {
				if (current_token_length > 1) {
					for (int i = 0; i < current_token_length; ++i) {
						current_token->text += text[index+i];
					}
				} else {
					current_token->ch = ch;
				}
				//current_token->print();
				this->tokens.push_back(current_token);
				current_token = nullptr;
			}

			if (ch == '\n') {
				line_number++;
				column_number = 1;
			} else if (ch == '\t') {
				column_number += 4;
			} else {
				column_number += current_token_length;
			}
		}
	}

	Metal::~Metal ()
	{
		for (auto token : this->tokens) {
			delete token;
		}
		this->tokens.clear();
	}

	void
	Metal::print ()
	{
		std::cout << "Text: " << this->text << std::endl;
	}

	void
	Metal::print_tokens ()
	{
		for (auto token : this->tokens) {
			token->print();
		}
	}

	#undef METAL_LEXER_LOG
};


