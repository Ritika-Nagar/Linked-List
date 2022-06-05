#include <iostream>
#include<map>
using namespace std;

class Node{

    public:
    Node* next;
    int data;

    Node(int data){
        this -> data= data;
        this -> next=NULL;
    }

    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
            delete next;// next is a node
            this->next=NULL;

        }
        cout<<"Memory is free for the node with data"<< value <<endl;
    }
};

void insertAtHead(Node* &head, int d){// by reference(&) bcoz we want to work in original linked list

    // new Node create 

    Node* temp=  new Node(d);
    temp -> next= head;
    head=temp;
}

void insertAtTail(Node* &tail, int d){
    // new Node create 

    Node* temp=  new Node(d);
    tail-> next= temp;
    tail= temp;

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

void insertAtMiddle(Node* &tail, Node* &head, int d, int position){
    int cnt=1;
    Node* temp=head;

    if(position==1){
        insertAtHead(head, d);

    }



    // isme direcly first position par nhi daal paate hai 
    while(cnt <position-1){
        cnt++;
        temp=temp->next;
    }

    // inserting last node
    if(temp->next==NULL){
        insertAtTail(tail,d);// last node directly bhi add ho jaati hai par uska tail update nhi hoti hai 
    }

    Node* nodeToinsert =new Node(d);
    nodeToinsert->next= temp->next;
    temp->next=nodeToinsert;

    
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


void deleteNode(Node* & head, int position){

    
    // deleting at first node
    if(position==1){
        Node* temp= head;
        head=head->next;
        //memory free
        temp->next=NULL;
        delete temp;
        
    }
    else{
        // deleting at last or other node

        Node* prev=NULL;
        Node* curr= head;

        int cnt=1;

        while(cnt< position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;


    }
}

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp= temp->next;
    }
    cout<< endl;
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
            cout<<"Cycle is present at data "<<slow->data<<endl;
            return true;
        }
        
    }

    return false;



}


int main(){
    cout<<"hello"<<endl;
    Node* node1= new Node(10);
    //cout<< node1->data<<endl;
    // print(node1);
    
    insertAtHead(node1, 20);
     print(node1);
    // insertAtHead(node1, 34);
    // print(node1);
    Node* head= node1;
    Node* tail= node1;
    

    insertAtTail(tail, 11);
    
    
    insertAtTail(tail, 15);
    
    insertAtTail(tail,54);
    tail->next=head->next;
   


    //insertAtMiddle(head,16,1);
    //insertAtMiddle(head,16,4);
    //print(head);

    // deleteNode(head,2);
    // print(head);

    // cout<< isCircular(tail)<<endl;
    cout<<floydDetectLoop(head)<<" ans"<<endl;    
}