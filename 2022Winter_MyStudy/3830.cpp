//
//  3830.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/12.
//

/*
 union find 문제
 2차원 배열로 무게값을 같이 업데이트해야댐..
 먼소리노;
 
 */

#include <iostream>
#include <vector>
using namespace std;

struct Data{
    int node;
    int weight;
    Data(){};
    Data(int node, int weight):node(node), weight(weight) {};
};

int N, M; //N:샘플의 종류와 개수, M:실험실에서 한 일의 수
char com;
int a, b, w;
Data diff[100001]; //0번째는 union관련, 1번째는 무게관련

/*
 int Find(int x){
     if(parent[x] == x) return x;
     return parent[x] = Find(parent[x]);
 }

 void Union(int x, int y){
     parent[Find(x)] = Find(y);
 }
 */
Data Find(int x){
    if(diff[x].node == x) return Data(x, w);
    return diff[x] = Find(diff[x].node);
}

void Union(int x, int y){
    diff[Find(x).node] = Find(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        cin>>N>>M;
        if(N==0 && M==0) break;
        
        for(int i=0;i<100001;i++){
            diff[i].clear();
        }
        
        for(int i=0;i<M;i++){
            cin>>com;
            
            //상근이가 무게를 잼: b가 a보다 w만큼 무겁다
            if(com=='!'){
                cin>>a>>b>>w;
                diff[0][a] = b;
                diff[1][a] = w;
                
                // union find해야됨
                
            }
            //교수님이 물어봄:b가 a보다 무겁냐
            else if(com=='?'){
                cin>>a>>b;
            }
        }
        
    }
    
}
