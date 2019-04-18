/*
You are given a rooted tree with N nodes (numbered 1 through N); node 1 is the root. Each node has a value;
let's denote the value of node i by Ai You may perform the following operation any number of times (including zero): 
choose any node which still exists in the tree and remove the whole subtree of this node including itself.
Let's define the profit as the sum of values of all nodes which currently exist in the tree minus X⋅k, 
where k denotes the number of times this operation was performed. Find the maximum possible profit.

Input
    The first line of the input contains a single integer T
denoting the number of test cases. The description of T
test cases follows.
The first line of each test case contains two space-separated integers N
and X.
The second line contains N
space-separated integers A1,A2,…,AN.
Each of the following N−1
lines contains two space-separated integers u and v denoting that nodes u and v are connected by an edge.
Output:
maximum profit
*/
#include<iostream>
#include<vector>
using namespace std;
int a[100010];
long long max_profit(vector<long long int> tree[],long long int node,long long int par,long long int x)
{
    long long int current_gain=a[node];
    for(int i=0;i<tree[node].size();i++)
    {
       long long int child=tree[node][i];
        if(child!=par)
        current_gain=current_gain+max_profit(tree,child,node,x);
    }
    return max(current_gain,x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,x;
        cin>>n>>x;
        long long int i;
        for(i=1;i<=n;i++)
            cin>>a[i];
            long long int u,v;
            vector<long long int>tree[n+2];
        for(i=1;i<n;i++)
        {
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        long long ans;
        x=-x;
        ans=max_profit(tree,1,0,x);
        cout<<ans<<endl;

    }
}
