#include <iostream>
using namespace std;

// IMPLEMENATION OF DOUBLE ENDED QUEUE INSERTION DELETION ALLOWED FROM BOTH ENDS
// THE FUNCTION TO INSERT ELEMENT AT REAR END AND DELETE FROM THE FRONT END WILL BE THE SAME AS CIRCULAR QUEUE
// THE FUNCTIONS TO CHECK THE QUEUE EMPTY AND FULL CONDITIONS WILL BE THE SAME AS WELL
class Dequeue
{

    int *arr;
    int size;
    int front;
    int rear;

public:
    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
        cout << "Dequeue of size " << size << " Created Successfully" << endl;
    }

    bool isFUll()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    // function to insert element from rear end
    void insertRear(int x)
    {

        if (isFUll())
        {
            cout << "Dequeue Overflow" << endl;
        }
        else
        {   
            // if the queue is empty move both the front and rear pointer at 0th position
            if (isEmpty())
            {
                front = rear = 0;
            }
            else // noremally find the next postion for insertion
            {
                rear = (rear + 1 )% size;
            }
            arr[rear] = x;
            cout << "Inserted element " << x << " from the rear end" << endl;
        }
    }

    // function to insert at front end
    void insertFront(int x){

        if(isFUll()){
            cout<<"Dequeue Overflow"<<endl;
            return;
        }
        // if empty move front and rear at 0
        if(isEmpty()){
            front=rear=0;
        }
        // if front is at 0 then move front to last as we generally move front to forwards for deletion so for insertion move backwards
        else if(front==0){
            front=size-1;
        }
        // move front backwards to find the next position
        else{
            front--;
        }
        arr[front]=x;
        cout<<"Inserted element "<<x<<" from the front end "<<endl;

    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Dequeue Underflow" << endl;
        }
        int x = arr[front];
        arr[front]=-1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        cout << "Dequed element " << x << " from the front end" << endl;
    }

    // function to delete element from the rear end
    void deleteRear(){
        if(isEmpty()){
            cout<<"Dequeue Underflow"<<endl;
            return;
        }
        // store the element at rear position
        int x =arr[rear];
        // if only single element is present reset the pointers to -1
        if(front ==rear){
            
            front=rear=-1;
        }
        // if rear is at 0th position move it to last as we generally move rear to forward direction for insertion
        else if(rear==0){
            rear=size-1;
        }
        // move rear pointer backwards to point at next element 
        else{
            rear--;
        }
        
        cout<<"Deleted element "<<x<<" from the rear end"<<endl;
    }

    // function to print the elements of the dequeue
    void print()
    {
       
       if(isEmpty()){
        cout<<"Queue Underflow";
        return;
       }
       int temp =front;
       while(temp!=rear){
        cout<<arr[temp]<<" ";
        temp= (temp+1)%size;
       }
       cout<<arr[rear];
       cout<<endl;
    }
    
};

int main()
{
    Dequeue Q(5);
    Q.insertRear(10);
    Q.insertFront(20);
    Q.insertRear(30);
    Q.insertFront(40);
    Q.print();
    Q.deleteRear();
    Q.deleteRear();
    Q.deleteRear();
    Q.deleteRear();
    Q.print();
    

    return 0;
}