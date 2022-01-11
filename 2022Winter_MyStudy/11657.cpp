//
//  11657.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

#include <iostream>
using namespace std;

#define INF 9876543210

/*
 벨만포드 알고리즘을 이용해서 푸는 문제
 시간 C가 양수가 아닌 경우가 있음 (0: 순간이동, <0: 시간을 되돌아가는 경우)
 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램 작성
 시간을 무한히 오래 전으로 되돌릴 수 있다면 -1 출력
 (마이너스의 무한 루프에 빠지게 되는 것)
 
 음수간선이 있으면, 계속 뺑뺑 돌 수 있는 상황이 발생할 수 있음 (뭔얘기지)
 
 다익스트라 같은 경우 가중치가 양수여야함.
 -> 양수가 아니어도 나올 수 있지만, 불확실함.
    코딩할 때는 불확실성이 있으면 안되기 때문에, 양수여야 함
 
 */

struct Data {
    int a, b;
    long long c; //long long 하는 이유는 integer 터질 수 있어서
    Data() {};
    Data(int a, int b, long long c) : a(a), b(b), c(c) {};
};

int N, M;
int a, b, c;
long long dist[501]; //각 도시로의 최단경로 저장하는 배열
Data list[6000]; //도시에서 도시로 가는 비용의 정보를 담는 배열
                // 간선 저장하는 것

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //N개 도시, M개 버스
    cin >> N >> M;

    //각각의 연결정보 저장
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        list[i] = Data(a, b, c);
    }
    
    //최단 경로 배열 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    //시작노드에서 최단경로는 0
    dist[1] = 0;

    for (int i = 1; i < N; i++) { // 각 노드마다 돌려
        for (int j = 0; j < M; j++) { //각 간선마다 돌려
            if (dist[list[j].a] == INF) continue;
            //만약에 연결된 간선 중에서 b(도착)까지 dist 배열에 저장되었던 값이, a(출발) dist 배열 값에 a에서 b로 가는 비용 정보 입력받았던 것보다 크다면 갱신
            if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
                dist[list[j].b] = dist[list[j].a] + list[j].c;
            }
        }
    }
    bool isCycle = false;

    //한번 더 돌았을 때 경로가 갱신된다면 음의 사이클이 존재하는 것
    for (int j = 0; j < M; j++) {
        if (dist[list[j].a] == INF) continue;
        
        //갱신된다면
        if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
            isCycle = true;
            break;
        }
    }

    //음의 순환이 존재한다면 -1을 리턴
    if (isCycle) {
        cout << -1 << endl;
    }
    //음의 순환이 없으면 최단 경로 리턴
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << -1 << endl;
            }
            else {
                cout << dist[i] << endl;
            }
        }
    }

    return 0;
}
