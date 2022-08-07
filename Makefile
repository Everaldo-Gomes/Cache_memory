path_bin =  ./bin
compiler_flags = g++ -g -Wall -std=c++17


all: main ram cache init_menu


main: ./src/main.cpp
	${compiler_flags} ./src/main.cpp -o ${path_bin}/main.exe

ram: ./src/RAM/ram.cpp
	${compiler_flags} ./src/RAM/*.cpp -o ${path_bin}/ram.exe

cache: ./src/cache/cache.cpp
	${compiler_flags} ./src/cache/*.cpp -o ${path_bin}/cache.exe

init_menu:
	gnome-terminal -- ${path_bin}/main.exe

init_ram:	
	gnome-terminal -- ${path_bin}/ram.exe

init_cache:	
	gnome-terminal -- ${path_bin}/cache.exe

clean:
	rm -rf ${path_bin}/*.exe

#gnome-terminal -e "bash -c exe_path;bash"