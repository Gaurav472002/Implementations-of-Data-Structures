#include<iostream>
using namespace std;

// IMPLEMENTATION OF QUEUE USING ARRAYS
// INSERTION FROM THE REAR END AND DELETION FROM THE REAR END

// create a class for the Queue
class Queue{

    /* the data members of queue will consist of 
    -> an array pointer to declare a dynamic array at runtime_error
    -> Size variable to declare the size of the array
    -> front pointer for deletion of elements
    -> rear pointer for insertion of elements */
    int *arr;
    int size;
    int front;
    int rear;

    public:
    /* constructor of queue to initialize the data members
    intially the pointers will be at -1 */
        Queue(int size){
            this->size=size;
            arr=new int[size];
            this->front=-1;
            this->rear=-1;
            cout<<"Queue of size "<<size<<" Created Successfully"<<endl;
        }
        
        // wheen the rear pointer will reach the end of the array the queue will be full
        bool isFUll(){
            return rear==size-1;
        }
        
        // when both front and rear pointers at -1 then the queue will be empty
        bool isEmpty(){
            return front==rear;
        }

        // Function to enque element, increment the rear pointer and insert the element
        void Enqueue(int x){

            if(isFUll()){
                cout<<"Queue Overflow"<<endl;
            }
           
            else{
                rear++;
                arr[rear]=x;
                cout<<"Enqued element "<<x<<" to the Queue"<<endl;
                
            }
            
        }

        /* function to dequeue the element increment the front store the elment and pop it
        if at any point the queue has 1 element the front==rear so we will reset the pointers */
        void Dequeue(){
            if(isEmpty()){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                front++;
                int x =arr[front];
                arr[front]=-1;
                if(front==rear){
                    front=rear=-1; // reset the pointers
                }
                cout<<"Dequed element "<<x<<" from the Queue"<<endl;
            }
        }

        // function to print the elements of the queue
        void print(){
            int temp =front+1;
            while(temp<size){
                cout<<arr[temp]<<" ";
                temp++;
            }
            cout<<endl;
        }

        
};


int main(){
    Queue Q(5);
    Q.Enqueue(100);
    Q.Enqueue(200);
    Q.Enqueue(300);
    Q.Enqueue(400);
    Q.Enqueue(500);
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Enqueue(600);
    Q.print();
    return 0;
}