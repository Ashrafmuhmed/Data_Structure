#include<bits/stdc++.h>
using namespace std ;
// --> Creating template to make the stack generic "WORK WITH DIFFERENT DATA TYPES"... 
template<class var>
class stack
{
    //creating node to store the value of the node and the POINTER that points to the following node in the stuck
    /*

            -------
            |value|
            -------
               |
               |
               \/
              
    */
    struct node
    {
        var item ;
        node *next;
    };
    node *top,*cur ;
public :
//Constructor to intialize the top --> NULL
    stack() : top(NULL){} 
//METHOD TO ADD NEW ELEMENT..
    void push(var newItem)
    {
        node *newItemPtr = new node; // create the node 
        newItemPtr->item = newItem ; // alocate the value 
        newItemPtr->next = top ;     // point the node to the next node to close the chain
        top = newItemPtr ;           // moving the top pointer to the last added node  
    }
//METHOD TO CHECK IF THE STACK EMPTY ?
    bool isEmpty()
    {
        return top == NULL ;
    }
//METHOD TO REMOVE THE TOP NODE ...
    void pop()
    {
        if(!isEmpty())
        {
            node *temp = top ;
            top = top->next ;
            temp = temp->next = NULL ;
            delete temp ;
        }
        else cout << "Empty" ;
    }
    void pop(var &stacktop)
    {
        if(!isEmpty())
        {
            stacktop = top->item;
            node *temp = top ;
            top = top->next ;
            temp = temp->next = NULL ;
            delete temp ;
        }
        else cout << "Empty" ;
    }
//METHOD TO PRINT THE VALUE STORED IN THE TOP NODE ....
    void getTop(var &stacktop)
    {
        if(!isEmpty())
        {
            stacktop = top->item;
        }
        else cout << "Empty" ;
    }
//METHOD TO DIPLAY THE STACK CONTENT..
    void display()
    {
        cur = top ;
        while(cur!=NULL)
        {
            cout << cur->item << " " ;
            cur = cur->next ;
        }
    }
};





int main()
{
    int x = 0 ;
    stack <int> s ;
    s.push(100);
    s.push(250);
    s.push(156);
    s.pop();
    s.push(198);
    s.display();
    s.getTop(x);
    cout << x ;
}