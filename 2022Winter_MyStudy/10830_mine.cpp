//
//  10830_mine.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/19.
//

#include <iostream>
#include <cstring>
using namespace std;
long long N, B;
long long orig[6][6];
long long ret[6][6];
long long mod = 1000;

void squared(long long a[6][6], long long b[6][6]){
    long long tmp[6][6];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] = tmp[i][j] % mod;
            }
        }
    }
    
    memcpy(ret, tmp, sizeof(ret));
    
}

void div(long long x){
    if(x==1) return; //행렬 제곱은 1을 제곱하면 그대로이기때문..
    else if(x%2 == 1){
        div(x/2);
        squared(ret, ret);
        squared(ret, orig);
    }
    else{
        div(x/2);
        squared(ret, ret);
    }
}

int main(){
    cin>>N>>B;
    int x;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>x;
            orig[i][j] = x%mod;
            ret[i][j] = orig[i][j];
        }
    }
    
    div(B);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
}
