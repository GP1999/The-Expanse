/*There is a complete Binary tree in which there are N nodes. Each vertex of the tree is assigned a value.

You are given the values of all nodes in level order traversal of the binary tree (from left to right).

You are given three types of queries.

1 X  LV  Find the value of Xth node from left on the level LV.

2  L R  Find the the sum of values of nodes from level L to R (L and R are inclusive). 

3  X  LV  VAL Update the value of Xth node from left which is at level LV to VAL. 

Note: Root is at level 1.*/
#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int no_nodes,no_query,i,j,k;
    cin>>no_nodes>>no_query;
    for(i=0;i<no_nodes;i++)
     cin>>a[i];
    int total_level;
    total_level=(log(no_nodes)/log(2))+1;
    long long int sum[total_level],cnt=0;
    for(i=1;i<=total_level;i++)
    {
        cnt=0;
        for(j=pow(2,i-1)-1;j<pow(2,i)-1;j++)
            cnt+=a[j];
        sum[i]=cnt;
    }
     while(no_query--)
     {
         int type, x_node,level,level_L,level_R,value,index;
         cin>>type;
         if(type==1)
         {
             cin>>x_node>>level;
              index=pow(2,level-1)+x_node-2;
             cout<<a[index]<<endl;
         }
         else if(type==2)
         {
             long long int ans=0;
             cin>>level_L>>level_R;
             for(i=level_L;i<=level_R;i++)
             {
                 ans+=sum[i];

             }
             cout<<ans<<endl;
         }
         else
         {
             cin>>x_node>>level>>value;
             index=pow(2,level-1)-2+x_node;
              sum[level]+=(value-a[index]);
             a[index]=value;
         }
     }

    return 0;

}
