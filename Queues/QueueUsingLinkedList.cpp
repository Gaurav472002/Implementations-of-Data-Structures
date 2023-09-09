#include<iostream>
using namespace std;

// IMPLEMENTATION OF QUEUE USING LINKED LISTS
// INSERTION FROM THE REAR END AND DELETION FROM THE REAR END

// create a class to create the node for the linked list
class Node{

    public:
        int data;
        Node * next;

        Node(int data){
            this->data=data;
            this->next=nullptr;
        }
};

// create the Queue class to maintain to pointers front and rear for the queue. Initially they will point to null
class Queue{

    Node *front;
    Node *rear;
    public:
    // constructor for queue initialization
    Queue(){
        front=rear=nullptr;
        cout<<"Queue initialized"<<endl;
    }

    // if both pointers point to null then the queue will be empty
    bool isempty(){
        return  front==nullptr;
    }
    
    /* Function to enqueu element
    if the queue is empty the both front and rear will point to the same element
    if not then insert element at the end of the linked list and make rear point to it */
    void enqueue(int x){
        Node *n = new Node(x);

        if(isempty()){
            front=rear=n; // first node insertion case
        }
        else{
            rear->next=n;
            rear=n;
        }
        cout<<"Enqueued element "<<x<< " to the Queue"<<endl;
    }

    /* Function to delete element from the queue
    make a temporary pointer to the front point the current front to next element and delete the first element of the linked list */
    void dequeue(){
        if(isempty()){
            cout<<"Queue Underflow"<<endl;
        }
        else{
            Node * temp =front;
            int x = temp->data;
            front=front->next;
            delete temp;
            cout<<"Dequeued element "<<x<<"  from the Queue"<<endl;
        }
    }

    // Function to print element of the queue
    void print(){
        Node * temp=front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q1;
    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.enqueue(400);
    q1.print();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.print();
    return 0;
}