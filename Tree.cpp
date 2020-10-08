#include <iostream>
#include <string.h>

using namespace std;

typedef struct tree{
    int data;
    tree* left;
    tree* right;
    tree* parent;
}Tree;

void Push(Tree* tree, int value)
{
    Tree* newNode = new Tree();
    Tree* temp = tree;
    
    newNode->data = value;
    
    while(true)
    {
        if(temp->data >= value)
        {
            if(temp->left == nullptr)
            {
                temp->left = newNode;
                newNode->parent = temp;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right == nullptr)
            {
                temp->right = newNode;
                newNode->parent = temp;
                break;
            }
            else
                temp = temp->right;
        }
    }
}

void Print(Tree* tree)
{
    Tree* temp = tree;
    
    cout<<temp->data<<endl;
    
    if(temp->left != nullptr)
        Print(temp->left);
    
    if(temp->right != nullptr)
        Print(temp->right);
}

bool Search(Tree* tree, int value)
{
    Tree* temp = tree;
    
    if(temp->data==value)
        return true;
    
    if(temp->left != nullptr)
    {
        if(Search(temp->left, value))
            return true;
    }
    
    if(temp->right != nullptr)
    {
        if(Search(temp->right, value))
            return true;
    }
    
    return false;
}

int main()
{
    Tree* nodeTree = new Tree();
    nodeTree->data = 6;
    
    Push(nodeTree, 2);
    Push(nodeTree, 4);
    Push(nodeTree, 8);
    Push(nodeTree, 9);
    Push(nodeTree, 10);
    Push(nodeTree, 3);
    Push(nodeTree, 8);
    Push(nodeTree, 1);
   
    Print(nodeTree);
    cout << (Search(nodeTree, 4) ? "FIND" : "NULL") << endl; 

   return 0;
}