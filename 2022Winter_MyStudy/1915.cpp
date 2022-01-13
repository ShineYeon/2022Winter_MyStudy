//
//  1915.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/13.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string input[1001];
int ans[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp = input[i][j] -'0';
            if(tmp == 1){
                if(i==0 || j==0)
                    ans[i][j] = 1;
                else
                    ans[i][j] = min(ans[i-1][j-1], min(ans[i-1][j], ans[i][j-1]))+1;
            }
            else //arr[i][j]가 0이라면
                ans[i][j] = 0;
        }
    }
    int Max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Max = max(Max, ans[i][j]);
        }
    }
    cout<<Max*Max<<endl;
}
