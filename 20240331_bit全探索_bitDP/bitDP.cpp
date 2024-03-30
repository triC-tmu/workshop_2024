#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main(){
  int n,m;cin >> n >> m;// n頂点m辺
  vector<vector<pair<int,int>>> g(n);
  for(int i = 0;i < m;i++){
    int s,t,d;cin >> s >> t >> d;
    g[s].push_back({t,d});
  }

  vector<vector<int>> dp(1 << n,vector<int>(n,INF));
  //初期化
  dp[0][0] = 0;

  for(int i = 0;i < (1 << n);i++){
    for(int j = 0;j < n;j++){
      if(dp[i][j] == INF)continue;
      for(const auto &[to,cost] :g[j]){
        if((i >> to & 1) == 1)continue;//行き先がすでに到達済みだった
        //遷移
        dp[i + (1 << to)][to] = min(dp[i + (1 << to)][to],dp[i][j] + cost);
      }
    }
  }

  if(dp[(1 << n) -1][0] == INF){
    cout << -1 << endl;
  }else{
    cout << dp[(1 << n) -1][0] << endl;
  }
}