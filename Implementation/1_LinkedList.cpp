#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(nullptr){} //default constructor
    Node(int val):data(val),next(nullptr){}  // parameterised constructor
    Node(int val , Node* nextNode):data(val),next(nextNode){} // parameterised constructor
};

class LinkedList{

    Node* head;

    public:

    LinkedList():head(nullptr){}

    void insertNode(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void deleteNode(int toDelete){
        if(head==nullptr){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(head->data==toDelete){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node* current=head;
        Node* previous=nullptr;
        while(current->data!=toDelete && current!=nullptr){
            previous=current;
            current=current->next;
        }
        if(current==nullptr){
            cout<<"Node not found to be deleted"<<endl;
        }else{
            previous->next=current->next;
            delete current;
        }
    }

    void display(){
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    
};

int main(){
    LinkedList list;
    list.insertNode(1);
    list.insertNode(3);
    list.insertNode(4);
    list.display();
    list.deleteNode(3);
    list.display();
    return 0;
}