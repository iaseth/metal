#include <iostream>

#include "metal/metal.hpp"

int
main (int argc, char const *argv[])
{
	Metal::Metal m{"this is just some text"};
	m.print_tokens();
	return 0;
}
