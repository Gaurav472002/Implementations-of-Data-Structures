#include<iostream>
#include<queue>
using namespace std;



class Node{

    public:
    int data;
    int height;
    Node *left;
    Node * right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }

};


Node * insertintoBST(Node *root,int data){

    if(!root){
        root = new Node(data);
        return root;
    }
    if(data<root->data){
        root->left = insertintoBST(root->left,data);
    }
    else if(data>root->data){
        root->right = insertintoBST(root->right,data);

    }
    else{
        return root;
    }
    
    
    return root;
}


Node * deleteNode(Node * root, int x){

    if(!root)return nullptr;

    if(x<root->data){
        root->left = deleteNode(root->left,x);
    }
    else if(x> root->data){
        root->right= deleteNode(root->right,x);
    }
    else{

        if(!root->left){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else{

            Node * temp = root->left;
            while(temp->right){
                temp=temp->right;
            }
            root->data=temp->data;
            root->left= deleteNode(root->left,temp->data);
            
        }
    }
   
    return root;
}

void Inorder(Node  *root){
    if(!root)return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node  *root){
    if(!root)return ;
     cout<<root->data<<endl;
    Preorder(root->left);
    Preorder(root->right);
}
void PostOrder(Node  *root){
    if(!root)return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<endl;
}
void level(Node * root){

        queue<Node *>q;
        q.push(root);

        while(!q.empty()){
            Node * temp =q.front();
            q.pop();
            
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);

            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<endl;
}

void preorder(Node * root){

    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



void createBST(Node *& root){

    cout<<"Enter the data for the BST creation"<<endl;
    int data;
    do{
        cin>>data;
        if(data!=-1){
            root = insertintoBST(root,data);
        }
    }while(data!=-1);
}

// void createBST(Node *&root){

//     int data=0;

//     while(data!=1001){
//         root=insertintoBST(root,data);
//         data++;
//     }
// }





int main(){

    Node *root =nullptr;
    createBST(root);

    
    level(root);
    deleteNode(root,100);
    level(root);
    
    

    
    return 0;

}