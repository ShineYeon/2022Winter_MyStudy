//
//  1753.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int V, E, K; // V:정점개수, E:간선개수, K:시작정점번호
int a, b, c; // a에서 b로 가는 가중치 c의 간선이 존재함

struct Data {
    int node;
    int weight;
    Data() {};
    Data(int node, int weight): node(node), weight(weight) {};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
};

vector<Data> v[20001];
priority_queue<Data> pq;
bool visited[20001];
int dist[20001];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E;
    for(int i=0;i<=V;i++){
        v[i].clear();
        visited[i] = false;
        dist[i] = INF;
    }
    
    cin>>K;
    
    dist[K]=0;
    pq.push(Data(K, 0));
    
    //vector 정보 입력받기.
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        v[a].push_back(Data(b, c));
    }
    
    while(!pq.empty()) {
        
        Data now = pq.top();
        pq.pop();
        
        if(visited[now.node] == true) continue;
        visited[now.node] = true;
        
        for(int i=0;i<v[now.node].size();i++){
            Data next = v[now.node][i];
            if(dist[next.node]>dist[now.node] + next.weight){
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
        
    }
    
    for(int i=1;i<=V;i++){
        if(dist[i] == INF)
            cout<<"INF"<<endl;
        else
            cout<<dist[i]<<endl;
    }
    return 0;
    
}
