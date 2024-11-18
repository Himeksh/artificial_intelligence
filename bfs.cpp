#include<bits/stdc++.h>

using namespace std;

void bfs(int start,unordered_map<int , list<int>>& adj,int n,int e, vector<int>& flag,vector<int>&ans){
    queue<int> q;

    q.push(start);
    flag[start] = 1;


    while(!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for(auto i: adj[front]){
            if(!flag[i]){
                q.push(i);
                flag[i] = 1;
            }
        }

    }

}

int main()
{
    int n,e;

    cout<<"enter the number of node"<<endl;
    cin>>n;

    cout<<"enter the number of edges"<<endl;
    cin>>e;

    unordered_map<int , list<int>> adj;

    for(int i=0;i<e;i++)
    {
        int u,v;

        cout<<"enter the pair of nodes having an edge"<<endl;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout<<"enter the starting node"<<endl;
    cin>>start;

    vector<int> flag(n,0);


    vector<int> ans;

    for(int i=0;i<n;i++){
        if(!flag[i]){
            bfs(start,adj,n,e,flag,ans);
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}

// enter the pair of nodes having an edge
// 0 1
// enter the pair of nodes having an edge
// 0 2
// enter the pair of nodes having an edge
// 1 3
// enter the pair of nodes having an edge
// 2 3
// enter the pair of nodes having an edge
// 2 4
// enter the pair of nodes having an edge
// 3 5 
// enter the pair of nodes having an edge
// 4 5
// enter the pair of nodes having an edge
// 4 6
// enter the pair of nodes having an edge
// 5 7
// enter the pair of nodes having an edge
// 6 7