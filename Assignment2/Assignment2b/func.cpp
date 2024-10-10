//Fadeev Eugene st128225@student.spbu.ru
//This is code which define functions of additing and getting elements from stack for assignment 2b.

void add(int*& stack, int& size, int n){
    //This function implements the operation of adding a new element to the stack by creating new stack
    int* new_stack = new int[size + 1];
    new_stack[0] = n;
    for (int i = 0; i < size; ++i){
        new_stack[i + 1] = stack[i];
    }
    delete[] stack;
    stack = new_stack;
    ++size; 
}


int get(int*& stack, int& size){
    //This function implements the operation of getting the top element from the stack by creating new stack
    int* new_stack = new int[size - 1];
    int r = stack[0];
    for (int i = 1; i < size; ++i){
        new_stack[i - 1] = stack[i];
    }
    delete[] stack;
    stack = new_stack;
    --size; 
    return r;
}



