#submit https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/9037879/T21140031/PyPy3
class Edge:
    def __init__(self,to,cost):
        self.to = to
        self.cost = cost

INF = 1 << 30

n, m = map(int,input().split()) #n頂点m辺
g = [[] for _ in range(n)] #隣接リスト
for _ in range(m):
    s,t,d = map(int,input().split())
    g[s].append(Edge(t,d))

dp = [[INF] * n for _ in range(1 << n)]

for e in g[0]:
    dp[1 << e.to][e.to] = e.cost

for k in range(n):#k:立っているbit数
    for i in range(1 << n):
        if i.bit_count() != k: continue #立っているbit数がkでなかった
        for j in range(n):
            if i >> j & 1 == 0: continue #訪れた頂点の集合(i)に頂点jが含まれていなかった
            if dp[i][j] == INF: continue
            
            for e in g[j]:
                if i >> e.to & 1 == 1: continue #行き先がすでに到達済みだった
                #遷移
                dp[i + (1 << e.to)][e.to] = min(dp[i + (1 << e.to)][e.to],dp[i][j] + e.cost)

if dp[(1 << n)-1][0] == INF:
    print(-1)
else:
    print(dp[(1 << n)-1][0])

