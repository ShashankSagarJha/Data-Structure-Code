#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node * head=NULL;
struct Node * GetNode(int);
void InsertNode(int);
void printdata();
void delete_pos(int *,int);
void insert_pos(int,int *,int);
void reverse(struct Node *,struct Node *);
void iterative_reverse();
int nth_el_lst(int );
void MiddleNode();
int main()
{
    printf("How many numbers:");
    int size,data;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Please enter value:\n");
        scanf("%d",&data);
        InsertNode(data);
        printdata();
    }
    int data2=60;
    int pos=5;
    insert_pos(data2,&size,pos);
    printdata();
    int data3=70;
    int pos1=2;
    insert_pos(data3,&size,pos1);
    printf("\n list after insertion:\n");
    printdata();
    int posd=-11;
    delete_pos(&size,posd);
    printf("\n list after deletion:\n");
    printdata();
    printf("\n list after recursive reversing:\n");
    reverse(NULL,head);
    printdata();
    printf("\n list after iterative reversing:\n");
    iterative_reverse();
    printdata();
    printf("\nThird element from last is: %d",nth_el_lst(3));
    MiddleNode();
    return 0;
}
struct Node * GetNode(int data){
    struct Node * temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    return temp;
};
void InsertNode(int data){
    struct Node * node=GetNode(data);
    if (head==NULL){
            head=node;
    }
    else{
        struct Node * curr=head;
        while(curr->link){
            curr=curr->link;
        }
        curr->link=node;
    }
}
int nth_el_lst(int n){
    int count=0;
    struct Node *main_ptr=head;
    struct Node *ref_ptr=head;
    while (ref_ptr){
        if(count<n){
            ref_ptr=ref_ptr->link;
            count++;
        }
        else{
            main_ptr=main_ptr->link;
            ref_ptr=ref_ptr->link;
        }
    }
    if (count==n) return main_ptr->data;
    return -1;
}
void MiddleNode(){
    if(head){
    struct Node *slow_ptr=head;
    struct Node *fast_ptr=head;
    while(fast_ptr->link!=NULL && fast_ptr->link->link!= NULL){
            slow_ptr=slow_ptr->link;
            fast_ptr=fast_ptr->link->link;
        }
    printf("\nMiddle node is:%d",slow_ptr->data);
    }
    else{
        printf("Empty List!!");
    }

}
void printdata(){
    struct Node * curr=head;
    while(curr){
        printf("%d ",curr->data);
        curr=curr->link;
    }
    printf("\n");
}
void insert_pos(int data,int *size,int pos){
    if (pos<1 || pos>(*size)+1){
        printf("---------------Invalid position:Can't insert--------------------------");
        return;
    }
    struct Node *temp1=GetNode(data);
    if (pos==1){
        temp1->link=head;
        head=temp1;
        return;
    }
    struct Node *temp2=head;
    for(int i=0;i<pos-2;i++){
        temp2=temp2->link;
    }
    temp1->link=temp2->link;
    temp2->link=temp1;
    (*size)++;
}
void delete_pos(int *size,int pos){
    if (pos<1 || pos>(*size)){
        printf("---------------Invalid position:Can't delete--------------------------");
        return;
    }
    struct Node *temp1;
    if (pos==1){
        temp1=head;
        head=temp1->link;
        free(temp1);
        (*size)--;
        return;
    }
    struct Node *temp2=head;
    for(int i=0;i<pos-2;i++){
        temp2=temp2->link;
    }
    temp1=temp2->link;
    temp2->link=temp1->link;
    free(temp1);
    (*size)--;
}
void reverse(struct Node *prev,struct Node *curr){
    if (curr){
        reverse(curr,curr->link);
        curr->link=prev;
    }
    else{
        head=prev;
    }
}
void iterative_reverse(){
    struct Node * prev;
    struct Node * curr=head;
    struct Node *next;
    while(curr){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

