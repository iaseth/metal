#ifndef METAL_HPP_IS_INCLUDED
#define METAL_HPP_IS_INCLUDED

#include <string>

namespace Metal
{
	class MetalToken
	{
		//
	};

	class Metal
	{
		private:
			int number_of_tokens;
			std::string text;

		public:
			Metal (std::string text);
			~Metal ();
			void print ();
	};
};

#endif