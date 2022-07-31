#pragma once

#include <bits/stdc++.h>
#include <bitset>


class Cache
{

private:
	
	static const short int bit_qnt = 7;
	const int row_qnt = 8;
	const int column_qnt = 8;

	
public:

	std::vector<std::vector<std::bitset<bit_qnt>>> cache_memory;
	
	Cache();
	void info_header();
	void init();
	
};
