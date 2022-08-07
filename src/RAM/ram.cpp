//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
#include "ram_func.h"

int main ()
{
	RAM ram;
	
	while (1)
	{		
		switch (*ram.chosen_option)
		{
		case 1:
			std::cout << "1\n";
			ram.read_content();
			*ram.chosen_option = 0;
			break;
		
		case 2:
			std::cout << "2\n";
			*ram.chosen_option = 0;
			break;
		}
	}
  
	return 0;
}
