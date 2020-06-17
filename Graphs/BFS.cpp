#include "iostream"
#include<queue>
using namespace std;

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
    cout<<"Required BFS Is Given By "<<endl;
    PrintBFS(edges,V,0,visting);
    


}
