#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &result){
    visited[node] = 1;
    result.push_back(node);

    for(auto x:adj[node]){
        if(!visited[x]){
            dfs(x,adj,visited,result);
        }
    }
}

int main(){
    int V,E;
    cout<<"enter number of vertices: ";
    cin>>V;
    cout<<"enter number of edges: ";
    cin>>E;
    
    vector<int>adj[V];

    cout<<"enter edges: \n";
    for(int i=0;i < E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected graph
    }

    vector<int>visited(V,0);
    vector<int>result;

    //handle disconnected graph
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,result);
        }
    }

    cout<<"DFS TRAVERSAL: ";
    for(auto x:result){
        cout<<x<<" ";
    }
}