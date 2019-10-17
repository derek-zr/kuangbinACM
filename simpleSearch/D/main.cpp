#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
/*
 * Farmer John knows that an intellectually satisfied cow is a happy cow who will give more milk. He has arranged a brainy activity for cows in which they manipulate an M × N grid (1 ≤ M ≤ 15; 1 ≤ N ≤ 15) of square tiles, 、
 * each of which is colored black on one side and white on the other side.

As one would guess, when a single white tile is flipped, it changes to black; when a single black tile is flipped, it changes to white.
 The cows are rewarded when they flip the tiles so that each tile has the white side face up. However, the cows have rather large hooves and when they try to flip a certain tile, they also flip all the adjacent tiles
 (tiles that share a full edge with the flipped tile). Since the flips are tiring, the cows want to minimize the number of flips they have to make.

Help the cows determine the minimum number of flips required, and the locations to flip to achieve that minimum. If there are multiple ways to achieve the task with the minimum amount of flips,
 return the one with the least lexicographical ordering in the output when considered as a string. If the task is impossible, print one line with the word "IMPOSSIBLE".

Input
Line 1: Two space-separated integers: M and N
Lines 2.. M+1: Line i+1 describes the colors (left to right) of row i of the grid with N space-separated integers which are 1 for black and 0 for white
Output
Lines 1.. M: Each line contains N space-separated integers, each specifying how many times to flip that particular location.
Sample Input
4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1
Sample Output
0 0 0 0
1 0 0 1
1 0 0 1
0 0 0 0
 */

//这道题解题的关键在于理解题目，并缩小搜索空间
//从题目中可以看出，如果我们最终想达到全white，那么由于翻转一个瓷砖会影响其周围的瓷砖，那么如果上一行有一个black，那么必须通过下一行同一列的翻转保证全白
//那么一旦我们确定了第一行的状态，后面的翻转情况都可以逐行确定了，只需检查最后一行的情况即可知道当前第一行的翻转状态是不是一个有效的结果
//在枚举第一行翻转状态时，用到了移位枚举的技巧，即通过各位置上的0 1 状态，来判断是否需要反转。

const int MAXN = 16;
bool originGrid[MAXN][MAXN], grid[MAXN][MAXN];    //每次枚举一个新状态时，都需要恢复到初始值
int ans[MAXN][MAXN], tmpAns[MAXN][MAXN];
int minFlip = INT_MAX;
int curFlip;
int m, n;   //rows and cols of the grid

void flip(int i, int j) {
    //翻转一次
    ++tmpAns[i][j];
    ++curFlip;
    grid[i][j] = !grid[i][j];
    if (i -1 >= 0)  grid[i-1][j] = !grid[i-1][j];
    if (i + 1 < m)  grid[i+1][j] = !grid[i+1][j];
    if (j -1 >= 0)  grid[i][j-1] = !grid[i][j-1];
    if (j + 1 < n)  grid[i][j+1] = !grid[i][j+1];
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> originGrid[i][j];
        }
    }

    for (int status = 0; status < (1<<n); ++status) {
        //初始化
        curFlip = 0;
        memcpy(grid, originGrid, sizeof(grid));
        memset(tmpAns, 0, sizeof(tmpAns));

        //第一行的情况
        for (int i = 0; i < n; ++i) {
            if (status >> i & 1)
                flip(0, i);
        }

        //遍历确定后面行的情况
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i-1][j]) {
                    //保证上一行全白
                    flip(i, j);
                }
            }
        }
        //通过检查最后一行的情况， 来判断当前答案是否合理
        for (int i = 0; i < n; ++i) {
            if (grid[m-1][i]) {
                //不符合条件
                curFlip = INT_MAX;
            }
        }
        if (curFlip < minFlip) {
            minFlip = curFlip;
            memcpy(ans, tmpAns, sizeof(ans));
        }
        else if (curFlip == minFlip && curFlip != INT_MAX) {
            //相等的情况下，字节序小的优先
            bool replaced = true;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    //当前结果字节序更大，则不更新
                    if (tmpAns[i][j] > ans[i][j]) {
                        replaced = false;
                        break;
                    }
                }
                if (replaced) {
                    memcpy(ans, tmpAns, sizeof(tmpAns));
                    break;
                }
            }
        }
    }

    if (minFlip == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j];
                if (j != n-1)
                    cout << " ";
            }
            if (i != m-1)
                cout << endl;
        }
    }

    return 0;
}