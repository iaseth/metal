#include <iostream>

#include "metal/metal.hpp"

int
main (int argc, char const *argv[])
{
	Metal::Metal m{"example"};
	m.print();
	return 0;
}
