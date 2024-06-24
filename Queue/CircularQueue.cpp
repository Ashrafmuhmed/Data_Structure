#include<bits/stdc++.h>
using namespace std ;
// --> Creating template to make the stack generic "WORK WITH DIFFERENT DATA TYPES"... 
template <class var>
class CircularQueue{
    //declaring the data members 
    private :
        int count , front , rear , maxSize ;
        var *queue ;
    public :
    // The constructor used for initiallizing the data members and initiallizing the queue size...
        CircularQueue(int size)
        {
            maxSize = size ;
            queue = new var[size] ;
            front = count = 0 , rear = maxSize-1;
        }
    //Method to check if the queue is full...
        bool isFull()
        {
            return count == maxSize ;
        }
    //Method to check if the queue is empty...
        bool isEmpty()
        {
            return !count ;
        }
    //Method to add element to the queue...
        void enqueue(var element)
        {
            if(isFull()) 
            {
                cout << "The queue is FULL ......" <<endl ;
            }
            else{
                rear = (rear+1) % maxSize ;
                count++;
                queue[rear] = element ;
                cout << "The element added ....." <<endl ;}
        }
    //Method used for deleting the front of the queue...
        void dequeue(int&copy)
        {   
            if(isEmpty())
            {
                cout << "The queue is already EMPTY ......" <<endl ;
            }
            else
            {    copy = queue[front] ;
                count -- ;
                front = (front+1)%maxSize ;
                cout << "The TOP element deleted now the top is " << queue[front] <<" ........." <<endl ;}
        }
    //Method to return the front index...
        int frontQueue()
        {
            if(isEmpty())
            { 
                cout << "The queue is EMPTY ......" <<endl;
                return -1 ;}
            else
            {
                return queue[front] ;
            }         
        }
    //Method that used for displaying the queue content 
        void printQueue()
        {
            if(isEmpty()) cout << "The queue is EMPTY......" <<endl ;
            else 
            {
                for(int i = front ; i != rear ; i=(i+1)%maxSize)
                {
                    cout << queue[i] <<"  " ;
                }
                cout << queue[rear] <<endl ;
            }
        }
    //Method used for searching for specific element....
        int searchQueue(var element)
        {
            int pos = -1 ;
            if(!isEmpty())
            {
                for(int i = front ; i!=rear ; i=(i+1)%maxSize)
                {
                    if(element==queue[i])
                    {
                        pos = i ;
                        break;
                    }
                }
            } 
            else {cout << "Q is empty ...." <<endl ;}
            return pos ;
        }
};

int main()
{
    int x ;
    CircularQueue<int>C1(5);
    C1.enqueue(85);
    C1.enqueue(65);
    C1.enqueue(71);
    C1.enqueue(93);
    C1.enqueue(81);
    C1.enqueue(-23);
    C1.enqueue(80);
    C1.dequeue(x);
    cout << C1.searchQueue(71) <<endl ;
    C1.printQueue();
    C1.dequeue(x);
    C1.enqueue(-23);
    C1.printQueue();
}