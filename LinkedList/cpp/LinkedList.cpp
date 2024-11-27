#include<bits/stdc++.h>
using namespace std ;
template <class var>
class Linkedlist{
    private :
    struct Node
    {
        var item ;
        Node *next ;
    };
    Node *head , *tail ;
    int length ;
    public :
    Linkedlist() :
    head(NULL),tail(NULL),length(0){}

    bool isEmpty() {return length == 0 ;}

    void insertFront(var item)
    {
        Node *newNode = new Node ;
        newNode->item = item ;
        if(isEmpty())
        {
            newNode->next = NULL ;
            head=tail=newNode ;
        }
        else
        {
            newNode->next = head ;
            head = newNode ;
        }
        length ++ ;
        cout << "Element added in the front of the list.....!\n" ;
    }

    void insertEnd(var item)
    {
        Node *newNode = new Node ;
        newNode->item = item ;
        if(isEmpty())
        {
            newNode->next = NULL ;
            head=tail=newNode ;
        }
        else
        {
            tail->next = newNode ;
            tail = newNode ;
            newNode->next=NULL;
        }
        length ++ ;
        cout << "Element added in the end of the list.....!\n" ;
    }

    void insertAt(int index , var item)
    {
        if(index < 0 || index > length) 
        {
            cout << "Invalid Position....!\n" ;
            return;
        }  
        if(index == 0){ insertFront(item) ; return;}
        else if(index == length) {insertEnd(item) ; return;}
        else{
            Node *cur = head , *newNode = new Node ;
            newNode->item=item ;
            for(int i = 1 ; i < index ; i++) cur = cur -> next ;
            newNode->next= cur->next ;
            cur->next = newNode ;
            length++;
            cout<<"The element added at index " <<index <<" ......!\n" ;
        }
    }

    void deleteHead()
    {
        if(isEmpty()){ cout << "List is already empty......!\n" ; return ;}
        else if(length == 1)
        {
            delete head ;
            head = tail = NULL ;
        }
        else 
        {
            Node *cur = head ;
            head = head -> next ;
            delete cur ;
        }
        length--;
        cout << "Front element is deleted .....!\n" ; 
    }

    void deleteTail()
    {
        if(isEmpty()){ cout << "List is already empty......!\n" ; return ;}
        else if(length == 1)
        {
            delete head ;
            head = tail = NULL ;
        }
        else 
        {
            Node *cur = tail , *prev = head ;
            for(int i = 1 ; i < length-1 ; i++) prev = prev->next ;
            prev->next = NULL ;
            delete cur ;
        }
        length--;
        cout << "Back element is deleted .....!\n" ; 
    }

    void deleteEle(var element)
    {
        if(isEmpty()) { cout << "List is already empty......!\n" ; return ;}
        else if( head->item == element) {deleteHead() ; return ;}
        else if( tail->item == element) {deleteTail() ; return ;}
        else 
        {
            Node *prev = NULL , *cur = head ;
            while(cur != NULL)
            {
                if(cur->item == element) break;
                prev = cur ;
                cur = cur -> next ;
            } 
            if(cur == NULL) cout << "The list doesnt contain this element.........!\n" ;
            else
            {
                prev->next = cur->next ;
                delete cur ; 
                length -- ;
                cout << "Element deleted from the list ......!\n" ;
            }        
        }
    }


    void deleteAtIndex(int index)
    {
        if(index < 0 || index > length) 
        {
            cout << "Invalid Position....!\n" ;
            return;
        }  
        if(index == 0){ deleteHead() ; return;}
        else if(index == length) {deleteTail() ; return;}
        else{
            Node *prev = NULL , *cur = head ;
            for(int i = 1 ; i <= index ; i++)
            {
                prev = cur ; cur = cur -> next ;
            }
            prev -> next = cur -> next ;
            delete cur ;
            length--;
            cout << "Element deleted from the list ......!\n" ;
        }
    }

    int search(var item)
    {
        if(!isEmpty())
        {
            Node *cur = head ; int index = 0 ;
            while(cur!=NULL && cur->item!=item)
            {
                cur = cur -> next ;
                index++;
            }
            if(cur!=NULL) return index ;
        }
        return -1 ;
    }

    void reverseList()
    {
        if(isEmpty()) { cout << "List is already empty......!\n" ; return ;}
        Node *prev = NULL ,*cur = head , *nextt = head -> next  ;
        while(cur != NULL)
        {
            nextt = cur -> next ;
            cur->next = prev ;
            prev = cur ;
            cur = nextt ;
            head = prev ;
        }
        cout << "LIST IS REVERSED.......!\n" ;
        display() ;
    }

    void display()
    {
        cout << "Your linked list is : ";
        Node *cur = head ;
        while(cur != NULL)
        {
            cout << cur->item <<" " ;
            cur = cur -> next ;
        }
        cout << endl << "length = " << length ;
        cout <<endl ;
    }


    
};


int main()
{
    Linkedlist<int>l1 ;
    l1.insertFront(58);
    l1.insertFront(95);
    l1.insertFront(00);
    l1.insertEnd(29);
    l1.insertAt(2,69);
    cout << "FOUND AT " <<l1.search(69) <<endl ;
    l1.display();
    l1.deleteAtIndex(2);
    l1.deleteHead();
    l1.display();
    l1.deleteTail();
    l1.display();
    l1.deleteEle(69) ;
    l1.deleteEle(99) ;
    l1.display();
    l1.deleteAtIndex(0);
    l1.deleteAtIndex(34);
    l1.display();
    l1.insertFront(95);
    l1.insertFront(00);
    l1.insertEnd(29);
    l1.insertAt(2,69);
    l1.display();
    l1.reverseList();
}