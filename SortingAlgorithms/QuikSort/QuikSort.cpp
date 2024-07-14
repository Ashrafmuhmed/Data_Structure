#include<bits/stdc++.h>
using namespace std ;
 
int partition(int arr[] , int ibegin , int jend)
{
    int i = ibegin ; 
    int j = jend ; 
    int piv = i ;
    while(true)
    {
        while(arr[piv] <= arr[j] && piv != j)
            j-- ;
        if(piv == j) break;
        else if(arr[piv] > arr[j]) {swap(arr[piv] , arr[j] ) ; piv = j ;}

        while(arr[piv] >= arr[i] && piv != i)
            i++;
        if(piv == i) break ;
        else if(arr[piv] < arr[i]){ swap(arr[piv] , arr[i]) ; piv = i ;}
    }
    return piv ;
}

void quikSort(int arr[] , int i , int j)
{
    if( i < j )
    {
        int piv = partition(arr , i , j);
        quikSort(arr , i , piv - 1) ;
        quikSort(arr , piv+1 , j) ;
    }
}

int main()
{
    int arr[] {5486,4884,25,448,10,484} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    quikSort(arr , 0 , size-1);
    for(int &x : arr)
        cout << x << " " ;
}