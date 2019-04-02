/*This program is to construct binary tree from inorder and postorder input*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef struct node Node;
struct node{
int val;
struct node *left,*right;
node(int a){val=a;left=right=NULL;}
};
Node* BuildTree(unordered_map<int,int> &mp, vector<int> &postorder, int start, int End, int *pindex)
{
    if(End<start)
        return NULL;
    int curr=postorder[*pindex];
    int index=mp[curr];
    Node *node=new Node(curr);
    --(*pindex);
    if(End==start)
        return node;
    node->right=BuildTree(mp,postorder,index+1,End,pindex);
    node->left=BuildTree(mp,postorder,start,index-1,pindex);
    return node;
}

int main()
{
    int n;
    cout<<"Enter No. of Nodes:";
    cin>>n;
    vector<int>inorder;
    unordered_map<int,int>m;
    vector<int>postorder;
    int i,j,k;
    for(i=0;i<n;i++)
        {cin>>k;m[k]=i;}
    for(i=0;i<n;i++)
        {cin>>k;postorder.push_back(k);}
    Node *root;
    int p=n-1;
    root=BuildTree(m,postorder,0,n-1,&p);
}
