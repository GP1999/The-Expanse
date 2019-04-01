/*This program is having both iterative and recursive traversal of Binary tree*/

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
void preorder_recursive(Node *root)
{
    if(root==NULL)
        return;
    else
    {
        cout<<root->x<<" ";
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}
void preorder_iterative(Node *root)
{
    Node *temp;
    vector<int>v;
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->x<<" ";
        v.push_back(temp->x);
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }


}
void inorder_recursive(Node *root)
{
    if(root==NULL)
        return;
    inorder_recursive(root->left);
    cout<<root->x<<" ";
    inorder_recursive(root->right);
}
void inorder_iterative(Node *root)
{


    stack<Node*>s;
    Node *curr=root;
    while(curr!=NULL||!s.empty())
    {
       while(curr!=NULL)
       {
           s.push(curr);
           curr=curr->left;
       }

       curr=s.top();
       s.pop();
       cout<<curr->x<<" ";
       curr=curr->right;

    }
}
void postorder_recursive(Node *root)
{
    if(root==NULL)
        return;
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        cout<<root->x<<" ";
}
void postorder_iterative(Node *root)
{
    stack<Node*>s1;
    stack<Node*>s2;
    Node *temp;
     s1.push(root);
     while(!s1.empty())
     {
         temp=s1.top();
         s1.pop();
         s2.push(temp);
         if(temp->left)
            s1.push(temp->left);
         if(temp->right)
            s1.push(temp->right);
     }
     while(!s2.empty())
     {
         cout<<s2.top()->x<<" ";
         s2.pop();
     }

}
void level_order(Node *root)
{
    queue<Node*>q;
    vector<int>v;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        v.push_back(temp->x);
        cout<<temp->x<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

    }
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
    preorder_recursive(root);
    cout<<endl;
    preorder_iterative(root);
    cout<<endl;
    inorder_recursive(root);
    cout<<endl;
    inorder_iterative(root);
    cout<<endl;
    postorder_recursive(root);
    cout<<endl;
    postorder_iterative(root);
    cout<<endl;
    level_order(root);
}
