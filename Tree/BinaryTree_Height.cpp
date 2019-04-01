/*Height of binary tree*/
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
int height(Node *root)
{
    if(root==NULL)
        return 0;
    int h1=1+height(root->left);
    int h2=1+height(root->right);
    return max(h1,h2);
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
    int Height=height(root);
     cout<"Height of tree:"<<<Height<<endl;
