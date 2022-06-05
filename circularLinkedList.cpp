#include <iostream>
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


void insertNode(Node* & tail, int element , int data){
    // Assuming that the element is present in linked list 

    // empty list 
    if (tail==NULL){
        Node* newNode= new Node(data);
        tail= newNode;
        newNode->next=newNode; //making a circular linked list .. node pinting to itself only 

    }
    else{
        // non empty list 
        Node* curr=tail;
        
        while(curr->data!=element){
            curr=curr->next;
        }

        Node* temp= new Node(data);
        temp->next=curr->next;
        curr->next=temp;

    }


}

void print(Node* tail){
    Node* temp=tail;

    do{
        cout<<temp->data<<endl;
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<" ";
}

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


int main(){
    Node* tail= NULL;
    insertNode(tail,1,80);
    

    insertNode(tail,80,78 );
    

    insertNode(tail, 78,2);
    insertNode(tail, 2,10);
    print(tail);
    cout<< isCircular(tail)<<endl;
    return 0;
}