#include<bits/stdc++.h>
using namespace std ;

void Swap(int &x , int & y)
{
    int temp = x ; 
    x = y ;
    y = temp ;
}
void heapify(int arr[] , int size , int index)
{
    int left = index * 2 + 1 ;
    int right = index * 2 + 2 ;
    int maxI = index ; 
    if(left < size && arr[left] < arr[maxI]) maxI = left ;
    if(right < size && arr[right] < arr[maxI]) maxI = right ;
    if(maxI != index) 
    {
        Swap(arr[maxI],arr[index]);
        heapify(arr , size , maxI );
    }
}


void buildHeap(int arr[] , int size)
{
    for(int i = size / 2 - 1 ; i >= 0 ; i--)
        heapify(arr , size , i) ;
}

void heapSort(int arr[] , int size)
{
    buildHeap(arr , size) ;
    for(int i = size - 1 ; i >= 0 ; i--)
    {
        Swap(arr[0] , arr[i]);
        heapify(arr , i , 0) ;
    }
}

int main()
{
    int arr[] {50,40,90,80,70,20,60} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    heapSort(arr , size) ;
    for(int&x : arr)
    {
        cout << x << " " ;
    }
}