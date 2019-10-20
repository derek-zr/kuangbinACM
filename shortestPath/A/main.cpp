#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

/*
 * Bessie is out in the field and wants to get back to the barn to get as much sleep as possible before Farmer John wakes her for the morning milking. Bessie needs her beauty sleep,
 * so she wants to get back as quickly as possible.

Farmer John's field has N (2 <= N <= 1000) landmarks in it, uniquely numbered 1..N. Landmark 1 is the barn; the apple tree grove in which Bessie stands all day is landmark N.
 Cows travel in the field using T (1 <= T <= 2000) bidirectional cow-trails of various lengths between the landmarks. Bessie is not confident of her navigation ability,
 so she always stays on a trail from its start to its end once she starts it.

Given the trails between the landmarks, determine the minimum distance Bessie must walk to get back to the barn. It is guaranteed that some such route exists.
Input
* Line 1: Two integers: T and N

* Lines 2..T+1: Each line describes a trail as three space-separated integers. The first two integers are the landmarks between which the trail travels.
 * The third integer is the length of the trail, range 1..100.
Output
* Line 1: A single integer, the minimum distance that Bessie must travel to get from landmark N to landmark 1.
Sample Input
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
Sample Output
90
Hint
INPUT DETAILS:

There are five landmarks.

OUTPUT DETAILS:

Bessie can get home by following trails 4, 3, 2, and 1.
 */

//Dijkstra模板题，直接套用模板即可
//先找当前的最短距离对应的点，再对该点的邻近节点进行松弛更新，最终得到起点到所有其他点的最短路径

int trailCnts, N;
const int MAXN = 1001;

//Dijkstra模板，包含边的结构体和松弛更新函数
struct Edge {
    int start, end, dist;
    Edge(int s, int e, int d) : start(s), end(e), dist(d) {};
};

struct Dij {
    int nodeNum, edgeNum;
    vector<Edge> edges;
    vector<int> G[MAXN];   //定义二维数组
    bool visited[MAXN];
    int d[MAXN];   //起点到各点的最短距离
    int p[MAXN];   //记录最短路径的边组成，

    void init(int n) {
        this->nodeNum = n;
        for (int i = 0; i < nodeNum; ++i) {
            G[i].clear();
        }
        edges.clear();
    }

    void addEdge(int start, int end, int dist) {
        edges.push_back({start, end, dist});
        G[start].push_back(edges.size() - 1);
    }

    struct HeapNode {
        int dist, end;
        bool operator< (const HeapNode &h) const {
            return dist > h.dist;    //距离越远，优先级越低
        }
    };

    void dij(int s) {
        //以s为起点
        priority_queue<HeapNode> q;
        memset(visited, 0, sizeof(bool)*nodeNum);
        for (int i = 0; i < nodeNum; ++i) {
            d[i] = INT_MAX;
        }
        d[s] = 0;
        q.push({0,s});
        while (!q.empty()) {
            HeapNode cur = q.top();
            q.pop();
            int curEnd = cur.end;
            if (visited[curEnd])
                continue;
            visited[curEnd] = true;
            for (int i = 0; i < G[curEnd].size(); ++i) {
                Edge& e = edges[G[curEnd][i]];
                if (e.dist + d[curEnd] < d[e.end]) {
                    //松弛
                    d[e.end] = e.dist + d[curEnd];
                    p[e.end] = G[curEnd][i];
                    //把更新权值后的点放入队列中
                    q.push({d[e.end], e.end});
                }
            }
        }
    }
};

int main() {
    Dij d;
    cin >> trailCnts >> N;
    d.init(N);
    int start, end , dist;
    for (int i = 0; i < trailCnts; ++i) {
        cin >> start >> end >> dist;
        //双向的
        d.addEdge(start-1,end-1,dist);
        d.addEdge(end-1,start-1,dist);
    }
    d.dij(0);
    //从0到N-1的最短路径
    cout << d.d[N-1] << endl;
    return 0;
}