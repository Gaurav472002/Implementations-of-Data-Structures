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
        this->height=1;
    }

};

int getHeight(Node * N){
    if(!N){
        return 0;
    }
    return N->height;
}

int getBalance(Node * N){
    if(!N){
        return 0;
    }
    return getHeight(N->left)-getHeight(N->right);
}


Node * rightRotate(Node * p){
    Node *c =p->left;
    Node * t =c->right;
    c->right =p;
    p->left =t;

    p->height =  max(getHeight(p->left),getHeight(p->right))+1;
    c->height =  max(getHeight(c->left),getHeight(c->right))+1;
    cout<<"right rotate done"<<endl;
    return c;
}

Node * leftRotate(Node * c){

    Node * p=c->right;
    Node * t =p->left;

    p->left=c;
    c->right =t;

    c->height =  max(getHeight(c->left),getHeight(c->right))+1;
    p->height =  max(getHeight(p->left),getHeight(p->right))+1;
    
    cout<<" left rotate done on "<<c->data<<endl;

    return p;

    
}


Node * rotate(Node * root){

    int balance = getBalance(root);

    // 4 possible cases of rotations

    //left heavy cases

    if(balance>1){

        // left left case
        if(getHeight(root->left->left)- getHeight(root->left->right)>0){
            
            return rightRotate(root);
        }
        // left right case

        if(getHeight(root->left->left)- getHeight(root->left->right)<0){
            root->left =leftRotate(root->left);
            
            return rightRotate(root);
        }
    }


      //right heavy cases

    if(balance < -1){

        // right right case
        if(getHeight(root->right->left)- getHeight(root->right->right)<0){
            
            return leftRotate(root);
        }
        // right left case

        if(getHeight(root->right->left)- getHeight(root->right->right)>0){
            root->right =rightRotate(root->right);
            
            return leftRotate(root);
        }
    }

    // root->height= 1+ max(getHeight(root->left),getHeight(root->right));

    return root;

}




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
    root->height= 1+ max(getHeight(root->left),getHeight(root->right));
    
    return rotate(root);
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
    cout<<getBalance(root)<<endl;
    // deleteNode(root,5);
    level(root);
    // cout<<root->left->height<<endl;
    // cout<<root->right->height<<endl;
    cout<<getBalance(root)<<endl;
    cout<<getHeight(root);

    
    return 0;

}