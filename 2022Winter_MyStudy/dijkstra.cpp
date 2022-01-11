//
//  dijkstra.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

/*
 다익스트라 구현하기
 필요 요소: 구성 요소 저장할 벡터
 벡터에 저장될 노드정보, 간선 정보, pq 오름차순 -> 구조체
 오름차순 정렬할 pq
 노드 개수만큼 dist 배열
 방문 여부 배열
 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 98765432

//노드의 정보를 구조체로 표현
struct Data{
    int node; //노드 번호
    int weight; //노드까지의 간선의 가중치
    Data() {};
    Data(int node, int weight):node(node), weight(weight){};
    bool operator<(const Data d) const{
        return weight>d.weight;
    }
};

vector<Data> v[10]; //다음에 방문할 노드 (현재노드와 연결된 노드들)

int dist[10]; //해당 인덱스(노드)까지의 dist 값 -> 계속해서 업데이트할 예정

bool isVisited[10]; //방문여부를 저장하는 노드

priority_queue<Data> pq;//다음에 방문하게 될 노드

//계속 써야할 변수들이기 때문에 바깥에다가 선언하는게 좋다.
int N, M; //N:노드 개수, M:간선 개수
int a, b, c; //원래 바깥에다 선언하는 게 좋다

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    //초기화 (벡터를 클리어, 초기 최소 방문 거리를 무한대로 설정)
    for(int i=0;i<=N;i++){
        v[i].clear();
        dist[i] = INF;
        isVisited[i] = false;
    }
    
    //연결 정보를 입력받기
    for(int i=0;i<M;i++){
        cin>>a>>b>>c; //a, b: 노드들, c:간선 가중치
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }
    
    //다익스트라에서 시작할 값 지정 (초기값을 0으로 설정)
    dist[1] = 0; //시작하는 노드의 거리를 0으로
    pq.push(Data(1, 0));
    
    //다익스트라는 while문으로 제어 (pq가 빠질때까지, 즉, 모든 노드를 방문할 때까지 while loop
    while(true){
        if(pq.empty()) break;
        
        //pq에서 하나 꺼내기 (now는 지금 방문하는 노드)
        Data now = pq.top();
        pq.pop();
        
        //만약에 방문을 했었으면 스킵, 안했었으면 true로
        if(isVisited[now.node]) continue;
        isVisited[now.node] = true;
        
        //이제 연결된 노드들을 다 방문하기
        for(int i=0; i<v[now.node].size(); i++){
            //다음 방문하게 될 노드 (연결된 노드)
            Data next = v[now.node].at(i);
            
            //dist[now.node]는 현재 노드까지의 최솟값
            //다음 노드까지의 예전에 계산했던 dist보다 현재노드를 거쳐서 가는 경로가 더 작다면, dist[next.node]를 갱신
            if (dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }
    
    for(int i=0;i<=N;i++){
        cout<<"dist "<<i<<" "<<dist[i]<<endl;
    }
    
    return 0;
}
