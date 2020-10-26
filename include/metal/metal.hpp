#ifndef METAL_HPP_IS_INCLUDED
#define METAL_HPP_IS_INCLUDED

#include <string>
#include <vector>

namespace Metal
{
	class Token
	{
		//
	};

	class Metal
	{
		private:
			int number_of_tokens;
			std::string text;
			std::vector<Token> tokens;

		public:
			Metal (std::string text);
			~Metal ();
			void print ();
			void print_tokens ();
	};
};

#endif