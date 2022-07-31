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

