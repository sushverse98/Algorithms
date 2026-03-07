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

void bfs(int start, vector<int>adj[], vector<int>&visited, vector<int>&result){
    queue<int>q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto x: adj[node]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
            }
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

    //select starting node
    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    if (start < 0 || start >= V) {
    cout << "Invalid starting node";
    return 0;
    }

    //DFS Traversal
    //handle disconnected graph
    dfs(start, adj, visited, result);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,result);
        }
    }

    cout<<"DFS TRAVERSAL: ";
    for(auto x:result){
        cout<<x<<" ";
    }

    // RESET before BFS
    fill(visited.begin(), visited.end(), 0);
    result.clear();

    //BFS Traversal
    //handle disconnected graph
    bfs(start, adj, visited, result);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bfs(i,adj,visited,result);
        }
    }

    cout<<"\nBFS TRAVERSAL: ";
    for(auto x:result){
        cout<<x<<" ";
    }
}