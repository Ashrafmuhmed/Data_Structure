#include<bits/stdc++.h>
using namespace std ;
template <class var>
//Creating the class
class LinkedQueue{
private :
    struct Node{
        var item ;
        Node *next;
    };
    Node *front = NULL , *rear = NULL ;
public :
    LinkedQueue(){}

    bool isEmpty()
    {
        return front == NULL ;
    }

    void enQueue(var item)
    {
        Node *newPtr = new Node ;
        newPtr->item=item ;
        newPtr->next=NULL ;
        if(this->isEmpty()) front = rear = newPtr ;
        else
        {
            rear->next=newPtr ;
            rear = newPtr ;    
        }
    }

    void deQueue()
    {
        Node *temp = new Node ;
        if(this->isEmpty()) cout << "The queue is already empty...." <<endl;
        else if(rear == front)
        {front = rear = NULL ;
        cout << "The first in element is deleted now the queue is empty ...." <<endl ;}
        else
        {
            temp = front ;
            front = front->next ;
            temp->next=NULL;
            delete temp ;
            cout << "The First in element deleted now the front is " << front->item <<endl ;
        }
    }

    void deQueue(var&copy)
    {
        assert(!this->isEmpty());
        copy = front->item;
        front = front->next ;
    }

    int getFront()
    {
        assert(!this->isEmpty());
        return front->item ;
    }

    int getRear()
    {
        assert(!this->isEmpty());
        return rear->item ;
    }
    void clear()
    {
        if(this->isEmpty()) cout << "The queue is already empty ....." <<endl ;
        else 
        {
            Node *temp ;
            while(front != NULL)
            {
                temp = front ;
                front = front->next ;
                delete temp ;
            }
            rear = NULL ;
            cout << "The queue is cleared ..... " <<endl ;

        }
    }
    void display()
    {
        if(!this->isEmpty())
        {Node *temp = this->front ;
        while(temp != NULL)
        {
            cout << temp->item << " " ;
            temp = temp->next ;
        }
        cout << endl ;}
    }


};

int main()
{
    LinkedQueue<int>l1 ;
    l1.enQueue(54);
    l1.enQueue(64);
    l1.enQueue(94);
    l1.enQueue(524);
    l1.clear() ;
    int x ;
    l1.deQueue(x);
    l1.enQueue(9);
    l1.enQueue(214);
    l1.enQueue(5314);
    l1.enQueue(57);
    l1.display();
}