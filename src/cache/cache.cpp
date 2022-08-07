#include <bits/stdc++.h>
#include <bitset>

//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "cache_func.h"

#define SHMSZ 27

int main ()
{
	Cache cache;	
	
	while (1)
	{		
		switch (*cache.chosen_option)
		{
		case 1:
			cache.search_tag();
			*cache.chosen_option = 0;
			break;
	   
		}
	}
  
	return 0;
}
