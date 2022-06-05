#include <iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory with Node value"<<this->data<<endl;

    }
};


void insertAtTail(struct Node* & head, struct Node* &tail, int val){
    
    Node* temp =new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
        
    }else{
        tail->next=temp;
        tail=temp;
    }
}

struct Node* add(struct Node* first, struct Node* second){
    int carry=0; 
    Node* ansHead=NULL;
    Node* ansTail= NULL;
    
    while(first!=NULL && second!=NULL){
        int sum= carry+ first->data+ second->data;
        int digit= sum%10;
        // create new node 
        
        insertAtTail(ansHead, ansTail , digit);
        carry =sum/10;
        
        first=first->next;
        second=second->next;
        
    }
    
    while(first!=NULL){
        int sum= carry+ first->data;
        int digit= sum%10;
        // create new node 
        
        insertAtTail(ansHead, ansTail , digit);
        carry =sum/10;
        
        first=first->next;
    }
    
    
    while(second!=NULL){
        int sum= carry+ second->data;
        int digit= sum%10;
        // create new node 
        
        insertAtTail(ansHead, ansTail , digit);
        carry =sum/10;
        
        second=second->next;
    }
    
    while(carry!=0){
        int sum= carry;
        int digit= sum%10;
        // create new node 
        
        insertAtTail(ansHead, ansTail , digit);
        carry =sum/10;
        
        
    }
    
    return ansHead;
}
struct Node* reverse(struct Node* &head){
    Node* prev=NULL;
    Node* curr= head;
    Node* forw= curr->next;
    while(curr!=NULL){
        forw= curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=forw;
    }
    
    head= prev;
    return prev;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first= reverse(first);
       second= reverse(second);
       
       Node* ans= add(first, second);
       
       ans= reverse(ans);
       return ans;
    }
};
