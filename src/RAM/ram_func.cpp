#include "ram_func.h"

RAM::RAM()
{
	info_header();
}

void RAM::info_header()
{
	std::cout <<"\t\t\t RAM Memory\n\n\n\n"
			  <<"\t\t   Value \tAddress\n\n";
}

void RAM::init() {

	ram_memory.resize(ram_memory_cell);
	
	int block_counter = 0,
		block_qnt = 0;
  
	for (int i = 0; i < ram_memory_cell; i++)
	{
		if (block_counter == 2)
		{   
			std::cout << "\033[1;36mBlock " << block_qnt << "\033[0m\b\b\b\b\b";
		}

		// convert int to binary
		std::bitset<bit_qnt> binary_value((rand() % 100000)); 
		std::bitset<bit_qnt> binary_address(i);              

		// save values and addresses
		ram_memory[i].push_back({binary_value, binary_address});

		// show values and addresses
		std::cout << "\t\t\033[1;32m|---------|\n" << "\t\t|\033[0m ";
		std::cout << binary_value << "\033[1;32m |\033[0m\t" << binary_address;
		
		if(block_counter == 3)
		{
			std::cout << "\n\t\t\033[1;32m|---------|\033[0m\n\n";
			block_counter = 0;
			block_qnt++;
		}
		else
		{
			std::cout << "\n";
			block_counter++;
		}
	} 
}


void RAM::update_info() {
  
	system("clear");
	info_header();

	int block_counter = 0,
		block_qnt = 0;
  
	for (int i = 0; i < ram_memory_cell; i++)
	{    
		if (block_counter == 2)
		{   
			std::cout << "\033[1;36mBlock " << block_qnt << "\033[0m\b\b\b\b\b";
		}
    
		std::cout << "\t\t\033[1;32m|---------|\n" << "\t\t|\033[0m ";

		for (auto [data, address] : ram_memory[i])
		{
			std::cout << data << "\033[1;32m |\033[0m\t" << address;
		}
    
		if (block_counter == 3)
		{
			std::cout << "\n\t\t\033[1;32m|---------|\033[0m\n\n";
			block_counter = 0;
			block_qnt++;
		}
		else
		{
			std::cout << "\n";
			block_counter++;
		}
	} 
}


void RAM::set_value(std::bitset<bit_qnt> new_address, std::bitset<bit_qnt> new_value)
{
	bool stop = false;
  
	for(unsigned int i = 0; i < ram_memory.size(); i++)
	{
		for(auto [data, address] : ram_memory[i])
		{
			if(address == new_address)
			{
				data = new_value;
				stop = true;
				break;
			}
		}
		
		if(stop)
		{
			break;	
		}		
	}
}



void RAM::read_content_main_memory()
{
	/*
	bool tag_found = cache_memory_search_tag(typed_address);     
	int current_block = get_block_number(typed_address);
	int index = find_beginning_block(typed_address, current_block);
	int displacement = get_displacement(typed_address);
	bitset<bit_qnt> set_bit(1);

  
	//first, search for it in the cache memory
  
	if(tag_found) { //the block is in the cache, read value...
          
    hit_read++; 

    //get the value in the cache memrory
    bitset<bit_qnt> value(cache_memory[cache_memory_tag_line][data_column+displacement]);

    //increment counter LFU
    cache_memory_increment_lfu(cache_memory_tag_line); 

    show_info(value, cache_memory_tag_line, displacement, current_block, true);
	}

	//copy all block in the cache memory
	else { 

    int free_row_index = cache_memory_check_valid_bit_0();
    
    if(free_row_index == -1) {  //if cache is full,  replace data using LFU policy

	//get mininum counter's line
	int line = cache_memory_get_minimum_counter();
      
	//get value
	bitset<bit_qnt> value(cache_memory[line][data_column+displacement]);
      
	//check dirty bit
	bool dirty_bit_0 = cache_memory_check_dirty_bit_0(line);

	//overwrite all data without saving ( dirty bit = 0 ), because the value is already in the main memory
	if(dirty_bit_0) { 

	//set tag
	cache_memory[line][tag_column] = typed_address;

	//copy the new block
	copy_block_to_cache(line, index);

	//set count LFU = 1
	cache_memory[line][count_column] = set_bit;   

	show_info(value, cache_memory_tag_line+1, displacement, current_block, true);	
	}

	//save the data in the main memory before changing the current data (dirty bit = 1)
	else {

	//get the block which the data in the cache belongs
	bitset<bit_qnt> aux = cache_memory[line][tag_column]; //get the address from the line that will be removed
	int block_number = get_block_number(aux); 
	
	//get block number/beginning
	int beginning_block = find_beginning_block(typed_address, block_number);

	//copy all data in the cache memory to main memory,
	for(int i = beginning_block, j = 0; i < beginning_block+4; i++, j++) {
	main_memory[i].back().first = cache_memory[line][data_column+j];
	}
        
	//set tag
	cache_memory[line][tag_column] = typed_address;
	
	//set dirty bit 0
	bitset<bit_qnt> zero(0);
	cache_memory[line][dirty_bit_column] = zero;
	
	//copy the new block
	copy_block_to_cache(line, index);

	//set count LFU = 1
	cache_memory[line][count_column] = set_bit;   

	show_info(value, cache_memory_tag_line+1, displacement, current_block, false);
	}
      
    }

    //there is at least one free row in the cache
    else {

	//set valid bit
	cache_memory[free_row_index][valid_bit_column] = set_bit;
      
	//set tag
	cache_memory[free_row_index][tag_column] = typed_address;

	//copying values to cache memory
	copy_block_to_cache(free_row_index, index);
      
	//increment count LFU
	cache_memory_increment_lfu(free_row_index); 

	//getting the value
	bitset<bit_qnt> value = main_memory_get_value(typed_address);
      
	show_info(value, cache_memory_tag_line+1, displacement, current_block, false);
    }
    miss_read++;
	}
	update_info();
*/
}
