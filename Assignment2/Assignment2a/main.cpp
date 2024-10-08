#include <iostream>
#include <filesystem>
#include <fstream>



int main()
{
	std::ifstream infile;
	infile.open("input.bin", std::ios::binary|std::ios::in);
	
	int filesize = std::filesystem::file_size("input.bin") - 1;
	
	char* buffer = new char[filesize];
	
	infile.read((char*)buffer, filesize);
	
	infile.close();
	
	
	for (int i = 0; i < (filesize / 2); ++i){
		std::swap(buffer[i], buffer[filesize - i - 1]);
	}
	
	
	std::ofstream outfile;
	outfile.open("output.bin", std::ios::binary | std::ios::out);
	
	outfile.write((char*)buffer, filesize);
	
	outfile.close();
	
	delete[] buffer;
	
	return 0;
}
