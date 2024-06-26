#include<bits/stdc++.h>
using namespace std ;
template<class var>
class ArrayStructure
{
    private :
        int *arr , maxSize , length ;
    public :
        ArrayStructure(int size)
        {
            if(size < 0)
            {
                cout << "Invalid Size , size is 10 now" <<EADDRNOTAVAIL;
                maxSize = 10 ;
                arr = new var[maxSize] ;}
            else 
            {
                maxSize = size ;
                arr = new var[maxSize] ;
                cout << "Array created with size "<<maxSize <<endl ;
            }
                length = 0 ;
        }
        bool isFull()
        {
            return length == maxSize ;
        }

        bool isEmpty()
        {
            return length == 0 ;
        }
    // 0  1  2 3 4  length = 4 
    // el 10 50 6 8         arr[4] = arr[3] + arr[3] = arr[2] + .....
        void addAt(int pos , var ele)
        {
            if(isFull()) cout << "The array is full can't add the element "<<endl ;
            else if(pos < 0 || pos > length) cout << "Invalid position..." <<endl ;
            else
            {
                for(int i = length ; i > pos ; i--)
                {
                    arr[i] = arr[i-1] ;
                }
                arr[pos] = ele ;
                cout << "The element "<< arr[pos] <<" is added at the position "<< pos << endl;
                length++;
            }
        }

        void addAtEnd(var ele)
        {
            if(isFull()) cout << "The array is already full..." <<endl ;
            else 
            {
                arr[length] = ele ;
                length ++ ; 
            }
        }

        void removeAt(int pos)
        {
            if(isEmpty()) cout << "The array is already empty....." <<endl ;
            else if(pos < 0 || pos >= length) 
            {
                cout << "Invalid Index...." <<endl ;
            }
            // 0   1  2  3  4
            // 25 69 35 14 25  arr[0] = arr[1] + arr[1] = arr[2] + .....
            else 
            {
                for(int i = pos ; i < length ; i++)
                arr[i] = arr[i+1] ;
                length--; 
            }
        }

        int search(var ele)
        {
            for(int i = 0 ; i < length ; i++)
            {
                if(arr[i] == ele) return i ;
            }
            return -1 ;
        }

        void insertNoDuplicate(var ele)
        {
            if(search(ele) == -1) addAtEnd(ele) ;
            else cout << "The element exist in the array at position " << search(ele) <<endl;
        }

        void updateAt(int idex , var ele)
        {
            if(isEmpty()) cout << "The array is already empty ...... " <<endl ;
            else if(idex < 0 || idex > length) cout << "Invalid index..." <<endl ;
            else
            {
                arr[idex] = ele ;
                cout << "Element at " <<idex <<" updated to "<<arr[idex] <<endl ;
            }
        }

        var getElement(int pos)
        {
            if(isEmpty()) cout << "The array is already empty ...... " <<endl ;
            else if(pos < 0 || pos > length) cout << "Invalid index..." <<endl ;
            else
            {
                return arr[pos] ;
            }
        }
        void display()
        {
            if(isEmpty()) cout << "The array is empty ....." <<endl ;
            else
            {cout << "The list : [ " ;
            for(int i = 0 ; i < length ; i++)
            {
                cout << arr[i] << " " ;
            }
            cout <<" ]\n" ;}
        }

        ArrayStructure()
        {
            delete[]arr;
        }        

        void clear()
        {length = 0 ;}
};

int main()
{
    ArrayStructure<int>A1(5) ;
    A1.addAt(2 , 258) ;
    A1.addAtEnd(35) ;
    A1.addAtEnd(635) ;
    A1.addAtEnd(-95) ;
    A1.addAtEnd(-95) ;
    A1.addAtEnd(-95) ;
    A1.addAtEnd(-95) ;
    A1.addAtEnd(-95) ;
    A1.display() ;
    A1.addAt(1,-32) ;
    A1.insertNoDuplicate(35) ;
    A1.display() ;
    cout << A1.search(35) <<endl ;
    cout << A1.search(-32) <<endl;
    cout << A1.search(635) <<endl ;
    cout << A1.search(-95) ;
}