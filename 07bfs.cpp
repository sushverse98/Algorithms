#include<bits/stdc++.h>
using namespace std;

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
    for(int i=0; i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"\nAdjancy List: \n";
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    vector<int>visited(V,0);
    vector<int>result;

    //handle disconnected graph
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bfs(i,adj,visited,result);
        }
    }

    cout<<"BFS TRAVERSAL: ";
    for(auto x:result){
        cout<<x<<" ";
    }
}