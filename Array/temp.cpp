#include<bits/stdc++.h>
using namespace std;
typedef long long int  lli;
pair<lli,lli> distance(pair<lli,lli>p[],lli x,lli y,lli n,double *q)
{
    double temp,mindist=9999999999.0;
    pair<lli,lli>minpair;

    for(lli i=0;i<n;i++)
    {
        temp=sqrt((((x-p[i].first)*(x-p[i].first))+((y-p[i].second)*(y-p[i].second))));
       // printf("%.10f\n",mindist);
        //printf("%.10f \t %.10f\n",temp,mindist);
        if(temp<mindist)
        {
            minpair=p[i];
            mindist=temp;
        }
        //cout<<p[i].first<<" "<<p[i].second<<" "<<temp<< " "<<mindist<<endl;
        //printf("%.10f\n",mindist);

    }
    *q=mindist;
    return minpair;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        lli x,y;
        cin>>x>>y;
       lli n,m,k;
        cin>>n>>m>>k;
        pair<lli,lli>setA[n+1];
        pair<lli,lli>setB[m+1];
        pair<lli,lli>setC[k+1];
        lli p1,p2;
        for(lli i=0;i<n;i++)
        {
            cin>>p1>>p2;
            setA[i]=make_pair(p1,p2);
        }
        for(lli i=0;i<m;i++)
        {
            cin>>p1>>p2;
            setB[i]=make_pair(p1,p2);
        }
        for(lli i=0;i<k;i++)
        {
            cin>>p1>>p2;
            setC[i]=make_pair(p1,p2);
        }
        double mindistAP,mindistBP,mindistAB,mindistBA,mindistAC,mindistBC,mindistPC,mindistPBC,mindistPAC,distBP,distAP;
        pair<lli,lli>minAP,minBP,minAB,minBA,minAC,minBC,minPC,minPBC,minPAC;
        minAP=distance(setA,x,y,n,&mindistAP);//d1
        minBP=distance(setB,x,y,m,&mindistBP);//d_1
        minAB=distance(setB,minAP.first,minAP.second,m,&mindistAB);//d2
        minBA=distance(setA,minBP.first,minBP.second,n,&mindistBA);//d_2
        minAC=distance(setC,minBA.first,minBA.second,k,&mindistAC);//d_3
        minBC=distance(setC,minAB.first,minAB.second,k,&mindistBC);//d3

        minPC=distance(setC,x,y,k,&mindistPC);
        minPBC=distance(setC,minBP.first,minBP.second,k,&mindistPBC);
        minPAC=distance(setC,minAP.first,minAP.second,k,&mindistPAC);
        distAP=sqrt((((x-minBA.first)*(x-minBA.first))+((y-minBA.second)*(y-minBA.second))));
        distBP=sqrt((((x-minAB.first)*(x-minAB.first))+((y-minAB.second)*(y-minAB.second))));
        double ans[11],org=9999999999.0;
         ans[0]=mindistAP+mindistAB+mindistBC;
         ans[1]=mindistBP+mindistBA+mindistAC;
        ans[2]=2*mindistAP+mindistBP+mindistPBC;
        ans[3]=2*mindistBP+mindistAP+mindistPAC;
        ans[4]=2*(mindistBP+mindistAP)+mindistPC;
        ans[5]=mindistAP+mindistAB+distBP+mindistPC;
        ans[6]=mindistBP+mindistBA+distAP+mindistPC;
        ans[7]=mindistBP+2*mindistBA+mindistBC;
        ans[8]=mindistAP+2*mindistAB+mindistAC;
        ans[9]=2*mindistBP+mindistAP+mindistAB+mindistBC;
        ans[10]=2*mindistAP+mindistBP+mindistBA+mindistAC;
        /*cout<<minAP.first<<" "<<minAP.second<<":d1\n";
        cout<<minAB.first<<" "<<minAB.second<<":d2\n";
        cout<<minBC.first<<" "<<minBC.second<<":d3\n";
        cout<<minBP.first<<" "<<minBP.second<<":d_1\n";
        cout<<minBA.first<<" "<<minBA.second<<":d_2\n";
        cout<<minAC.first<<" "<<minAC.second<<":d_3\n";*/
        for(int i=0;i<11;i++)
        {
            if(org>ans[i])
                org=ans[i];
        }
        printf("%.10f\n",org);


    }
}
