#include<iostream>
#include<map>
#include<list>
using namespace std;


class Graph{
    map<int,list<int>>mp;

    public:
    Graph(){
        cout<<"Graph initialized"<<endl;
        
    }

    void add_edge(int u,int v, bool directed){
        mp[u].push_back(v);
        if(!directed){
            mp[v].push_back(u);
        }
    }

    void print(){
        

        for(auto i: mp){

            cout<<i.first<<"->";

            for(auto j: i.second){
                cout<<j<<" ";
            }

            cout<<endl;
        }
    }
    
};



int main(){

    Graph g;
    int n,e;
    cout<<"Enter the number of nodes in the graph "<<endl;
    cin>>n;
    cout<<"Enter the  number of edges in the graph"<<endl;
    cin>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v,false);

    }
    g.print();
    return 0;
}