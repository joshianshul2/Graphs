#include<iostream>
#include<vector>
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

vector<int> *DFSPath(vector<int> *p,int ** edges,int V,int a,int b,bool * vistited)
{

    if(a==b)
    {
        p->push_back(a);
        return p;
    }
    vistited[a]=true;
    for(int i=0;i<V;i++)
    {
        if(edges[a][i]==1 && vistited[i]!= true)
        {
            vector<int>* q;
            q=DFSPath(p,edges,V, i,b, vistited);
            if(q!= NULL)
            {
                q->push_back(a);
                return q;
            }
                
        }
    }
   return NULL;
        
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
    vector<int> *p =new vector<int>();
    cout<<"Required DFS Path Is Given By "<<endl;
    vector<int>*output = DFSPath(p,edges,V, a, b, visting);
    if(output!= NULL)
    {
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" "<<endl;
        }
    }
}

