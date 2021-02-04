#include <iostream>

using namespace std;
struct node{
    int data;
    struct node * link;
};
int main()
{
    int *ptr=new int();
    *ptr=5;
    float *flt_ptr=new float(10.11);
    cout<<*ptr<<endl<<*flt_ptr<<endl;
    int *arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=10*(i+1);
        cout<<*(arr+i)<<" ";
    }
    //structure operation
    node *node1=new node();
    node1->data=10;
    cout<<endl<<(*node1).data;
    delete ptr;
    delete flt_ptr;
    delete[] arr;
    delete node1;
    cout<<endl<<*ptr;
    return 0;

}