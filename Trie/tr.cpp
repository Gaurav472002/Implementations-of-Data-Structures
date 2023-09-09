#include<iostream>
using namespace std;


class TrieNode{
    
    public:
    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=nullptr;

        }
        isTerminal=false;
    }
    
};

class Trie{

    public:
    TrieNode * root;

    

        Trie(){
            root= new TrieNode('\0');
        }

        void insertUtil(TrieNode * root, string word){

                if(word.length()==0){
                    root->isTerminal=true;
                    return;
                }

                int index =word[0]-'a';
                TrieNode *child;

                if(root->children[index]!=nullptr){
                    child =root->children[index];
                }
                else{
                    child = new TrieNode(word[0]);
                    root->children[index]=child;
                }
                insertUtil(child,word.substr(1));

        }

        void insertword(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode *root, string word){

            if(word.length()==0){
                return root->isTerminal;
            }
            int index =word[0]-'a';
            TrieNode *child;

            if(root->children[index]!=nullptr){
                child=root->children[index];
            }
            else{
                return false;
            }
            return searchUtil(child,word.substr(1));
            
        }

        bool searchWord(string word){
                return searchUtil( root, word);
        }

        void removeutil(TrieNode * root, string word){

            TrieNode * crawler =root;
            int n= word.length();
            for(int i=0;i<n;i++){
                if(!crawler->children[word[i]-'a']){
                    return;
                }
                crawler =crawler->children[word[i]-'a'];
                
            }
            crawler->isTerminal=false;
        }
        void remove(string word){
            removeutil(root,word);
        }
            
};

int main(){

    Trie * t = new Trie();
    t->insertword("daddy");
    t->insertword("dad");
    t->insertword("dada");
    t->insertword("daddys");
    // t->remove("daddy");
    t->remove("dad");

    cout<<t->searchWord("daddy");
    cout<<t->searchWord("dad");
    cout<<t->searchWord("dada");
    cout<<t->searchWord("daddys");
}