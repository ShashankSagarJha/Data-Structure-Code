#include <iostream>
#include <bits/stdc++.h>
struct Node{
    int data;
    struct Node* link;
};
bool detect_loop(Node *);
bool loop_two_pointer(Node *);
using namespace std;
Node *head;

int main()
{
    Node * node1=new Node;
    Node * node2=new Node;
    Node * node3=new Node;
    Node * node4=new Node;
    head=node1;
    node1->data=10;
    node1->link=node2;
    node2->data=20;
    node2->link=node3;
    node3->data=30;
    node3->link=node4;
    node4->data=40;
    node4->link=node2;

    cout<<detect_loop(head)<<endl;
    cout<<loop_two_pointer(head);
    return 0;
}
bool loop_two_pointer(Node * h){
    Node *slow_ptr=h;
    Node *fast_ptr=h;
    while(slow_ptr && fast_ptr){
        slow_ptr=slow_ptr->link;
        if(fast_ptr->link) fast_ptr=fast_ptr->link->link;
        if (slow_ptr==fast_ptr) return true;
    }
    return false;
}
bool detect_loop(Node *h){
    unordered_set<Node *> s;
    while(h){
        if (s.find(h)!=s.end()) return true;
        s.insert(h);
        h=h->link;
    }
    return false;
}
