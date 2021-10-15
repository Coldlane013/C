#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int i, size,num,pos;
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("Enter array elements:");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d",&num);
    printf("Enter insert element position:");
    scanf("%d",&pos);
    if(pos > size+1 || pos <=0){

    printf("INVALID POSITION PLEASE ENTER POSITION FROM 1 TO [%d]",size);
    }
    else{
        for(i=size;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1] = num;
        size++;
        printf("Array elements after adding element:");
        for(i=0;i<size;i++){
            printf("%d\t",arr[i]);
        }

    }
    return 0;
}
