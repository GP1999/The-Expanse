/*This program is to check Binary tree is symmetric or not*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node{
int x;
struct node *left,*right;
node(int k){x=k;left=NULL;right=NULL;}
};
void insertNode(int child,string s,Node *root)
{
    Node *ptr=new Node(child);
    Node *temp=root,*pptr;
    for(int i=0;i<s.size();i++)
    {
        pptr=temp;

        if(s[i]=='L')
        {
            temp=temp->left;
        }
        else
            temp=temp->right;

    }
    if(s[s.size()-1]=='L')
        pptr->left=ptr;
    else
        pptr->right=ptr;

}
bool isSymmetric(Node *tree1,Node *tree2)
{
    if(tree1==NULL&&tree2==NULL)
        return true;
    if(tree1==NULL&&tree2!=NULL||tree1!=NULL&&tree2==NULL)
        return false;
    if(tree1->x!=tree2->x)
        return false;
    bool i1=true;
    i1=i1&&isSymmetric(tree1->left,tree2->right);
    bool i2=true;
    i2=i2&&isSymmetric(tree1->right,tree2->left);
    return i1&&i2;

}
bool isSymmetric_iterative(Node *root)
{
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;
    queue<Node*>q;
    Node *tree1,*tree2;
    q.push(root);
    q.push(root);
    while(!q.empty())
    {
        tree1=q.front();
        q.pop();
        tree2=q.front();
        q.pop();
        if(tree1->x!=tree2->x)
            return false;
        if(tree1->left&&tree2->right)
        {
            q.push(tree1->left);
            q.push(tree2->right);
        }
        else if(tree1->left||tree2->right)
            return false;
        if(tree1->right&&tree2->left)
        {
            q.push(tree1->right);
            q.push(tree2->left);
        }
        else if(tree1->right||tree2->left)
            return false;



    }
    return true;
}
int main()
{
    int r;
    cout<<"Enter root node:";
    cin>>r;
    Node *root=new Node(r);
    cout<<"Enter no. of nodes:";
    int n;
    cin>>n;
    cout<<"Enter node values and place(left or right)\n";
    string ch;
    int child;
    for(int i=0;i<n;i++)
    {
        cin>>child>>ch;
        insertNode(child,ch,root);
    }
    bool i= isSymmetric(root,root);
   if(i)
    cout<<"YES\n";
   else
    cout<<"NO\n";

}
