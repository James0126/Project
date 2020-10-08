#include <iostream>
#include <string.h>

using namespace std;


typedef struct Custom{
    Custom* next_ptr;
    Custom* prev_ptr;
    char c;
}test;

void Push(test* t, char value)
{
    test* t2 = new Custom();

    t2->c = value;
    
    test* temp;
    temp = t->prev_ptr;
    
    if(temp==nullptr)
    {
        t2->next_ptr=t;
        t->prev_ptr = t2;
        return;
    }
    
    while(true)
    {
        if(temp->prev_ptr == nullptr)
        {
            t2->next_ptr = temp;
            temp->prev_ptr = t2;
            break;
        }
        else
        {
            temp = temp->prev_ptr;
        }
    }

}

void Pop(test* t)
{
    test* temp;
    temp = t->prev_ptr;
    
    // while(true) ----> Stack
    // {
    //     if(temp->prev_ptr == nullptr)
    //     {
    //         temp->next_ptr->prev_ptr = nullptr;
    //         delete(temp);
    //         break;
    //     }
    //     else
    //     {
    //         temp = temp->prev_ptr;
    //     }
    // }
    
    t->prev_ptr = temp->prev_ptr; //-----> Queue
    temp->prev_ptr->next_ptr = t;
    
    delete(temp);

}

void Print(test* t)
{
    test* temp;
    
    temp = t->prev_ptr;
    
    while(true)
    {
        if(temp == nullptr)
        {
            break;
        }
        else
        {
            cout<<temp->c;
            temp = temp->prev_ptr;
        }
    }
}


int main()
{
    test* stack = new test();
    
    
    Push(stack, 'a'); 
    Push(stack, 'b');
    Push(stack, 'c');

    Pop(stack);

    Print(stack);
    delete(stack);

    return 0;
}
