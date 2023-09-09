// IMPLEMENTATION OF STACKS USING ARRAYS 
// INSERTION DELETION TAKES PLACE FROM ONE END ONLY
#include<iostream>
using namespace std;

// create the class for the stack
class Stack{

    /* the data members will be an array pointer for dynamic allocation of array, 
    top variable to store the index of the topmost max_element
    size variable -> to declare the size we will allocate for our stack */

    int *arr;
    int top;
    int size;

    public:
    // constructor to initialize the stack
        Stack(int size){
            this->size=size;
            this->top=-1;
            arr=new int[size];
            cout<<"Stack of size "<<size<<" created successfully"<<endl;
        }

        // function to check if the stack is empty or not 
        bool isEmpty(){
            return top==-1;
        }
        // function to check if the stack is full or not if we start the top from 0 then the condition will be top==size
        bool isFull(){
            return top==size-1;
        }
        /* function to push element to the stack
        as we are starting top from -1 we will first increment the top and then insert the element inside the stack */

        void push(int x){
            if(isFull()){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                top++;
                arr[top]=x;
                cout<<"Pushed element "<<x<<" to the stack successfully"<<endl;
            }
        }

        /* function to pop element from the stack
        first we will store the topmost element of the stack and then we will decrement the top counter */
        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                int x =arr[top];
                arr[top]=-1;
                top--;
                cout<<"Popped element "<<x<<" from the stack successfully"<<endl;
                
            }
        }
        // function to get the topmost element of the stack
        void peek(){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
            }
            else{

                cout<<"The top element is "<<arr[top]<<endl;
            }
        }

        // Function to print the elments of the stack

        void print(){
            int temp =top;
            while(temp>=0){
                cout<<arr[temp]<<endl;
                temp--;
            }
            cout<<endl;
        }
};



int main(){

    Stack s1(5);
    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(400);
    s1.push(500);
    
    // s1.pop();
    // s1.pop();
    // s1.pop();
    s1.peek();
    s1.print();
    return 0;
}