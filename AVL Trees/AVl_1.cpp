#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *left;
    Node * right;
    int height;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
        this->height=1; // each node will be of height 1
    }

};


int getheight(Node * node){
    if(!node){
        return 0;
    }
    return node->height;
}

int getBalance(Node * node){
    if(!node){
        return 0;
    }
    return getheight(node->left)- getheight(node->right);
}


Node * rightRotate(Node *P){
    Node * C = P->left;
    Node * T =C->right;
    
    C->right=P;
    P->left =T;

    P->height= 1+ max(getheight(P->left), getheight(P->right));
    C->height= 1+ max(getheight(C->left), getheight(C->right));
    return C;
}

Node * leftRotate(Node * C){
    Node * P =C->right;
    Node * T = P->left;
    
    P->left=C;
    C->right=T;
    
    C->height= 1+ max(getheight(C->left), getheight(C->right));
    P->height= 1+ max(getheight(P->left), getheight(P->right));

    return P;
}


Node * insertIntoBST(Node * root, int data){

    if(!root){
        root =new Node(data);
        return root;
    }

    if(data<root->data){
        root->left = insertIntoBST(root->left,data);
    }
    else if(data>root->data){
        root->right =insertIntoBST(root->right,data);
    }
    else{
        return root; // not allowing duplicate notes in the BST
    }

    root->height = 1 +max(getheight(root->left), getheight(root->right));

    int balance = getBalance(root);

    // left left rotation
    if(balance>1 && data < root->left->data){
        return rightRotate(root);
    }

    // left right rotation
    if(balance>1 && data>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right rotation
    if(balance <-1 && data >root->right->data){
        return  leftRotate(root);
    }

    // right left rotation
    if(balance< -1 && data < root->right->data){
        root->right =rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

Node * deletefromBST(Node * root, int x){

    if(!root)return nullptr;

    if(x<root->data){
        root->left = deletefromBST(root->left,x);
    }
    else if(x>root->data){
        root->right = deletefromBST(root->right,x);
    }
    else{

        // 1 child or  no child cases
        if(!root->left){
            Node * temp =root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node * temp =root->left;
            delete root;
            return temp;
        }
        else{
            Node * temp =root->right;
            while(temp->left){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deletefromBST(root->right,temp->data);
        }
    }

    if(!root){
        return nullptr;
    }
    root->height = 1 +max(getheight(root->left), getheight(root->right));

    int balance =  getBalance(root);

    // LL CASE
    if(balance>1 && getBalance(root->left)>=0){
        return rightRotate(root);
    }
    // LR CASE
    if(balance >1 && getBalance(root->left)<0){
        root->left =leftRotate(root->left);
        return rightRotate(root);
    }
    // RR CASE
    if(balance<-1 && getBalance(root->right)<=0){
        return leftRotate(root);
    }

    // RL CASE
    if(balance <-1 &&getBalance(root->right)>0){
        root->right =rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
    
    

}


// void constructTree(Node *& root){
//     cout<<"Enter the data for the BST creation :"<<endl;
//     int data;

//     do{
//         cin>>data;
//         if(data!=-1){
//             root= insertIntoBST(root,data);
//         }
//     }while(data!=-1);
// }

void constructTree(Node *&root){

    int data=0;

    while(data!=1001){
        root=insertIntoBST(root,data);
        data++;
    }
}

void preorder(Node * root){
    if(!root){
        return  ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    Node * root =nullptr;
    constructTree(root);
    preorder(root);
    cout<<endl;
    cout<<getheight(root)<<endl;
    cout<<getBalance(root)<<endl;

    // root=deletefromBST(root,1);

    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<getheight(root)<<endl;
    // cout<<getBalance(root)<<endl;
    return 0;
}