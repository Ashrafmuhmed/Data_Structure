#include<bits/stdc++.h>
using namespace std ;
void bubbleAsce(int arr[] , int n)
{
    bool isSorted ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        isSorted = true ;
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                isSorted = false ;
                swap(arr[j] , arr[j+1]);
            }
        }
        if(isSorted) break;
    }
}

void bubbleDesce(int arr[] , int n)
{
    bool isSorted ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        isSorted = true ;
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(arr[j]<arr[j+1])
            {
                isSorted = false ;
                swap(arr[j] , arr[j+1]);
            }
        }
        if(isSorted)
         break;
    }
}
void swap(int&x,int&y)
{
    int temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

int main()
{
    int arr[] = {60,50,40,30} ;
    bubbleAsce(arr,4);
    cout << "The array after sorting it ascendingly : " ;
    for(int &x : arr)
    {
        cout << x <<" " ;
    }
    cout << endl ;
    bubbleDesce(arr,4);
    cout << "The array after sorting it Descendingly : " ;
    for(int &x : arr)
    {
        cout << x <<" " ;
    }
    cout << endl ;
}