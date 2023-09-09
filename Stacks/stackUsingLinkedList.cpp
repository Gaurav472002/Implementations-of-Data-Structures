#include<iostream>
using namespace std;

// Stack implementation using the linked list
// INSERTION DELETION TAKES PLACE FROM ONE END ONLY

// As we are using linked list create a class for the nodes of the linked list
class Node{
    public:
    int data;
    Node *next;

    
        Node(int data){
            this->data=data;
            this->next=nullptr;
        }
};

// create a class for the stack where we will have a top pointer to keep track of the topmost element of the stack
class Stack{
    // initially the top pointer will be null when there are no elements in the stack
    Node *top=nullptr;

    public:

    // when the stack is empty the top pointer will point to null
    bool isEmpty(){

        return top==nullptr;
    }

    /* to push the element to the stack check if the stack is empty or not if it is then simply create a node and make it the topmost element
     if the stack is not empty then insert element at the first of the linked list and make it the topmost element
     for example if the linked list is 10->nullptr then  20->10->nullptr and then top =20 */
    void push(int x){
        Node * n = new Node(x);
        if(!top){
            top=n;
        }
        else{
            n->next=top;
            top=n;
        }
        cout<<"Pushed "<<x<<" to the stack"<<endl;
    }

    /* to pop the element from the stack first check if it is empty or not
    if not empty then create a temporary pointer to the top element of the stack
    capture its data and then  move the top pointer to the next pointer and delete it
    basically delete the first element from linked list and move the pointer forward */
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            Node * temp =top;
            int x =temp->data;
            top=top->next;
            delete temp;
            cout<<"Popped "<<x<<" from the stack"<<endl;
        }
        
    }

    // FUnction to get the topmost element of the stack
    void peek(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
        }
        else{
            cout<<"The top element is "<<top->data<<endl;
        }
    }

    /* Function to print the whole stack
    point a temporary pointer to the top of the stack and keep printing data and move it forward until it reaches the end i.e null */
    void print(){
        Node * temp =top;
        while(temp){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
};


int main(){
    Stack s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.print();
    s.pop();
    s.print();
    s.peek();

    return 0;
}