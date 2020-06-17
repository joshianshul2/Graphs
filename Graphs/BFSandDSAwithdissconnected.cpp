#include "iostream"
#include "queue"
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

void PrintBFS(int ** edges,int V,int sv,bool *vistited)
{
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    while(pendingvertex.size()!=0)
    {
        int currvertex=pendingvertex.front();
        cout<<currvertex<<" "<<endl;
        pendingvertex.pop();
        for(int i=0;i<V;i++)
        {
            if(sv==i)
                continue;
        if(edges[currvertex][i]==1 && vistited[i]!=true)
        {
            pendingvertex.push(i);
            vistited[i]=true;
        }
        }
    }
    
}

void BFS(int ** edges,int V)
{
    bool *visting =new bool [V];
       for(int i=0;i<V;i++)
           
       {
           visting[i]=false;
       }
    for(int i=0;i<V;i++)
    {
        if(!visting[i])
        PrintBFS(edges,V,i,visting);
    }
    delete [] visting;
}

void DFS(int ** edges,int V)
{
    bool *visting =new bool [V];
       for(int i=0;i<V;i++)
           
       {
           
           visting[i]=false;
       }
    for(int i=0;i<V;i++)
    {
        if(!visting[i])
        PrintDFS(edges,V,i,visting);
    }
    delete [] visting;
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
    for(int j=0;j<E;j++)
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
   
    cout<<"Required BFS Is Given By "<<endl;
    BFS(edges,V);
    cout<<"Required DFS Is Given By "<<endl;
    DFS(edges,V);
    


}

