//
//  10830.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/19.
//

#include <iostream>
#include <cstring>
using namespace std;

int N;
long long B, half;
/*
 arr이 행렬제곱한 결과를 담는 배열이고
 component는 원래 입력받았던 배열이다.
 */

//일단 행렬을 두개 만들고, 곱해서 하나의 행렬에 넣기. (오리지널 행렬은 하나 남겨둠)
long long component[7][7];
long long arr[7][7];
long long mod = 1000;

//행렬곱하기
void squared(long long a[][7], long long b[][7]) {
    //임시로 담을 배열 선언 후 초기화
    long long tmp[7][7];
    memset(tmp, 0, sizeof(tmp));
    for(long long i=0; i<N; i++){
        for(long long j=0; j<N; j++){
            for(long long k=0; k<N; k++){
                //행렬곱 코드가 좀 어렵다.
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] = tmp[i][j] % mod;
            }
        }
    }
    memcpy(arr, tmp, sizeof(arr)); //arr배열에는 계속해서 곱한 수가 저장이 되는 상황
}

void solve(long long x){
    if(x==1) return;
    else if(x%2 == 1){
        solve(x/2); // 홀수일 경우 쪼개서,
        squared(arr, arr); //arr과 arr을 행렬곱하고
        squared(arr, component); //다시한번 arr 행렬곱
        //arr은 계속해서 곱한 수가 저장이 되는 상황이고, component는 새로운 배열임.
    }
    else{
        solve(x/2); //짝수일 경우 쪼개서
        squared(arr, arr); //arr과 arr을 행렬곱하면 됨
    }
}

int main(){
    scanf("%d %lld", &N, &B);
    long long x;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>x;
            component[i][j] = x%mod;
            arr[i][j] = component[i][j];
        }
    }
    
    solve(B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }
        printf("\n");
    }
    
    
}
