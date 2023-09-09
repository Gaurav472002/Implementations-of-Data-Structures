#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>>adj_matrix;

    public:
    Graph(int n){
        adj_matrix= vector<vector<int>>(n,vector<int>(n,0));

    }

    void add_edge(int u, int v, bool directed){

        adj_matrix[u][v]=1;
        if(!directed){
            adj_matrix[v][u]=1;
        }
    }

    void print(){
        int n = adj_matrix.size();
        for(int i =0;i<n;i++){
            
            cout<<i<<"->";
            for(int j=0;j< n;j++){
                if(adj_matrix[i][j]==1){
                    cout<<j<<" ";
                }
            }   
            cout<<endl;

        }
    }
};


int main(){

    int n=0,e=0;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    Graph g(n);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v,false);
    }
    g.print();
    return 0;

}