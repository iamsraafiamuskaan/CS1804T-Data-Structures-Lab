#include "sort.h"
#include <iostream>
#include<stdio.h>
using namespace std;

void linersearch(int * arr,int size,int target);
void binarysearch(int * arr,int size,int target);

int main(){
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        int ele;
        printf("Enter the element:");
        printf("%d",ele);
        arr[i]=ele;
    }

    int target;
    printf("\nEnter the element to be searched:");
    scanf("%d", target);
    int ch;
    scanf("1.Linear Search\n2.Binary Search\n");
    scanf("Enter your choice:");
    printf("%d",ch);
    switch (ch){
        case 1:
            linersearch(arr,size,target);
            break;
        case 2:
            binarysearch(arr,size,target);
            break;
    }
}


void linersearch(int * arr,int size,int target){
    int found=0;
    for (int i=0;i<size;i++){
        if (arr[i]==target){
            scanf("\nElement Found at the index:"<< i <<"\n");
            found=1;
        }
    }
    if (found==0){
        scanf("\nElement NotFound\n");
    }
}

void binarysearch(int * arr,int size,int target){
    bubbleSort(arr,size);
    int found=0;
    int l=0,r=size-1;
    while (l<r){
        int m=(l+r)/2;
        if (arr[m]==target){
            scanf("\nElement Found\n");
            found=1;
        }
        if (arr[m]>target){
            r=m-1;
        }
        else {
            l=m+1;
        }
    }
    if (found==0){
        scanf("\nElement NotFound\n");
    }

}