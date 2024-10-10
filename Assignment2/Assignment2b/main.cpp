//Fadeev Eugene st128225@student.spbu.ru
//This is main code for assignment 2b.


//Include needed libs
#include <iostream>
#include <sstream>
#include <string>
#include "func.hpp"


int main(){
    //Create stack
    int size = 0;    
    int* stack = new int[size];
    
    //Creare opperands
    int app1, app2;
    
    //Pointer to the top of stack
    int top = stack[0]; 
    
    //Read input line and split it by words
    std::string line;
    std::getline(std::cin, line);
    
    std::istringstream words(line);
    std::string word;
    
    //Start to anylyse words from input line
    while (words >> word) {
        if (word == "+"){
	    app1 = get(stack, size);
	    app2 = get(stack, size);
            add(stack, size, app1 + app2);
        }
        else if (word == "-"){
            app1 = get(stack, size);
            app2 = get(stack, size);
            add(stack, size, app2 - app1);
        }
        else if (word == "*"){
            app1 = get(stack, size);
            app2 = get(stack, size);
            add(stack, size, app1 * app2);
        }
        else if (word == "/"){
            app1 = get(stack, size);
            app2 = get(stack, size);  
            add(stack, size, app2 / app1);  
        }
        else {
            add(stack, size, std::stoi(word));
        }
        //Update pointer
        top = stack[0];
    }
    
    //Print top of the stack
    std::cout << top << std::endl;
    
    //Free memory
    delete[] stack;
    
    return 0; 
}
