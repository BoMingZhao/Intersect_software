#include "Exception_MD.h"

const char* Exception_MD::what()const throw() 
{
	return "Meaningless definition!Two points coincide in a line definition\n";
}