//
//  boj2960.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/09.
//

#include <iostream>
using namespace std;
#define MAXN 1001

int N, K;
bool visit[MAXN];


int main() {
    cin>>N>>K;
    int cnt = 0;
    
    for(int i=2;i<=N;i++){
        if(visit[i])
            continue;
        for(int j=i;j<=N;j+=i){
            if(!visit[j]){
                if(++cnt==K){
                    printf("%d\n", j);
                    return 0;
                }
                visit[j] = true;
            }
        }
    }

}
