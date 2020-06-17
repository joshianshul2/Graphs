#include<iostream>
using namespace std;

void PrintDFS(int **edges,int V,int sv,bool * vistited)
{
   
    cout<<sv<<" "<<endl;
    vistited[sv]=true;
for(int i=0;i<V;i++)
    {
     if(sv== i)
 {
     continue;
 }
    if(edges[sv][i]==1)
    {
        if(vistited[i])
            continue;
        PrintDFS(edges,V,i,vistited);
        
    }
}
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
     cout<<"Required DFS Is Given By "<<endl;
    PrintDFS(edges,V,0,visting);
}
