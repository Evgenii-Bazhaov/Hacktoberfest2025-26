#include<stdio.h>
void show(int arr[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[q+1+j];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;

    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
        
    }
}
void mergesort(int arr[],int p, int r){
    if(p<r){
        int q=p+((r-p)/2);
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
void main(){
    int n;
    printf("enter size:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nentered array is :");
    show(arr,n);
    mergesort(arr,0,n-1);
    printf("\nsorted array is :");
    show(arr,n);
}