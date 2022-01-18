//
//  1504.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

int N, E;
int a, b, c;
int v1, v2;
vector<Data> v[801];
int cost[801];
int visited[801];
priority_queue<Data> pq;


int travel(int start, int dest){
    cost[start] = 0;
    pq.push(Data(start, 0));
    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.node] == true) continue;
        visited[now.node] = true;
        for(int i=0;i<v[now.node].size();i++){
            Data next = v[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight)
                cost[next.node] = cost[now.node] + next.weight;
            pq.push(Data(next.node, cost[next.node]));
            
        }
    }
    return cost[dest];

}
 
 

void init() {
    for(int i=0;i<=N;i++){
        cost[i] = INF;
        visited[i] = false;
    }
}

int main(){
    scanf("%d %d", &N, &E);
    for(int i=0;i<=N;i++){
        v[i].clear();
        cost[i] = INF;
        visited[i] = false;
    }
    for(int i=1;i<=E;i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }
    
    //시작정점은 1, 종료정점은 N
    scanf("%d %d", &v1, &v2); //v1, v2를 반드시 거쳐야 함
    
    
    int oneTov1 = travel(1, v1);
    init();
    int v1Tov2 = travel(v1, v2);
    init();
    int v2ToN = travel(v2, N);
    init();
    
    int oneTov2 = travel(1, v2);
    init();
    int v1ToN = travel(v1, N);
    
    
    int ans = min(oneTov1+v1Tov2+v2ToN, oneTov2+v1Tov2+v1ToN);
    
    
    
    if(ans >= INF || ans < 0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    
}
