#include <iostream>
using namespace std;


   // time complex: O(n)
   //space: 

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };




// Node* reverse( Node* head){
//     if(head==NULL || head->next==NULL ){
//         return head;
//     }
    
//     Node* chotaHead= reverse(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return chotaHead;
// }
Node* kReverse(Node* head, int k) {
    
    Node* curr=head;
    Node* prev=NULL;
    Node* forw= NULL;
    
    // first k node will be reversed 
    int cnt=0;
    while(curr!=NULL && cnt<k){
        forw= curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
        cnt++;
    }
    
    if(forw!=NULL){
    head->next= kReverse(forw, k);
    }
    
    return prev;
    
    
}