#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
int main()
{
    printf("---------------using pointer arithmetic below-------------\n");
    int *p=malloc(10*sizeof(int));
    for (int i=0;i<10;i++){
            *(p+i)=i;
            printf("%d ",*(p+i));
    }
    printf("\n---------------using array below-------------\n");

    int *ptr=malloc(10*sizeof(int));
    for (int i=0;i<10;i++){
            ptr[i]=i;
            printf("%d ",ptr[i]);
    }
    printf("\n---------------Structure operation below-------------");
    struct node *ps=malloc(10*sizeof(struct node));

    (*ps).data=11;//filling data using pointer arithmetic
    printf("\nPrinting data using arrow operator: %d",ps->data);//using arrow operator
    return 0;
}