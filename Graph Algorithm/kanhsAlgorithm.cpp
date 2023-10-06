#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class graph{
public:

void  kanhsAlgo(unordered_map<int,list<int>>&adj, int n)
    {
        // Here concept of indegree used
        // as it represents number of incoming
        // edges on a node
        vector<int> indegree(n, 0);
        // Code for make indegree
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
 
        vector<int> ans;
        queue<int> qrr;
        // Initially insert elements who has
        // indegree 0
        for (int i = 0; i < n; i++) {
 
            if (indegree[i] == 0) {
                qrr.push(i);
            }
        }
 
        while (!qrr.empty()) {
            // push those elements in queue which
            // poses 0 indegree
            int node = qrr.front();
 
            qrr.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qrr.push(it);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
    }




};
void addEdge(unordered_map<int,list<int>>adj,int u,int v,bool direction){
    // direction==0 -> undirected
    // direction==1 -> directed
    adj[u].push_back(v);
    if(direction==0){
        adj[v].push_back(u);
    }

}

 
int main(){
    unordered_map<int,list<int>>adj;
    graph g;
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
   
 
    addEdge(adj, 5, 0,1);
    addEdge(adj, 5, 2,1);
    addEdge(adj, 2, 0,1);
    addEdge(adj, 2, 3,1);
    addEdge(adj, 3, 0,1);
    addEdge(adj, 3, 1,1);
    addEdge(adj, 1, 0,1);
    addEdge(adj, 4, 0,1);
    addEdge(adj, 4, 1,1);
   
   
    g.kanhsAlgo(adj,n);
   
   return 0;
}