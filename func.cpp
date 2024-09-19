#include <iostream>


void func(){
	std::string a;
	std::cout << "Hello, world!\n";
	std::cin >> a;
	while (a != "stop")
	{
		std::cout << "Hello, " << a << "!\n";
		std::cin >> a;
	}

}
