#include <iostream>
#include <sstream>
#include <string>
#include "func.hpp"


int main(){
    int size = 0;    
    int* stack = new int[size];
    
    int app1, app2;
    
    std::string line;
    std::getline(std::cin, line);
    
    std::istringstream words(line);
    std::string word;
    
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
    }
    std::cout << stack[0] << std::endl;
    delete[] stack;
    return 0; 
}
