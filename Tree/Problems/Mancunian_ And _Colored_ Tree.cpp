/*After a hectic week at work, Mancunian and Liverbird decide to go on a fun weekend camping trip. As they were passing through a 
forest, they stumbled upon a unique tree of N nodes. Vertices are numbered from 1 to N.
Each node of the tree is assigned a color (out of C possible colors). Being bored, they decide to work together (for a change) and 
test their reasoning skills. The tree is rooted at vertex 1. For each node, they want to find its closest ancestor having the same 
color.

Input format
The first line contains two integers N and C denoting the number of vertices in the tree and the number of possible colors.
The second line contains N-1 integers. The i th  integer denotes the parent of the (i+1)th vertex.
The third line contains N integers, denoting the colors of the vertices. Each color lies between 1 and C inclusive.

Output format
Print N space-separated integers. The i th integer is the vertex number of lowest ancestor of the (i+1)th node which has the same
color. If there is no such ancestor, print 1 for that node.*/

#include<bits/stdc++.h>
using namespace std;
#define SIZE 100001
int color[SIZE],ans[SIZE];
stack<int>per_color[SIZE];
vector<int>tree[SIZE];
void DFS(int node)
{
    if(per_color[color[node]].empty())
        ans[node]=-1;
    else{
        ans[node]=per_color[color[node]].top();

    }
    per_color[color[node]].push(node);
    for(int i=0;i<tree[node].size();i++)
    {
        int new_v=tree[node][i];
        DFS(new_v);
    }
    per_color[color[node]].pop();
}
int main()
{
    int n,c,i;
    cin>>n>>c;
    for(i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        tree[p].push_back(i);
    }
    for(i=1;i<=n;i++)
    {
        cin>>color[i];
    }
    DFS(1);
    for(i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}
