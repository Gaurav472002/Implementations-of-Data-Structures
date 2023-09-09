#include<iostream>
using namespace std;


class TrieNode{

    public:

    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data){
        this->data =data;
        

        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isTerminal=false;
    }
};

class Trie{

    public:
    TrieNode *root;

    Trie(){
        root =new TrieNode('\0');
        cout<<"Trie Initialized"<<endl;
    }


    void insertUtil(TrieNode * root, string word){

        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        TrieNode *child;
        int index =word[0]-'a';
        if(root->children[index]!=nullptr){
            child =root->children[index];
        }
        else{
            child =new TrieNode(word[0]);
                root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }


    bool SearchUtil(TrieNode *root, string word){

        if(word.length()==0){
            return root->isTerminal;
        }
        TrieNode *child;
        int index = word[0]-'a';

        if(root->children[index]!=nullptr){
            child =root->children[index];
        }
        else{
            return false;
        }
        return SearchUtil(child,word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);
    }


    bool searchWord(string word){
        return SearchUtil(root,word);
    }
};

int main(){

     Trie *T = new Trie();

    T->insertWord("daddy");
    T->insertWord("dad");
    T->insertWord("dada");
    T->insertWord("dadd");
    cout << T->searchWord("daddy");
    cout << T->searchWord("dadd");
    cout << T->searchWord("dad");
    cout << T->searchWord("dada");
    return 0;
}