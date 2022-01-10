//
//  1922.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/10.
//

#include <iostream>
#include <queue>
using namespace std;
//크루스칼 구현

int N, M; //N:컴퓨터(노드) 수, M:선(간선) 수
int a, b, c;
int parent[1001];

struct Data{
    int node1, node2, weight;
    Data() {};
    Data(int node1, int node2, int weight): node1(node1), node2(node2), weight(weight) {};
    
    //priority queue를 어떻게 할 것인지 선언한 부분
    bool operator<(const Data d) const{
        return weight > d.weight;
        //낮은게 먼저 산출될 수 있도록 pq 정렬 방식을 저장
    }
};


int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    parent[Find(x)] = Find(y);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M;
    int count, answer;
    priority_queue<Data> pq;
    
    for(int i=0;i<=N;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        pq.push(Data(a, b, c));
    }
    
    count=0;
    answer = 0;
    while(true){
        //모든 노드들이 연결되는 경우는 없다라서 count로 조건 거는게 가능,
        //아니라면 pq로 조건걸어야 됨 (계속해서 pop해와서)
        if(count == (N-1)) break;
        Data d = pq.top(); //맨위에껄 pop해와서
        pq.pop();
        if(Find(d.node1)!=Find(d.node2)){ //node1과 node2의 부모노드가 연결되어있는게 아니라면 연결처리
            Union(d.node1, d.node2);
            count++;
            answer += d.weight;
        }
    }
    printf("%d\n", answer);
    return 0;
    
}
