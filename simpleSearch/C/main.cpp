#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

/*
 * Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line.
 * Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input
Line 1: Two space-separated integers: N and K
Output
Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input
5 17
Sample Output
4
Hint
The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.
 */

//bfs题，遍历当前的各种情况
//这里用visited数组进行了剪枝

int main() {
    const int MAXN = 200000;
    bool visited[MAXN] = {false};
    int farmer, cow;
    int minTime;
    int curTime = 0;
    queue<int> q;
    //read input
    cin >> farmer >> cow;
    //initialize
    minTime = abs(farmer - cow);   //update the minTime as the maximal step
    q.push(farmer);
    visited[farmer] = true;

    //bfs with 剪枝
    while (!q.empty()) {
        ++curTime;
        //pop previous level
        int len = q.size();
        int temp;
        for (int i = 0; i < len; ++i) {
            int cur = q.front();
            q.pop();
            if (curTime >= minTime-1 || cur < 0) {
                continue;
            }
            if (cur > cow) {
                //can only -1
                temp = cur - 1;
                //check whether visited
                if (temp >= 0 && !visited[temp]) {
                    visited[temp] = true;
                    if (temp == cow) {
                        minTime = curTime;
                        break;
                    }
                    else {
                        q.push(temp);
                    }
                }
            }
            else {
                temp = 2 * cur;
                if (temp < MAXN && !visited[temp]) {
                    visited[temp] = true;
                    if (temp == cow) {
                        minTime = curTime;
                        break;
                    }
                    else {
                        q.push(temp);
                    }
                }
                temp = cur + 1;
                if (temp < MAXN && !visited[temp]) {
                    visited[temp] = true;
                    if (temp == cow) {
                        minTime = curTime;
                        break;
                    }
                    else {
                        q.push(temp);
                    }
                }
                temp = cur - 1;
                if (temp >= 0 && !visited[temp]) {
                    visited[temp] = true;
                    if (temp == cow) {
                        minTime = curTime;
                        break;
                    }
                    else {
                        q.push(temp);
                    }
                }
            }
        }
        //check if already find shortest
        if (minTime == curTime)  break;
    }
    cout << minTime << endl;
    return 0;
}