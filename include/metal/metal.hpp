#ifndef METAL_HPP_IS_INCLUDED
#define METAL_HPP_IS_INCLUDED

#include <string>
#include <vector>

namespace Metal
{
	enum TokenType {
		OPERATOR,
		KEYWORD,
		IDENTIFIER,

		SPACE,
		TAB,
		LINE,

		NONE
	};

	namespace CharFuncs
	{
		bool is_identifier_initial (char ch);
		bool is_identifier_middle (char ch);

		bool is_number_initial (char ch);
		bool is_number_middle (char ch);
	};

	class Token
	{
		private:
			int index;
			TokenType token_type;
			char ch;
			std::string text;
			int line_number;
			int column_number;
			int count;
			friend class Metal;

		public:
			Token (TokenType token_type);
			~Token ();
			void print ();
			bool isNoneType ();
			bool isSpaceType ();
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