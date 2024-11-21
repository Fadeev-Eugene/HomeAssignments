//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of main code for assignment 5.

#include <iostream>
#include <vector>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"


int main() {
    std::cout << "Direct method calls:" << std::endl;
    Transformer transformer;
    transformer.transform();
    transformer.openFire();
    transformer.ulta();
    
    Autobot autobot;
    autobot.transform();
    autobot.openFire();
    autobot.ulta();

    Decepticon decepticon;
    decepticon.transform();
    decepticon.openFire();
    decepticon.ulta();



    std::cout << "\nMethod calls through base class pointers:" << std::endl;
    Transformer* t1 = &autobot;
    Transformer* t2 = &decepticon;

    t1->transform();
    t2->openFire();

    std::cout << "\nVirtual method calls through a vector:" << std::endl;
    
    std::vector<Transformer*> transformers;
    for (int i = 0; i < 3; ++i) {
        transformers.push_back(new Transformer());
        transformers.push_back(new Autobot());
        transformers.push_back(new Decepticon());
    }
    
    for (Transformer* transformer : transformers) {
        transformer->transform();
        transformer->openFire();
        transformer->ulta();
    }
    
    for (Transformer* transformer : transformers) {
        delete transformer;
    }

    return 0;
}
