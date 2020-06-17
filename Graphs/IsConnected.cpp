#include<iostream>
#include<vector>
using namespace std;

void IsConnected(int **edges,int V,int a,bool * vistited)
{
vistited[a]=true;
for(int i=0;i<V;i++)
    {
     if(a== i)
 {
     continue;
 }
    if(edges[a][i]==1  && vistited[i]!=true)
    {
        IsConnected(edges,V,i,vistited);

    }
}
    return ;
}

int main()
{
    int V,E;
    //cout<<"Enter a Vertices And Edges "<<endl;
    cin>>V>>E;
    int ** edges =new int *[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int [V];
    for(int j=0;j<V;j++)
    {
        edges[i][j]=0;
    }
       }
    for(int i=0;i<E;i++)
    {
        int f,s;
        //cout<<"Enter a  First And Second Edges "<<endl;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visting =new bool [V];
    for(int i=0;i<V;i++)
        
    {
        visting[i]=false;
    }
    
    IsConnected(edges,V,0,visting);
    for (int i = 0; i < V; i++)
    {
        if (visting[i] == 0)
        {
            cout << "false" << '\n';
            return 0;
        }

    }
    cout << "true" << '\n';
    

    return 0 ;
}


