#ifndef METAL_HPP_IS_INCLUDED
#define METAL_HPP_IS_INCLUDED

#include <string>
#include <vector>

namespace Metal
{
	enum TokenType {
		METAL_OPERATOR,
		METAL_KEYWORD,
		METAL_IDENTIFIER,

		METAL_NONE
	};

	class Token
	{
		private:
			TokenType token_type;
			char ch;
			std::string text;
			int line_number;
			int column_number;
			friend class Metal;

		public:
			Token (TokenType token_type);
			~Token ();
			void print ();
			bool isNoneType ();
	};

	class Metal
	{
		private:
			int number_of_tokens;
			std::string text;
			std::vector<Token*> tokens;

		public:
			Metal (std::string text);
			~Metal ();
			void print ();
			void print_tokens ();
	};
};

#endif