//
//  1967.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/20.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

struct Data{
    int node;
    int weight;
    Data(){};
    Data(int node, int weight):node(node), weight(weight){};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
};

int n;
int a, b, c;
bool visited[1001];
vector<Data> v[1001];
int cost[1001];
priority_queue<Data> pq;


int bfs(int x){
    int ret = 0;
    pq.push(Data(x, 0));
    cost[x] = 0;
    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.node]) continue;
        visited[now.node] = true;
        for(int i=0;i<v[now.node].size();i++){
            Data next = v[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight)
                cost[next.node] = cost[now.node] + next.weight;
            if(ret < cost[next.node])
                ret = cost[next.node];
            pq.push(Data(next.node, cost[next.node]));
        }
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        v[i].clear();
        visited[i] = false;
        cost[i] = INF;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }
    
    int ret = 0;
    for(int i=1;i<=n;i++){
        if(ret < bfs(i))
            ret = bfs(i);
    }
    
    cout<<ret<<endl;
    
}
