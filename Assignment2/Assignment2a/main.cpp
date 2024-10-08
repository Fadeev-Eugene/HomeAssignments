//Fadeev Eugene st128225@student.spbu.ru
//This is main code for assignment 2a.


//Include needed libs
#include <iostream>
#include <filesystem>
#include <fstream>



int main()
{
    //open "input.bin" file
    std::ifstream infile;
    infile.open("input.bin", std::ios::binary|std::ios::in);

    //get file size (i use -1 to get rid of new line symbol at the end of file. It fixes bug when output file starts with empty line)
    int filesize = std::filesystem::file_size("input.bin") - 1;

    //allocation memory for buffer
    char* buffer = new char[filesize];

    //read file to buffer
    infile.read((char*)buffer, filesize);
    
    //close "input.bin" file
    infile.close();

    //reverse data in buffer
    for (int i = 0; i < (filesize / 2); ++i){
        std::swap(buffer[i], buffer[filesize - i - 1]);
    }

    //open "output.bin" file
    std::ofstream outfile;
    outfile.open("output.bin", std::ios::binary | std::ios::out);
    
    //write data from buffer to file
    outfile.write((char*)buffer, filesize);

    //close "output.bin" file
    outfile.close();

    //free memory
    delete[] buffer;

    //end of code
    return 0;
}
