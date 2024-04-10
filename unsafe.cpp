#include<iostream>
using namespace std;
int main()
{

    int i,j,m,n;

    cout<<"Enter number of process :\n ";
    cin>>n;
    cout<< "enter number of resources :\n ";
    cin>>m;

    int alloc[n][m];
    cout<<"Enter allocation matrix \n ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>alloc[i][j];
        }
    }

    int max[n][m];
    cout<<"Enter max matrix :\n  ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>max[i][j];
        }
    }

    int avail[m];

    cout<<"available resource: \n";
    for(j=0; j<m; j++)
    {
        cin>>  avail[j];

    }

    int need[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            //cout<< need[i][j]<< " " ;
        }

    }
    int f[n];
    int s[n];


    for (i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            f[i]=0;
        }
    }

    int c=0;
    int flag=1 ;

    while(c!=n)
    {
        int safe_state=0;
        for(i=0; i<n; i++)
        {
            if(f[i]==0)
            {
                flag=1 ;
                for(j=0; j<m; j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {

                    f[i]=1;
                    s[c++]=i;
                    for(int k=0; k<n; k++)
                    {
                        avail[k]+=alloc[i][k];
                    }
                    safe_state=1;
                    flag=1;
                }
            }
        }
        if(safe_state==0){
            cout<<"Unsafe \n" ;
            return 0;
        }
    }

    cout<<"Safe Sequence : \n";
    for(i=0; i<n; i++)
    {

        cout<<"p" << s[i]<< " ";
    }
}
