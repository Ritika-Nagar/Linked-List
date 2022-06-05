#include <iostream>
using namespace std;

#include <bits/stdc++.h> 


    

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


int getLength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
        
    }
    return len;
}



// Node* getMiddle(Node* head){
//     if(head==NULL){
//         return NULL;
//     }else if(head->next==NULL){
//         return head;
//     }else if( head->next->next==NULL){
//         return head->next;
//     }
    
    
//     Node* slow= head;
//     Node* fast= head->next;
    
//     while(fast!=NULL){
//         fast=fast->next;
//         if(fast!=NULL){
//             fast=fast->next;
//         }
//         slow= slow->next;
//     }
    
//     return slow;
// }

// Node *findMiddle(Node *head) {
//     return getMiddle(head);
// }



Node *findMiddle(Node *head) {
    int len= getLength(head);
    int mid= (len/2) +1;
    
    
    Node* temp= head;
    int pos=1;
    while(pos!=mid){
        temp=temp->next;
        pos++;
    }
    return temp;
    
}