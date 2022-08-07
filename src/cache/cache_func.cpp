#include "cache_func.h"


Cache::Cache()
{
	info_header();
	init();

	// reading data
	int shmid;
	
	if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
	{
		std::cout << "Error creating the segment shmget" << std::endl;
		return;
	}

	if ((typed_info     = (std::bitset<bit_qnt>*)shmat(shmid, NULL, 0)) == (std::bitset<bit_qnt>*) -1 ||
		(chosen_option  = (int*)shmat(shmid, NULL, 0))                  == (int*) -1                  )
	{
		std::cout << "Error attaching the segment shmat" << std::endl;
		return;
	}
	
	// writing data	
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
	{
		std::cout << "Error creating the segment shmget" << std::endl;
		return;
	}
	
	if ((cache_tag_found = (bool*)shmat(shmid, NULL, 0)) == (bool*) -1)
	{
		std::cout << "Error attaching the segment shmat" << std::endl;
		return;
	}
}


void Cache::info_header()
{
	std::cout <<"\t\t\t\t\t\t  Cache Memory\n\n\n"
			  << "   Valid-bit \t    Tag \t\b\b\bDirty-bit \t "
			  <<"  Data1  \t   Data2  \t   Data3 \t\b    Data4 \t\bCount [LFU]\n\n";
}


void Cache::init()
{
	cache.resize(row_qnt, std::vector<std::bitset<bit_qnt>>(column_qnt, 0));

	std::cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
	for (int i = 0; i < row_qnt; i++)
	{
		std::cout << "   \033[1;32m|\b\b\b\033[0m";
    
		for (int j = 0; j < column_qnt; j++)
		{
			std::bitset<bit_qnt> aa(0);
			cache[i][j] = aa;

			//valid, dirty bit
			if (j == 0 || j == 2)
			{ 
				std::bitset<1> bb(0);
				std::cout << "\t" << bb;
			}

			//tag
			else if (j == 1)
			{ 
				std::bitset<5> cc(0);
				std::cout << "\t   " << cc;	
			}
			
			//counter (LFU)
			else if (j == 7)
			{ 
				std::bitset<3> dd(0);
				std::cout << "\t   " << dd;
			}

			// data
			else
			{ 
				std::cout << "\t  " << aa;
			}      
		}
		
		std::cout << "\033[1;32m    |\n\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
	}
}


void Cache::search_tag()
{	
	int count_bit_hit = 0;
	*cache_tag_found = true;
	std::cout << "After>> " << *typed_info;
   
	for (int i = 0; i < row_qnt; i++)
	{   
		if (cache[i][valid_bit_column] == 1) // exist some data in this row
		{  
			std::bitset<bit_qnt> fetched_tag(cache[i][tag_column]);
/*
			//compare the fethed tag
			for (int j = 6; j > 1; j--)
			{
				if (fetched_tag[j] != tag)
				{
					count_bit_hit = 0;
					break;
					} 
				
				count_bit_hit++;
			}

			if (count_bit_hit == 5) // all bits matches, so the block is in the cache
			{ 
				*cache_tag_found = true;
				tag_line = i;
				break;
			}
 */
		}
	}
}


/*
  void Function :: cache_find_tag_0() {
  
  bitset<bit_qnt> zero(0);
  
  //fetch a tag to compare
  for(int i = 1; i < cache_row; i++) {

  bitset<bit_qnt> fetched_tag(cache[i][tag_column]);
      
  if(fetched_tag == zero) {
  cache_tag_line = i;
  break;
  }
  }  
  }


  int Function :: cache_check_valid_bit_0() {

  int found_valid_bit_0_index = -1;
  bitset<bit_qnt> zero(0);

  for(int i = 0; i < cache_row; i++) {
  if(cache[i][valid_bit_column] == zero) {
  found_valid_bit_0_index = i;
  break;
  }
  }
  return found_valid_bit_0_index;
  }


  bool Function :: cache_check_dirty_bit_0(int line) {

  bool found_dirty_bit_0 = false;
  bitset<bit_qnt> zero(0);

  if(cache[line][dirty_bit_column] == zero) {
  found_dirty_bit_0 = true;
  }

  return found_dirty_bit_0;
  }


  void Function :: copy_block_to_cache(int free_row_index, int index) {

  //index + 3, because need to run through 4 cells
  int data_index = data_column;
  
  for(int i = index; i <= index+3; i++, data_index++) {
  for(auto [data, address] : main_memory[i]) {
  cache[free_row_index][data_index] = data;
  }
  } 
  }


  int Function :: get_displacement(bitset<bit_qnt> typed_address) {

  bitset<2> displacement;
  
  for(int i = 0; i < 2; i ++) {
  displacement[i] = typed_address[i];
  }
  
  return (int)(displacement.to_ulong());
  }


  void Function :: cache_increment_lfu(int index) {
  
  int aux_int;
  aux_int = (int)(cache[index][count_column].to_ulong()); //convert binary to int
  aux_int += 1; 
  bitset<bit_qnt> aux(aux_int);  //convert the new value to binary
  cache[index][count_column] = aux; //save the value
  }


  int Function :: cache_get_minimum_counter() {

  int m = 1E7;
  int line = -1;
  
  for(unsigned int i = 0; i < cache.size(); i++) {
    
  if((int)(cache[i][count_column].to_ulong()) < m) {
  m = (int)cache[i][count_column].to_ulong();
  line = i;
  }  
  }
  

  // int m = 0;
  // int line = -1;
  
  // for(int i = 0; i < cache.size(); i++) {
    
  //   if((int)(cache[i][count_column].to_ulong()) > m) {
  //     m = (int)cache[i][count_column].to_ulong();
  //     line = i;
  //   }  
  // }

  return  line;
  }





 update info cache

  
	//cache memory
	cout <<"\t\t\t\t\t\t  Cache Memory\n\n"
		 << "   Valid-bit \t   Tag  \t\b\b\bDirty-bit \t Data1  \t Data2  \t Data3  \t Data4 \t\t\bCount [LFU]\n\n";

	cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
	for(int i = 0; i < cache_row; i++) {
		cout << "   \033[1;32m|\b\b\b\033[0m";
    
		for(int j = 0; j < cache_column; j++) {	

			if(j == 0 || j == 2) { //valid, dirty bit
				bitset<bit_qnt> aux(cache[i][j]);
				cout << "\t" << aux[0];
			}
			else if(j == 1) { //tag

				cout << "\t   ";

				bitset<bit_qnt> aux(cache[i][j]);
				for(int i = 6; i > 1; i--) {
					cout << aux[i];
				}
			}
			else if(j == 7) { //counter (LFU)
	
				cout << "\t   " ;

				bitset<bit_qnt> aux(cache[i][j]);
				for(int i = 2; i >= 0; i--) {
					cout << aux[i];
				}
			}
			else { // data
				cout << "\t " << cache[i][j];
			}      
		}
		cout << "\033[1;32m    |\n\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
	}
	cout << "\n\n\n";






*/

