//
//  1854.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/12.
//

/*
 1번에서 i번째 도시로 가는 k번째 최단 경로의 소요시간
 
 아이디어 힌트:
 다익스트라에 필요 구조: visit노드, 최단경로비용노드, priority queue
 근데 이건 몇번째 최단경로가 아니라, 그냥 최단 경로만을 저장한 것
 그래서 최단 경로가 아닌 것들은 뺐음
 
 이제 원하는건 k번째 최단경로임
 따라서 다른 거리의 경로를 저장할 필요가 있다
 그러면 배열에서도, 여러가지를 저장해야됨
 벡터나 큐, 아니면 다른 자료구조가 추가적으로 필요함
 
 해당 노드까지 가는데 필요한 경로를 다 저장함
 (정점에 들어오는 데 필요한 시간들을 일단 다 저장)
 
 어떤 값을 저장해야 하는가..
 k개 값을 저장하면 됨
 
 그러면 어떤 자료구조를 각각의 노드마다 저장하면 좋을까?
 값이 들어올때마다 정렬해서 가장 작은 값부터 순서대로 꺼내는 자료구조인 우선순위큐
 최소 거리를 저장하는 pq배열을 만들고
 일단 다 가보면서 해당 노드에서, pq사이즈를 파악함
 값이 만약 k개가 안도착해있으면 일단 넣어줌
 
 pq가 이미 k개 차 있으면?
 pq에서 가장 위에 있는 값이 거기로의 가장 짧은 거리
 
 우선순위 큐 배열을 생성해서 우선순위 큐를 각 정점마다 하나씩 가지도록함,
 해당 정점을 방문할 때마다 그때의 dist를 우선순위 큐에 push
 만약 해당 정점의 우선순위큐의 크기가 K개 이하인 경우
 -> 소요시간을 정점의 우선순위 큐에 push하고, 다익스트라를 진행하는 전체 우선순위 큐에도 push
 해당 정점의 우선순위큐의 크기가 K개인 경우
 -> 정점들의 우선순위 큐는 다익스트라의 pq와 다르게 내림차순으로 즉, 큰 수가 top에 오도록 구성해야함. 만약 새로 구한 정점으로의 소요시간(next_cost)이 해당정점의 pq의 top보다 작다면 top의 수는 K번째 최단 경로가 될 수 없다. 따라서 top을 pop하고, next_cost를 push한다.
 그 후 next_cost를 다익스트라의 pq에 push해서 해당 경로에서 다른 경로로 갈 수 있도록 함.
 
 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define INF 98765432

struct Data{
    int node;
    long long weight;
    Data() {};
    Data(int node, long long weight): node(node), weight(weight){};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
    
};


int n, m, k; //n:도시 개수, m:도로개수
int a, b, c;
vector<Data> v[1001];
int cost[1001];
bool visited[1001];
priority_queue<long long> distpq[1001];
priority_queue<Data> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    
    for(int i=0;i<=n;i++){
        v[i].clear();
        cost[i] = INF;
        visited[i] = false;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back(Data(b, c));
    }
    
    cost[1] = 0;
    pq.push(Data(1, 0));
    distpq[1].push(0);
    
    int next, now;
    long long nextCost, cost;
    while (true) {
        if (pq.empty()) break;
        now = pq.top().node;
        cost = pq.top().weight;
        pq.pop();

        for(int i=0; i<v[now].size() ; ++i){
            next = v[now].at(i).node;
            nextCost = cost + v[now].at(i).weight;
              if(distpq[next].size() <k){
                distpq[next].push(nextCost);
                pq.push(Data(next, nextCost));
              }else if(distpq[next].top() > nextCost){  //K개가 우선순위 큐에 존재 하지만 next_cost가 top보다 작은 경우
                distpq[next].pop();
                distpq[next].push(nextCost);
                pq.push(Data(next, nextCost));
              }
              
            }
        
    }
    
    vector<int> ret(n+1, -1);
    for(int i=1;i<=n;i++){
        if(distpq[i].size() == k)
            ret[i] = distpq[i].top();
    }
    for(int i=1;i<=n;i++){
        cout<<ret[i]<<endl;
    }
}
