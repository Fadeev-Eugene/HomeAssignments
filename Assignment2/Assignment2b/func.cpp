void add(int*& stack, int& size, int n){
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



