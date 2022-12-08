#include<iostream>
using namespace std;

// algoritmos de ordenação

void booblesort(int A[],int l,int r){
    for(int i=l;i<r;i++){
        for(int j=r;j>i;j--){
            if(A[j]<A[j-1]){
                int aux=A[j];
                A[j]=A[j-1];
                A[j-1]=aux;
            }
        }
    }
}

void booblesort_v2(int A[],int l,int r){
    bool trade = true;
    for(int i = l; i < r && trade; i++){
        for(int j = r; j > i; j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                trade = true;
            }
        }
    }
}

void insertionsort(int A[],int l,int r){
    for(int i=l+1;i<=r;i++){
        int key = A[i];
        int j = i-1;
        while(j>=l && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

void selectionsort(int A[],int l,int r){
    for(int i=l;i<r;i++){
        int min=i;
        for(int j=i+1;j<=r;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        int aux=A[i];
        A[i]=A[min];
        A[min]=aux;
    }
}