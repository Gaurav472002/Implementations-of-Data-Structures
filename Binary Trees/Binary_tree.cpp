#include<iostream>
#include<queue>
using namespace std;


class Node{

    public:
    int data;
    Node *left;
    Node *right;

    
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

Node * ConstructTree(Node * root){
    
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data==-1)return nullptr;
    root = new Node(data);
    cout<<"Enter data for the left of "<<data<<endl;
    root->left = ConstructTree(root->left);
    cout<<"Enter data for the right of "<<data<<endl;
    root->right = ConstructTree(root->right);
    
    return root;
    
}

void inorder(Node * root){
    
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void preorder(Node * root){
    
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);   
    preorder(root->right);
}

void postorder(Node * root){
    
    if(!root){
        return;
    }
    
    postorder(root->left);   
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node * root){
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *top =q.front();
        q.pop();
        cout<<top->data<<" ";
        if(top->left!=nullptr){
            q.push(top->left);
        }
        if(top->right!=nullptr){
            q.push(top->right);
        }
    }
}

Node * ConstructTreefromLevelOrder(Node * root){

    queue<Node*>q;
    int data;
    cout<<"Enter the data for the root node"<<endl;
    cin>>data;
    if(data!=-1){
        root =new Node(data);
    }
    q.push(root);
    while(!q.empty()){

        Node *temp =q.front();
        q.pop();

        int ldata;
        cout<<"Enter the data for the left of "<<temp->data<<endl;
        cin>>ldata;
        if(ldata!=-1){
            temp->left= new Node(ldata);
            q.push(temp->left);
        }

        int rdata;
        cout<<"Enter the data for the right of "<<temp->data<<endl;
        cin>>rdata;
        if(rdata!=-1){
            temp->right= new Node(rdata);
            q.push(temp->right);
        }

    }
    return root;

}

int main(){

    Node *root =nullptr;
    // root=ConstructTree(root);
    root = ConstructTreefromLevelOrder(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}