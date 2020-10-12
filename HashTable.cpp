#include <iostream>
#include <vector>

using namespace std;

typedef struct hash{
    int data = 0;
    hash* next = nullptr;
}Hash;

typedef struct table{
    Hash* hashData = nullptr;
}Table;

void Push(Table table[], int size, int value)
{
    if(table[value%size].hashData == nullptr)
    {   
        table[value%size].hashData = new Hash();
        table[value%size].hashData->data = value;
    }
    else
    {
        Hash* newData = new Hash();
        newData->data = value;
        
        Hash* temp = table[value%size].hashData;
        
        table[value%size].hashData = newData;
        newData->next = temp;
    }
}

void Print(Table table[], int size)
{
    Hash* temp;
    for(int i = 0; i < size; i++)
    {
        cout<<i<<" ";
        if(table[i].hashData == nullptr)
        {
            cout<<endl;
            continue;
        }
        
        else
        {
            temp = table[i].hashData;
            while(true)
            {
                cout<<temp->data;
                temp = temp->next;
                
                if(temp == nullptr)
                    break;
                else
                    cout<<" -> ";
            }
            cout<<endl;  
        }
    }
}

void Delete(Table table[], int size, int value)
{
    for(int i = 0; i < size; i++)
    {
        if(table[i].hashData == nullptr) continue;
        
        if(table[i].hashData->data == value)
        {
            delete(table[i].hashData);
            table[i].hashData = nullptr;
            return;
        }
        
        Hash* temp = table[i].hashData->next;
        Hash* prev = table[i].hashData;
        
        while(true)
        {
            if(temp == nullptr) break;
            
            if(temp->data == value)
            {
                if(temp->next != nullptr)
                {
                    prev->next = temp->next;
                    delete(temp);
                    return;
                }
                prev = nullptr;
                delete(temp);
                return;
            }
            
            prev = temp;
            temp = temp->next;
            
            if(temp == nullptr) break;
        }
    }
}

int main()
{
    int tableSize = 12;
    Table* table = new Table[tableSize];


    Push(table, tableSize, 34125);
    Push(table, tableSize, 135342);
    Push(table, tableSize, 341);
    Push(table, tableSize, 525);
    Push(table, tableSize, 66324);
    Push(table, tableSize, 586);
    Push(table, tableSize, 988);
    Push(table, tableSize, 5984);
    Push(table, tableSize, 24847);
    Push(table, tableSize, 1673);
    Push(table, tableSize, 4958);
    Push(table, tableSize, 2018);
    Push(table, tableSize, 7777);
    Push(table, tableSize, 25852);
    Push(table, tableSize, 643847);

    
    Delete(table, tableSize, 135342);
    
    Print(table, tableSize);

    return 0;
}
