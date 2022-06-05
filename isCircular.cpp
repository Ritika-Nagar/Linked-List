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


bool isCircular(Node * head){

    if(head==NULL){
        return true;
        }
    
    Node* temp= head->next;

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    if(temp==NULL){
        return false;
    }else{
        return true;
    }



}

bool detectCycle(Node* head){
    Node* temp= head;
    map<Node*, bool> vis;
    
    while(temp!=NULL){

        if(vis[temp]==true){
            return true;
        }
        vis[temp]=true;
        temp=temp->next;
    }

    return false;
}

bool floydDetectLoop(Node* head){

    if(head==NULL){
        return false;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow= slow->next;

        if(slow==fast){
            return true;
        }
        
    }

    return false;



}


Node* floydDetectLoop1(Node* head){

    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow= slow->next;

        if(slow==fast){
            return slow;
        }
        
    }

    return NULL;



}

Node* startNodeOfLoop(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection = floydDetectLoop1(head);
    Node* slow = head;


    while(slow!=intersection){
        slow=slow->next;
        intersection= intersection->next;

    }

    return slow;
    


}

void removeLoop(Node* head){

    if(head==NULL){
        return;
    }

    Node* startOfLoop= startNodeOfLoop(head);

    Node* temp= startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }

    temp->next=NULL;
}