#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        
        if(this->next!=NULL){
            delete next;
            this->next=NULL;

        }
        cout<<"Memory is free for the data "<<this->data<<endl;
    }

};

void insertAtHead(Node* &head, int data){

    if(head==NULL){
        Node* temp= new Node(data);
        head=temp;

    }else{
        Node* temp= new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;

    }
    

}

void insertAtTail(Node* &tail, int data){

    if(tail==NULL){
        Node* temp= new Node(data);
        tail=temp;
    }
    else{
    Node* temp= new Node(data);
    tail->next=temp;
    tail->prev=temp;
    tail =temp;
    }

}

void insertAtMiddle(Node* &head, Node* &tail ,int position, int data){
    Node* temp=head;
    Node* nodeToinsert= new Node(data);
    if(position==1){
        insertAtHead(head,data);
        return;
    }

    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }


    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    nodeToinsert->next=temp->next;
    temp->next->prev= nodeToinsert;
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;




}

void deleteNode(Node* &head,int position){
    // deletion at head
    Node* temp= head;

    //deletion at head
    if(position==1){
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;

    }
    else{
        Node* prev=NULL;
        Node* curr= head;

        int cnt=1;

        while(cnt< position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;
}

int length(Node* &head){
    Node* temp= head;
    int cnt=0;

    while(temp->next!=NULL){
        cnt++;
    }

    return cnt;
}

int getLength(Node* &head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
        
    }
    return cnt;
}


int main(){
    Node* node1= new Node(10);
    Node* head= node1;
    Node* tail=node1;
    // print(head);
    // insertAtHead(head,11);
    // insertAtHead(head,23);
    // insertAtHead(head,32);

    insertAtTail(tail,23);
    insertAtTail(tail,18);
    insertAtTail(tail,45);
    print(head);
    insertAtMiddle(head, tail, 2, 60);
    insertAtMiddle(head, tail, 1, 1);

    // int len= length(head);
    // cout<<len<<endl;
     //insertAtMiddle(head, tail, 7, 90);
    // deleteNode(head,3);
     deleteNode(head,1);
     


    print(head);
    return 0;

}