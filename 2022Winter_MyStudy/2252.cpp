//
//  2252.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, M; //N:전체학생수, M:키를비교한학생수
int parent[32001];
vector<vector<int>> vvi(100001);

int main(){
    int a, b;
    int i=0;
    queue<int> start;
    int ans[32001];
    scanf("%d %d", &N, &M);
    
    //벡터 안에다가 넣기
    vector<int> vi(32001);
    for(int i=0;i<=N;i++){
        vi.push_back(i);
    }
    vvi.push_back(vi);
    
    for(int i=0;i<M;i++){
        scanf(" %d %d", &a, &b); //학생 a가 b앞에 서야한다.
        parent[b]++;
        vvi[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        if(parent[i] == 0)
            start.push(i);
    }
    
    while(!start.empty()){
        int top = start.front();
        start.pop();
        
        if(parent[top] == 0) //자기자신으로 향하는 노드가 하나도 없을때
            start.push(top);
        else{
            if((--parent[top]) == 0){
                start.push(top);
                ans[i] = top;
                i++;
            }
            
        }
    }
    
    for(auto i:ans)
        printf("%d ", i);
    printf("\n");
}
