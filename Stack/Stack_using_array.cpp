#include<bits/stdc++.h>
using namespace std ;
class StackArray{
    //Data members
    private :
        int top ;
        int* arr ;
        int maxSize ;
    public :
    //Constructor..
        StackArray(int size) : 
            top (-1),
            arr(new int[size]),
            maxSize(size)
        {

        }
    //Method to check if the stack full..
        bool isFull() 
        {
            return top == maxSize-1 ;
        }
    //Method to check if the stack empty..
        bool isEmpty()
        {
            return top == -1 ;
        }
    //Method to add element on the top of the stack..
        void addEle(int x)
        {
            if(!isFull()) 
            {
                top ++ ;
                arr[top] = x ;
                cout << ".....The element is added successfully , now the top is "<<arr[top] <<"...." <<endl;
            }
            else 
            {
                cout << "The stack is full....." <<endl ;
            }
        }
    //Method to remove the element on the top of the stack..
        void removeEle()
        {
            if(isEmpty()) cout << "The stack is already empty....." <<endl ;
            else 
            {
                top -- ;
                cout << "The top element removed......" <<endl ;
            }
        }
    //Overloaded Method to send a copy of the top element then remove the top of the stack..
        void removeEle(int&send)
        {
            if(isEmpty()) cout << "The stack is already empty....." <<endl ;
            else 
            {
                send = arr[top] ;
                top -- ;
                cout << "The top element removed......" <<endl ;
            }
        }
    //Method to get the top of the stack..
        void getTop(int&send)
        {
            if(isEmpty()) cout <<"The stack is empty......." <<endl;
            else 
            {
                send = arr[top] ;
                cout << "The top element is " << send << " , sent ." <<endl ;
            }
        }
    //Method to display the stack content...
        void print()
        {
            int cur = top ;
            cout << "....[ " ;
            for( cur ; cur >= 0 ; cur--)
                cout << arr[cur] <<" " ;
            cout << "]....." ;
        }

};

int main()
{
    StackArray s1{5} ;
    s1.addEle(15) ;
    s1.addEle(18) ;
    s1.addEle(13) ;
    s1.addEle(14) ;
    s1.addEle(14) ;
    s1.addEle(14) ;
    s1.print() ;

}
