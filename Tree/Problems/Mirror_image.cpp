/*You are given a binary tree rooted at 1. You have to find the mirror image of any node qi about node 1. If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi print it mirror node if it exists else print -1. */

#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node{
int x;
struct node *left,*right;
node(int a){
    x=a;
left=NULL;
right=NULL;
}
};
int mirror(Node *tree1,Node *tree2,int value)
{
    if(tree1==NULL||tree2==NULL)
        return -1;
    if(tree1->x==value)
        return tree2->x;
    if(tree2->x==value)
        return tree1->x;
    int a=mirror(tree1->left,tree2->right,value);
    if(a!=-1)
        return a;
    return mirror(tree1->right,tree2->left,value);
}

int main()
{
    int n,Q,parent,child,i;
    char ch;
    Node *root=new node(1);
    queue<Node*>q;
    Node *temp;
    cin>>n>>Q;
    for(i=1;i<n;i++)
    {
        cin>>parent>>child>>ch;
        Node *ptr = new node(child);
        q.push(root);
        while(!q.empty())
        {
             temp=q.front();
            if(temp->x==parent)
                break;
                q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        if(ch=='L')
            temp->left=ptr;
        else
            temp->right=ptr;
    }
    while(Q--)
    {
        int data;
        cin>>data;
        int p=mirror(root,root,data);
        cout<<p<<endl;
    }
}
