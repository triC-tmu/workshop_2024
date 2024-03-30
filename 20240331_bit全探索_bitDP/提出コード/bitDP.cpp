//submit  https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/9037754/T21140031/C++17
#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int n,m;cin >> n >> m;// n頂点m辺
  vector<vector<pair<int,int>>> g(n);
  for(int i = 0;i < m;i++){
    int s,t,d;cin >> s >> t >> d;
    g[s].push_back({t,d});
  }

  vector<vector<int>> dp(1 << n,vector<int>(n,INF));
  //初期化
  for(const auto &[to,cost] :g[0]){
    dp[1 << to][to] = cost;
  }

  for(int k = 0;k < n;k++){//k:立っているbit数
    for(int i = 0;i < (1 << n);i++){
      if(__builtin_popcount(i) != k)continue;//立っているbit数がkでなかった
      for(int j = 0;j < n;j++){
        if((i >> j & 1) == 0)continue;//訪れた頂点の集合(i)に頂点jが含まれていなかった
        if(dp[i][j] == INF)continue;

        for(const auto &[to,cost] :g[j]){
          if((i >> to & 1) == 1)continue;//行き先がすでに到達済みだった
          //遷移
          dp[i + (1 << to)][to] = min(dp[i + (1 << to)][to],dp[i][j] + cost);
        }
      }
    }
  }

  if(dp[(1 << n) -1][0] == INF){
    cout << -1 << endl;
  }else{
    cout << dp[(1 << n) -1][0] << endl;
  }
}