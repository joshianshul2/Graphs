#include<iostream>
using namespace std;

bool HasPath(int **edges,int V,int a,int b,bool * vistited)
{
    if(edges[a][b]==1)
        return true;
   vistited[a]=true;
for(int i=0;i<V;i++)
    {
     if(a== i)
     continue;
    if(edges[a][i]==1 && vistited[i]!= true)
    {
        bool ans=HasPath(edges,V,i,b,vistited);
        if(ans)
            return true;
    }
}
    return false;
}

int main()
{
    int V,E;
    cout<<"Enter a Vertices And Edges "<<endl;
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
        cout<<"Enter a  First And Second Edges "<<endl;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visting =new bool [V];
    for(int i=0;i<V;i++)
        
    {
        visting[i]=false;
    }
    int a,b;
    cout<<"Enter the Required Path a and b "<<endl;
    cin>>a>>b;
    bool p=HasPath(edges, V, a, b, visting);
    if(p)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
