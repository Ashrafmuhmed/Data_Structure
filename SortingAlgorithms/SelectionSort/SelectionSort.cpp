#include<bits/stdc++.h>
using namespace std ;
void selectionAscSort(int arr[] , int n)
{
    int minIndex , tempmin ;
    for(int i = 0 ; i < n ; i++)
    {
        minIndex = i ;
        for (int j = i; j < n; j++)
        {
            if(arr[j] < arr[minIndex]) minIndex = j ; 
        }
        tempmin = arr[minIndex] ;
        arr[minIndex] = arr[i] ;
        arr[i] = tempmin ;
    }
}

void selectionDescSort(int arr[] , int n)
{
    int maxIndex , tempmax ;
    for(int i = 0 ; i < n ; i++)
    {
        maxIndex = i ;
        for (int j = i; j < n; j++)
        {
            if(arr[j] > arr[maxIndex]) maxIndex = j ; 
        }
        tempmax = arr[maxIndex] ;
        arr[maxIndex] = arr[i] ;
        arr[i] = tempmax ;
    }
}
int main()
{
    int arr[] = {60,40,50,30,10,20} ;
    selectionAscSort(arr,6);
    cout << "The array after sorting it ascendingly : " ;
    for(int &x : arr)
    {
        cout << x <<" " ;
    }
    cout << endl ;
    selectionDescSort(arr,6);
    cout << "The array after sorting it Descendingly : " ;
    for(int &x : arr)
    {
        cout << x <<" " ;
    }
    cout << endl ;
}