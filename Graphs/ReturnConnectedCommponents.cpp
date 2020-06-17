#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void connected(bool** edges, int n, int sv, bool *visited)
{
    int init=sv;
   // for same components Times
    while(init<n){
    if(visited[init]!= false){
        init++;
        continue;
    }
    visited[init] = true;
    queue<int> q;
    q.push(init);
    init++;
        vector<int> v1;
    while(!q.empty())
    {
        int x = q.front();
        v1.push_back(x);
        
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(edges[x][i] && !visited[i] )
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
        sort(v1.begin(), v1.end());
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    
    return;
   
}
int main()
{
    int V, E;
    cin >> V >> E;
    
    bool** edges = new bool*[V];
    for(int i=0; i<V; i++){
        edges[i]=new bool[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f;
        cin>>s;
        
        edges[f][s]=1;
        edges[s][f]=1;
        
        
    }

    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    
    connected(edges, V, 0 , visited);

  return 0;
}
