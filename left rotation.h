#include <iostream>
struct Node{
    char data;
    struct Node* link;
};
void traverse();
void rotateList(int );
int len();
using namespace std;
Node *head;
int main()
{
    Node * node1=new Node;
    Node * node2=new Node;
    Node * node3=new Node;
    Node * node4=new Node;
    Node * node5=new Node;
    Node * node6=new Node;
    head=node1;
    node1->data='a';
    node1->link=node2;
    node2->data='b';
    node2->link=node3;
    node3->data='c';
    node3->link=node4;
    node4->data='d';
    node4->link=node5;
    node5->data='e';
    node5->link=NULL;
    traverse();
    rotateList(3);
    cout<<"After Shift----->> ";
    traverse();

    return 0;
}
void traverse(){
    Node *curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->link;
    }
    cout<<endl;
}
void rotateList(int N){
    if (N==0 || len()==N) return;
    N=N%len();
    Node *curr=head;
    Node *ref_ptr=NULL;
    int counter=0;
    while(curr->link){
        counter++;
        if (counter==N) ref_ptr=curr;
        curr=curr->link;
    }
    curr->link=head;
    head=ref_ptr->link;
    ref_ptr->link=NULL;
}

int len(){
    int counter=0;
    Node * curr=head;
    while(curr){
        counter++;
        curr=curr->link;
    }
     return counter;
}
