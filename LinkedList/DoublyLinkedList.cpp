#include<bits/stdc++.h>
using namespace std ; 
template<class var>
class DoublyList
{
    private : 
        struct Node
        {
            var item ;
            Node *next , *prev ;
        };
        Node * head , *tail ;
        unsigned int length ;
    public :
        DoublyList() :
        head(NULL) , tail(NULL) , length(0) {}

        bool isEmpty() {return length == 0 ;}

        void insertFront(var item)
        {
            Node *newNode = new Node ;
            newNode -> item = item ; 
            if(isEmpty())
            {
                head = tail = newNode ;
                newNode -> next = newNode->prev = NULL ;
            }
            else
            {
                newNode -> next = head ;
                newNode -> prev = NULL ;
                head ->prev = newNode ;
                head = newNode ;
            }
            length++;
            cout << "The element is added in the front of the list ........!\n" ; 
        }

        void insertEnd(var item)
        {
            Node *newNode = new Node ;
            newNode -> item = item ; 
            if(isEmpty())
            {
                head = tail = newNode ;
                newNode -> next = newNode->prev = NULL ;
            }
            else
            {
                newNode -> next = NULL ;
                newNode -> prev = tail ;
                tail -> next = newNode ;
                tail = newNode ;
            }
            length++;
            cout << "The element is added in the end of the list ........!\n" ; 
        }

        void insertAt(var item , int pos)
        {
            if(pos < 0 || pos > length) {cout << "The position is invalid .......!\n" ; return ;}
            if(pos == 0) {insertFront(item) ; return ;}
            if(pos == length) {insertEnd(item) ; return ;}
            Node *prev = NULL , *cur = head , *newNode = new Node ;
            newNode -> item = item ;
            for(int i = 1 ; i <= pos ; i++)
            {
                prev = cur ;
                cur = cur -> next ;
            }
            prev -> next = newNode ;
            newNode -> prev = prev ;
            newNode -> next = cur ;
            cur -> prev = newNode ;
            length ++ ;
            cout << "Element added at index " <<pos <<endl ;
        }

        void deleteFront()
        {
            if(!isEmpty())
            {
                Node *cur = head ;
                head = head -> next ;
                head -> prev = NULL ;
                delete cur ;
                length--;
                cout << "Front element is deleted.......!\n" ; 
            }
            else
            {
                cout << "The list is already empty......!\n" ;
            }
        }

        void deleteEnd()
        {
            if(!isEmpty())
            {
                Node *cur = tail ;
                tail = tail -> prev ;
                tail -> next = NULL ;
                length--;
                cout << "End element is deleted.......!\n" ; 
                delete cur ;}
            else 
            {
                cout << "The list is already empty......!\n" ;
            }
        }

        void deleteAt(int index)
        {
            if(index < 0 || index > length) {cout << "The position is invalid .......!\n" ; return ;}
            if(index == 0) {deleteFront() ; return ;}
            if(index == length) {deleteEnd() ; return ;}
            Node *cur = head ;
            for(int i = 0 ; i < index ; i ++)
            {
                cur = cur -> next ;
            }
            cur -> prev -> next = cur -> next ;
            cur -> next -> prev = cur -> prev ;
            length--;
            cout << "Element is deleted.......!\n" ;
        }

        void deleteItem(var item)
        {
            Node *cur = head ;
            while(cur != NULL)
            {
                if(cur -> item == item)
                {
                    cur -> prev -> next = cur -> next ;
                    cur -> next -> prev = cur -> prev ;
                    delete cur ;
                    length --;
                    cout << "Element is deleted ......!\n" ;
                    return;
                }
                cur = cur -> next ;
            }
            cout << "Not found element......!\n" ;
        }

        int search(var item)
        {
            Node *cur = head ;
            int index = 0 ;
            while(cur != NULL)
            {
                if(cur -> item == item)
                {
                    return index ;
                }
                index++;
                cur = cur -> next ;
            }
            return-1;
            cout << "Not found element......!\n" ;
        }



        void display()
        {
            Node *cur = head ;
            cout << "The list : " ;
            while(cur != NULL)
            {cout << cur -> item <<"  " ; cur = cur -> next ;}
            cout << endl << "The length is " <<length <<" \n" ;
        }

        void displayR()
        {
            Node *cur = tail ;
            cout << "The list : " ;
            while(cur != NULL)
            {cout << cur -> item <<"  " ; cur = cur -> prev ;}
            cout << endl << "The length is " <<length <<" \n" ;
        }
        
};

int main()
{
    DoublyList<int>l ;
    l.deleteFront();
    l.insertFront(54) ;
    l.insertEnd(69);
    l.insertAt(220,1);
    l.insertFront(96) ;
    l.insertFront(563) ;
    l.display();
    l.displayR();
    cout << "220 index is " <<l.search(220) <<endl ;
    cout << l.search(-96) <<endl;
    l.deleteItem(220);
    l.insertFront(96) ;
    l.display();

}