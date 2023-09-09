#include <iostream>
using namespace std;
// IMPLEMENTATION OF CIRCULAR QUEUE
class Queue
{

    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
        cout << "Queue of size " << size << " Created Successfully" << endl;
    }

    /* function to determine queue is full or not
     when the front will be at 0 and suppose the size of our queue 5 and we are at index 4 which is the last index then 4+1%5 =0 which means
    queue is full */
    bool isFUll()
    {
        return (rear + 1) % size == front;
    }

    // Function to determine if the queue is empty or not
    bool isEmpty()
    {
        return front == -1;
    }
    
    /* function to enqueue elements in the queue
    let size =5 rear=-1
    insert first element -1+1%5 =0 insert at 0 index
    insert second element 0+1%5 =1 insert at 1 index
    using this approach if only a single element is present at last index and we want to insert then we can traverse back to the front of the array */
    void Enqueue(int x)
    {

        if (isFUll())
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1 )% size;
            }
            arr[rear] = x;
            cout << "Enqueued Element " << x << " to the queue" << endl;
        }
    }
    // function to delete element from teh queue using the same formula

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
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

        cout << "Dequed element " << x << " from the Queue" << endl;
    }

    void print()
    {
       
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
    Queue Q(5);
    Q.Enqueue(100);
    Q.Enqueue(200);
    Q.Enqueue(300);
    Q.Enqueue(400);
    Q.Enqueue(500);
    Q.Enqueue(500);
     Q.print();

    Q.Dequeue();
    Q.Dequeue();
    Q.Enqueue(600);
    Q.Enqueue(700);
    //  Q.Dequeue();
    //   Q.Dequeue();
    //    Q.Dequeue();
    //     Q.Dequeue();
    //      Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Dequeue();
    // Q.Enqueue(600);
    Q.print();
    return 0;
}