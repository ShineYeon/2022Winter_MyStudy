//
//  1916.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/17.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

struct Data{
    int node;
    int weight;
    Data() {};
    Data(int node, int weight):node(node), weight(weight){};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
};

int N, M; //N:도시 개수, M:버스 개수
vector<Data> d[1001];
int a, b, c;
priority_queue<Data> pq;
int start, dest;
int cost[1001];
bool visited[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0;i<=N;i++){
        d[i].clear();
        visited[i] = false;
        cost[i] = INF;
    }
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        d[a].push_back(Data(b, c));
    }
    cin>>start>>dest;
    
    pq.push(Data(start, 0));
    cost[start] = 0;
    
    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.node]) continue;
        visited[now.node] = true;
        for(int i=0;i<d[now.node].size();i++){
            Data next = d[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight)
                cost[next.node] = cost[now.node] + next.weight;
            pq.push(Data(next.node, cost[next.node]));
            
        }
    }
    
    cout<<cost[dest]<<endl;
    
    
}
