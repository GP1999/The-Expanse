/*This program is of spiral pattern like
1  2  3  4
12 13 14 5
11 16 15 6
10  9 8  7

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1][n+1];
    int r,cnt=0,total=1;
    int i,j=1,k=1;
    while(k<(n*n)+1)
    {
        if(total%4==1)
        {
            for(i=cnt+1;i<=n-cnt;i++)
            {
                a[j][i]=k++;
            }
            r=j;
            j=n-cnt;
            total++;

        }
        else if(total%4==2)
        {
            for(i=r+1;i<=n-cnt;i++)
            {
                a[i][j]=k++;
            }
            j=n-cnt;
            total++;

        }
        else if(total%4==3)
        {

            for(i=n-cnt-1;i>=cnt+1;i--)
            {
                a[j][i]=k++;

            }
            j=cnt+1;
            total++;
        }
        else
        {
            for(i=n-cnt-1;i>=cnt+2;i--)
            {
                a[i][j]=k++;
            }
            j=cnt+2;
            cnt++;
            total++;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
