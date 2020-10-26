#include "metal/metal.hpp"

#include <iostream>

namespace Metal
{
	Metal::Metal (std::string text)
	{
		this->text = text;
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
};


