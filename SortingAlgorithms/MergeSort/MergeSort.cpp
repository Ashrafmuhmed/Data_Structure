#include<bits/stdc++.h>
using namespace std ;

void mergeA(int arr[] , int l , int r , int m)
{
    int i , j , k ;
    int n1 = m - l + 1 ;
    int n2 = r - m ;
    int*L= new int[n1] ;
    int*R= new int[n2] ;

    for( i = 0 ; i < n1 ; i++) L[i] = arr[l + i] ;
    for( i = 0 ; i < n2 ; i++) R[i] = arr[m + 1 + i];

    i = j = 0 ; k = l ;

    while( i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[ k ] = L[ i ] ;
            i++ ; 
        }
        else
        {
            arr[ k ] = R[ j ] ;
            j++ ; 
        }
        k++;
    }

    while( i < n1 ) 
    {
        arr[ k ] = L[ i ] ;
        k++ ; i++ ;
    }

    while( j < n2 )
    {
        arr[ k ] = R[ j ] ;
        j++ ; k++ ;}
}
void mergeSortA(int arr[] , int l , int r)
{
    if(l < r)
    {
        int m = l + (r-l) / 2 ;
        mergeSortA(arr , l , m ) ;
        mergeSortA(arr , m+1 ,r) ;
        mergeA(arr , l ,  r , m) ;
    }
}
void mergeD(int arr[] , int l , int r , int m)
{
    int i , j , k ;
    int n1 = m - l + 1 ;
    int n2 = r - m ;
    int*L= new int[n1] ;
    int*R= new int[n2] ;

    for( i = 0 ; i < n1 ; i++) L[i] = arr[l + i] ;
    for( i = 0 ; i < n2 ; i++) R[i] = arr[m + 1 + i];

    i = j = 0 ; k = l ;

    while( i < n1 && j < n2)
    {
        if(L[i] >= R[j])
        {
            arr[ k ] = L[ i ] ;
            i++ ; 
        }
        else
        {
            arr[ k ] = R[ j ] ;
            j++ ; 
        }
        k++;
    }

    while( i < n1 ) 
    {
        arr[ k ] = L[ i ] ;
        k++ ; i++ ;
    }

    while( j < n2 )
    {
        arr[ k ] = R[ j ] ;
        j++ ; k++ ;}
}
void mergeSortD(int arr[] , int l , int r)
{
    if(l < r)
    {
        int m = l + (r-l) / 2 ;
        mergeSortD(arr , l , m ) ;
        mergeSortD(arr , m+1 ,r) ;
        mergeD(arr , l ,  r , m) ;
    }
}


void printA(int*x , int n)
{
    for(int i = 0 ; i < n ; i++ )
        cout << x[i] << " " ;
    cout << endl ;
}


int main()
{
    int s ;
    cin >> s ;
    int *arr = new int[s] ;
    for(int i = 0 ; i < s ; i++)
        cin >> arr[i] ;
    cout << "The elements you entered : " ;
    printA(arr , s);
    mergeSortA(arr , 0 , s-1) ;
    cout << "After sorting the array ascendingly : " ;
    printA(arr , s);
    mergeSortD(arr , 0 , s-1) ;
    cout << "After sorting the array descendingly : " ;
    printA(arr , s);
 
}