#include<bits/stdc++.h>

using namespace std;

void iterativeDeepening(unordered_map<int, list<int>>adj,vector<int>& flag,int start,vector<int>& ans,int depth){
    if(depth == 0){
        return;
    }
    ans.push_back(start);
    for(auto i : adj[start]){
        if(!flag[i]){
            flag[i] = 1;
            iterativeDeepening(adj,flag,i,ans,depth-1);
        }
    }
    return;
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

    for(int depth = 1;depth < 3; depth++){
        vector<int> flag(n,0);
        flag[start] = 1;
        vector<int> ans;
        iterativeDeepening(adj,flag,start,ans,depth);
        
        for(int i=0;i<ans.size();i++)
        {
        cout<<ans[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}