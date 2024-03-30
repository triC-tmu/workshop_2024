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
#初期化
dp[0][0] = 0

for i in range(1 << n):
    for j in range(n):
        if dp[i][j] == INF: continue 
        for e in g[j]:
            if i >> e.to & 1 == 1: continue #行き先がすでに到達済みだった
            #遷移
            dp[i + (1 << e.to)][e.to] = min(dp[i + (1 << e.to)][e.to],dp[i][j] + e.cost)

if dp[(1 << n)-1][0] == INF:
    print(-1)
else:
    print(dp[(1 << n)-1][0])

