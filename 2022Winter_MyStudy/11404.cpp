//
//  11404.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

#include <iostream>
#include <vector>
using namespace std;

#define INF 98765432

/*
 플로이드 와샬 알고리즘 이용하기
 모든 도시의 쌍(A, B)에서, 도시 A에서 B로 가는데 필요한 최소 비용 계산하기
 */

int n, m; //n개 도시(노드), m개 버스(간선)
int a, b, c;

struct Data{
    int node; //도시 번호
    int weight; //간선 비용
    Data() {};
    Data(int node, int weight) :node(node), weight(weight) {};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
};

int cost[101][101]; //비용 정보


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    
    //cost 정보 초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cost[i][j] = INF;
        }
    }
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(cost[a][b] > c)
            cost[a][b] = c;
    }
    
    
    
    for(int k=1; k<=n; k++){ //경유하는 부분을 맨 위로 뺀다
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(cost[i][k] == INF ||cost[k][j] == INF) continue;
                if(cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cost[i][j] == INF)
                cout<<"0 ";
            else
                cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
