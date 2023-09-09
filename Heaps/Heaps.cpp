#include<iostream>
using namespace std;


class heap{

    int *arr;
    int pos;
    int size;

    public:

        heap(int size){
            this->size=size;
            arr= new int[size];
            pos=0;
            arr[pos]=-1;
            cout<<"Heap Initialized"<<endl;
        }

        void insert(int x ){
            pos++;
            int index =pos;
            arr[index]=x;
            while(index>1){
                int parent =index/2;

                if(arr[index]<arr[parent]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return ; // heap property satisfies
                }
            }
        }

 void deleteHeap() {
    if (pos == 0) {
        cout << "Heap empty" << endl;
        return;
    }

    int index = 1;
    arr[1] = arr[pos]; // Replace root with the last element
    pos--; 
    while (index <= pos) {
        int lchild = 2 * index;
        int rchild = 2 * index + 1;
        int swapindex = index;

        if (lchild <= pos && arr[lchild] < arr[swapindex]) {
            swapindex = lchild;
        }
        if (rchild <= pos && arr[rchild] < arr[swapindex]) {
            swapindex = rchild;
        }

        if (index != swapindex) {
            swap(arr[index], arr[swapindex]);
            index = swapindex; // Update index to the child that was swapped
        } else {
            return;
        }
    }
}


        void print(){
            for(int i=1;i<=pos;i++){
                cout<<arr[i]<<" ";
            }
        }
};

void heapify(int *arr, int size, int index){

    int largest =index;
    int leftchild =2*index;
    int rightchild =2*index+1;

    if(leftchild<=size && arr[leftchild]>arr[largest]){
        largest =leftchild;
    }
    if(rightchild <=size && arr[rightchild]> arr[largest]){

        largest =rightchild;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}


void heapsort(int*arr,int size){
    
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){

    heap h(10);
   
    h.insert(500);
     h.insert(400);
    h.insert(300);
    h.insert(200);
    h.insert(100);
    h.deleteHeap();
    h.print();

//     int arr[16]={-1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//     int size=15;
//     for(int i=size/2;i>0;i--){
//         heapify(arr,size,i);
//     }

//    for(int i=1;i<=size;i++){
//     cout<<arr[i]<<" ";
//    }
//     cout<<endl;
//     heapsort(arr,size);
//     for(int i=1;i<=size;i++){
//         cout<<arr[i]<<" ";
//     }
    return 0;
}