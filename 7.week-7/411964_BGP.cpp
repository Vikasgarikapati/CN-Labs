#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of hosts :";
    cin>>n;
    int initial[n][n],route[n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<"Enter the distance between the hosts "<< i + 1<<" and " <<j + 1<<" :";
            cin>>initial[i][j];
        }
    }
    cout<<"The distance matrix of the hosts you have entered is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<" "<<initial[i][j];
        }
        cout<<endl;
    }
    for(int z=0;z<n;z++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((initial[i][z]+initial[z][j])<initial[i][j])
                {
                    initial[i][j]=initial[i][z]+initial[z][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                route[i][j] = 0;
            }
            else
            {
                route[i][j]=initial[i][j];
            }
        }
    }
    cout<<"The final matrix of hosts after routing is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<" "<<route[i][j];
        }
        cout<<endl;
    }
    return 0;
}