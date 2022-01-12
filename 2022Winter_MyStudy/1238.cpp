//
//  1238.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/12.
//

/*
 플로이드와샬 -> 통과됨..!!
 플로이드 완전 자명함.
 
 어떻게 다익스트라?
 다익스트라를 n번? 그래도 통과되긴해
 솔루션 -> 그래프와 트랜스포스한 그래프로 다익스트라 2번 돌리기
 (입력을 받을 때 반대 방향으로도 추가)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

struct Data{
    int n;
    int w;
    Data() {};
    Data(int n, int w):n(n), w(w) {};
    bool operator<(const Data d)const{
        return w > d.w;
    }
};
int N, M, X;
int a, b, c;
vector<Data> v[1001];
vector<Data> tv[1001];
priority_queue<Data> pq;
int Goingcost[1001];
int Comingcost[1001];
bool visited[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>X;
    
    for(int i=0;i<=N;i++){
        Goingcost[i] = INF;
        Comingcost[i]=INF;
        visited[i] = false;
        v[i].clear();
        tv[i].clear();
    }
    
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        v[a].push_back(Data(b, c));
        tv[b].push_back(Data(a, c));
    }
    
    //출발점
    pq.push(Data(X, 0));
    Goingcost[X] = 0;
    
    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.n]) continue;
        visited[now.n] = true;
        for(int i=0;i<v[now.n].size();i++){
            Data next = v[now.n].at(i);
            if(Goingcost[next.n] > Goingcost[now.n] + next.w){
                Goingcost[next.n] = Goingcost[now.n] + next.w;
                pq.push(Data(next.n, Goingcost[next.n]));
            }
        }
    }
    
    for(int i=0; i<=N;i++){
        visited[i] = false;
    }
    
    Comingcost[X] = 0;
    pq.push(Data(X, 0));
    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.n]) continue;
        visited[now.n] = true;
        for(int i=0;i<tv[now.n].size();i++){
            Data next = tv[now.n].at(i);
            if(Comingcost[next.n] > Comingcost[now.n]+next.w){
                Comingcost[next.n] = Comingcost[now.n]+next.w;
                pq.push(Data(next.n, Comingcost[next.n]));
            }
        }
    }
    
    int max=0;
    for(int i=1;i<=N;i++){
        if(max < Goingcost[i] + Comingcost[i])
            max = Goingcost[i] + Comingcost[i];
        
    }
    
    cout<<max<<endl;
    
    
}
