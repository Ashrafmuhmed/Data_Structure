#include<bits/stdc++.h>
using namespace std ;

int linearSearch(int arr[] , int size , int key)
{
    for(int i = 0 ; i < size ; i++)
        if(arr[i] == key) return i ;
    return -1 ;
}

int binarySearch(int arr[] , int i , int j , int key)
{
    int m ;
    while( i <= j)
    {
        m =( i+j ) / 2 ;

        if(arr[m] == key) return m ;
        else if(arr[m] > key) j = m - 1 ;
        else i = m + 1 ; 
    }
    return -1 ;
}

int main()
{
    int arr[] = {2,4,5,9,51,98,102,201};
    int size = sizeof(arr) / sizeof(arr[0]) ; 
    cout  << linearSearch(arr,size,98) <<"\n" ;
    cout  << binarySearch(arr,0,size-1,98) ;
    

}