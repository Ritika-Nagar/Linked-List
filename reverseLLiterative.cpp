#include <iostream>
using namespace std;


#include <bits/stdc++.h> 

    //Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


// Time Complxity = O(n)
// space comp =O(N) ..BCOZ it would be taking stack space ..har ek node sttack k under jaakar baithegi 

// LinkedListNode<int> * reverse1(LinkedListNode<int> *&head){
    
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
    
    
//     LinkedListNode<int> * chotaHead= reverse1(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return chotaHead;
                            
                            
// }



// void reverse(LinkedListNode<int> * &head, LinkedListNode<int> * prev, LinkedListNode<int> * curr){
//      // base case
    
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     LinkedListNode<int> * forw=curr->next;
//     reverse(head, curr, forw);
//     curr->next= prev;
// }



LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    LinkedListNode<int> * prev=NULL;
    LinkedListNode<int> * curr=head;
    LinkedListNode<int> * forw=NULL;
    while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=forw;
    }
    
    return prev;
}



// time complexity = O(n)
// space complexity= constant 