#include<bits/stdc++.h>

using namespace std;

void dfs(int start,unordered_map<int , list<int>>& adj,vector<int>& flag,vector<int>& ans){
    if(!flag[start]){
        ans.push_back(start);
        flag[start] = 1;
    }

    for(auto i : adj[start]){
        if(!flag[i]) dfs(i,adj,flag,ans);
    }
    return;
}

int main(){
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

    for(int i=0;i<n;i++)
    {
        if(!flag[i])
        {
            dfs(start,adj,flag,ans);
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;

}