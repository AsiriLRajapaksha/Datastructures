#include <stdio.h>
#include <stdlib.h>
int n =0;
int arr[6];
int k;
int main()
{
    AddNumbers();
    printf("You have entered : ");
    Display();
    InsertSort();
    printf("\nNumbers in Ascending oder: ");
    Display();
    int s1 = MaximumSum1();
    int s2 = MaximumSum2();
    printf("The two number with maximum sum are %d and %d \nThe sum is %d",s1 ,s2 , s1+s2);
    return 0;
}

void AddNumbers(){
    int i=0;
    while(i != 6 ){
        printf("Enter number %d [0-9] : ", i+1);
        scanf("%d",&n);
        if(9>n && n>0 ){
            arr[i]=n;
            i++;
        }
    }
}

void Display(){
    for(int j= 0 ; j<6 ; j++){
        printf("%d " , arr[j]);
    }
}

void InsertSort(){
    int j;
    for(int i = 1 ; i<6 ; i++){
        k = arr[i];
        for(j = i - 1 ; j>=0 && k<arr[j] ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = k;
    }
}

int MaximumSum1(){
    int s1 = arr[5]*100 + arr[3]*10 + arr[1];
   return s1;
}

int MaximumSum2(){
    int s2 = arr[4]*100 + arr[2]*10 + arr[0];
   return s2;
}


