#include<bits/stdc++.h>
using namespace std;
int Array[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int No_element,i,sum=0,best=0;
        cin>>No_element;
        for (i=0; i<No_element; i++)
        {
            cin>>Array[i];

        }
                /*   Consider the subproblem of finding the maximum-sum subarray that ends at
        position k. There are two possibilities:
        1. The subarray only contains the element at position k.
        2. The subarray consists of a subarray that ends at position k¡1, followed by
        the element at position k.
        In the latter case, since we want to find a subarray with maximum sum, the
        subarray that ends at position k-1 should also have the maximum sum. Thus,
        we can solve the problem efficiently by calculating the maximum subarray sum
        for each ending position from left to right.*/
        for (i=0; i<No_element; i++)
        {
            sum = max(Array[i], sum+Array[i]);
            best = max(sum, best);
        }
        cout<<best<<endl;
    }
}
