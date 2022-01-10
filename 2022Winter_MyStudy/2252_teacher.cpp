//
//  2252_teacher.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/10.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring> //초기화할때 사용 (memset)
using namespace std;

int N, M;
int a, b;
int indegree[32001];

int main(){
    vector<int> v[32001];
    queue<int> q;
    queue<int> answer;
    
    cin>>N>>M;
    
    //memset은 0으로 초기화하는데 사용함. 0이 아니면 오류날 수 있음
    memset(indegree, 0, (sizeof(indegree)));
    
    for(int i=0;i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }
    
    for(int i=1;i<=N;i++){
        if(indegree[i] == 0){
            answer.push(i);
            q.push(i);
        }
    }
    
    while(true){
        if(q.empty()) break;
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            indegree[v[x].at(i)]--;
            if(indegree[v[x].at(i)] == 0){
                q.push(v[x].at(i));
                answer.push(v[x].at(i));
            }
        }
    }
    
    while(true){
        if(answer.empty()) break;
        printf("%d ", answer.front());
        answer.pop();
    }
    return 0;
    
}
