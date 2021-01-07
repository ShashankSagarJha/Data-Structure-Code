#include <iostream>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
void traverse();
struct Node * getNode(int);
void insert_node(int,int *);
void insert_at(int,int,int *);
void delete_at(int,int*);
void traverse_recursive(struct Node *);
void reverse_list_recursive(struct Node * ,struct Node * );
void reverse_list_iterative(struct Node * );
struct Node * head;
using namespace std;
int a=10;
int main()
{
    int n,data,len=0;
    cout<< "Please enter size:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"please enter value:";
        cin>>data;
        insert_node(data,&len);
        traverse();
        cout<<endl;
    }
    cout<<"size="<<len<<endl;
    int pos,info;
    cout<<"Please enter position:";
    cin>>pos;
    cout<<"Please enter info:";
    cin>>info;
    insert_at(info,pos,&len);
    cout<<"List after insertion:";
    traverse();
    cout<<"reverse traversal:";
    traverse_recursive(head);
    cout<<endl<<"Please enter position to delete:";
    cin>>pos;
    delete_at(pos,&len);
    cout<<endl<<"List after deletion:";
    traverse();
    reverse_list_iterative(head);
    cout<<endl<<"List after reverse:";
    traverse();
    cout<<endl<<"New Size:"<<len;
    return 0;
}
void reverse_list_recursive(struct Node * prev,struct Node * curr){
    if (prev==NULL){
        reverse_list_recursive(curr,curr->next);
        curr->next=NULL;
    }
    else if (curr==NULL){
        prev->prev=NULL;
        head=prev;
    }
    else{
      reverse_list_recursive(curr,curr->next);
      prev->prev=curr;
      curr->next=prev;
    }
}
void reverse_list_iterative(struct Node * head_ptr){
    Node * curr=head_ptr;
    Node *new_curr;
    while(curr){
        new_curr=curr->prev;
        curr->prev=curr->next;
        curr->next=new_curr;
        curr=curr->prev;
    }
    head=new_curr->prev;

}
void delete_at(int pos,int *len){
    if(pos<1 || pos > (*len)){
        cout<<"Invalid Input"<<endl;return;
    }
    Node * temp;
    Node * curr=head;
    if(pos==1){
        temp=head;
        head=temp->next;
        head->prev=NULL;
        delete(temp);
    }
    else if(pos==(*len)){
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=NULL;
        delete(temp);
    }
    else {
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=temp->next;
        temp->next->prev=curr;
        delete(temp);
    }
    (*len)--;
}

struct Node * getNode(int data){
    Node *node=new Node();
    node->prev=NULL;
    node->next=NULL;
    node->data=data;
    return node;
};

void insert_node(int data,int *len){
    struct Node *node=getNode(data);
    if (head==NULL){
        head=node;
    }
    else{
        struct Node *curr=head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=node;
        node->prev=curr;
    }
    (*len)++;
}
void traverse(){
    Node * curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
void traverse_recursive(struct Node * curr){
    if(!curr)return;
    traverse_recursive(curr->next);
    cout<<curr->data<<" ";
}
void insert_at(int data,int pos,int *len){
    if(pos<1 || pos > (*len)+1){
        cout<<"Invalid Input"<<endl;return;
    }
    Node *new_node=getNode(data);
    if(pos==1){
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
    else if(pos==(*len)+1){
        Node * curr=head;
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        curr->next=new_node;
        new_node->prev=curr;
    }
    else{
        Node * curr=head;
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        new_node->next=curr->next;
        new_node->prev=curr;
        curr->next->prev=new_node;
        curr->next=new_node;
    }
    (*len)++;
}
