#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int n,dis;
    edge(int nn,int dd)
    {
        n=nn;
        dis=dd;
    }
    bool operator<(const edge &e)const
    {
        if(dis>e.dis)
        {
            return true;
        }
        else
        {
            return false ;
        }
    }
};
int main()
{
    vector<int>adj[1000],wt[1000];
    int n,e;
    cin>>n>>e;
    vector<int>dis(n+1,1e9);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        wt[u].push_back(w);
        wt[v].push_back(w);
    }
    int s,e1;
    cin>>s>>e1;
    priority_queue<edge>pq;
    dis[s]=0;
    pq.push(edge(s,0));
    while(!pq.empty())
    {
        edge u=pq.top();
        pq.pop();
        for(int i=0;i<adj[u.n].size();i++)
        {
            int v=adj[u.n][i];
            int w=wt[u.n][i];
            if(dis[u.n]+w<dis[v])
            {
                dis[v]=dis[u.n]+w;
                pq.push(edge(v,dis[v]));
            }
        }
    }
    cout<<dis[e1]<<endl;


    return 0;
}
