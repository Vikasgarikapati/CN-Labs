#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of hosts :";
    cin>>n;
    vector<vector<int>> adjacencygraph(n);
    int through[n][n],share[n][n][n];
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            through[i][j]=-1;
        }
    }
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                adjacencygraph[i][j]=0;
            }
            else
            {
                cout<<"\n Enter Distance between hosts"<<i+1<<" and "<<j+1<<" : ";
                int t;
                cin>>t;
                adjacencygraph[i][j]=adjacencygraph[j][i]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                if((adjacencygraph[i][j]>-1)&&(adjacencygraph[j][k]>-1))
                {
                    share[i][j][k]=adjacencygraph[j][k]+adjacencygraph[i][j];
                }
                else
                {
                    share[i][j][k]=-1;
                }
            }
        }
    }
    cout<<"\n The data you have entered is :\n";
    for (int i=0;i<n;i++)
    {
        cout<<" At host "<<i+1<<endl;
        cout<<"Host\tDistance\tthrough\n";
        for(int j=0;j<n;j++)
        {
            cout<<j+1<<"\t"<<adjacencygraph[i][j]<<"\t"<<through[i][j]<<endl;
        }
    }
    cout<<"The shared data is :\n";
    for(int i=0;i<n;i++)
    {
        cout<<" For host "<<i+1<<endl;
        for (int j=0;j<n;j++)
        {
            cout<<" From host "<<j+1;
            for(int k=0;k<n;k++)
            {
                cout<<k+1<<" "<<share[i][j][k]<<endl;
            }
        }
    }
    int store[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            store[i][j]=adjacencygraph[i][j];
            through[i][j]=i;
            for(int k=0;k<n;k++)
            {
                if((store[i][j]>share[i][k][j])||(store[i][j]==-1))
                {
                    if(share[i][k][j]>-1)
                    {
                        store[i][j]=share[i][k][j];
                        through[i][j]=k;
                    }
                }
            }
            if(store[i][j]==-1)
            {
                for(int k=0;k<n;k++)
                {
                    if((store[i][k]!=-1)&&(store[k][j]!=-1))
                    {
                        if((store[i][j]==-1) || ((store[i][j]!=-1) &&(store[i][j]>store[i][k]+store[k][j]))) 
                        {
                            if(store[i][k]+store[k][j]>-1)
                            {
                                store[i][j]=store[i][k]+store[k][j];
                                through[i][j]=k;
                            }
                        }
                    }
                     
                }
            }
        }
    }
    cout<<" The final table is :"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<" At host "<<i+1<<endl;
        cout<<"Host\tDistance\tthrough\n";
        for(int j=0;j<n;j++)
        {
            cout<<j+1<<"\t"<<store[i][j]<<"\t";
            if(i==through[i][j])
            {
                cout<<"-"<<endl;
            }
            else
            {
                cout<<through[i][j]+1<<endl;
            }
        }
    }
    return 0;
}