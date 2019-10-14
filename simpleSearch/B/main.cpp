#include <iostream>
#include <climits>
#include <queue>
using namespace std;

/*
 * You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east,
 * west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides.

Is an escape possible? If yes, how long will it take?
Input
The input consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size).
L is the number of levels making up the dungeon.
R and C are the number of rows and columns making up the plan of each level.
Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty cells are represented by a '.'.
 Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.
Output
Each maze generates one line of output. If it is possible to reach the exit, print a line of the form
Escaped in x minute(s).

where x is replaced by the shortest time it takes to escape.
If it is not possible to escape, print the line
Trapped!
Sample Input
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
Sample Output
Escaped in 11 minute(s).
Trapped!
 */

//因为要找最短路径，所以bfs比较合适，因为第一个遍历到终点的路径一定是最短路径

//every step
const int dirR[] = {1, -1, 0, 0, 0, 0};
const int dirC[] = {0, 0, 0, 0, 1, -1};
const int dirH[] = {0, 0, -1, 1, 0, 0};

struct cell {
    int height,row,col;
    cell(int h, int r, int c) {height = h; row = r; col = c;}
    inline bool operator == (const cell & c) {
        if (this->row == c.row && this->col == c.col && this->height == c.height)
            return true;
        return false;
    }
    cell add(int i) {return cell{height+dirH[i], row+dirR[i], col+dirC[i]};}
};

const int maxLen = 100;   //迷宫最大大小
int minTime = INT_MAX;    //初始化为最大值
bool dugeon[maxLen][maxLen][maxLen] = {false};

//start and end
int r = 0, c = 0, h = 0;
cell startCell(0, 0 ,0);
cell endCell(0, 0, 0);
//the final ans
int curTime = 0;
//queue for bfs
queue<cell> q;


void clear(queue<cell>& q) {
    queue<cell> empty;
    swap(empty, q);
}


int main() {
    while (cin >> h >> r >> c) {
        if (h == 0)  break;
        //当前数组外围加上墙
        for (int j = 0; j <= r + 1; ++j) {
            for (int k = 0; k <= c + 1; ++k) {
                dugeon[h+1][j][k] = false;
            }
        }
        for (int i = 0; i <= h + 1; ++i) {
            for (int k = 0; k <= c + 1; ++k) {
                dugeon[i][r+1][k] = false;
            }
        }
        for (int i = 0; i <= h + 1; ++i) {
            for (int j = 0; j <= r + 1; ++j) {
                dugeon[i][j][c+1] = false;
            }
        }
        char temp;
        //read the structure of dugeon
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= r; ++j) {
                for (int k = 1; k <= c; ++k) {
                    cin >> temp;
                    if (temp == '#') {
                        dugeon[i][j][k] = false;
                    }
                    else if (temp == '.') {
                        dugeon[i][j][k] = true;
                    }
                    else if (temp == 'S') {
                        startCell = cell(i, j, k);
                        dugeon[i][j][k] = true;
                    }
                    else if (temp == 'E') {
                        endCell = cell(i, j, k);
                        dugeon[i][j][k] = true;
                    }
                }
            }
        }

        //initialize
        curTime = 0;
        minTime = INT_MAX;
        //clear the queue
        clear(q);
        q.push(startCell);
        dugeon[startCell.height][startCell.row][startCell.col] = false;

        //bfs
        while (!q.empty() && minTime == INT_MAX) {
            ++curTime;
            int len = q.size();
            //get cell in previous level
            for (int s = 0; s < len; ++s) {
                cell cur = q.front();
                q.pop();
                for (int i = 0; i < 6; ++i) {
                    cell curNext = cur.add(i);
                    if (dugeon[curNext.height][curNext.row][curNext.col]) {
                        //if reach the end, it must be the shortest
                        if (curNext == endCell) {
                            minTime = curTime;
                            break;
                        }
                        dugeon[curNext.height][curNext.row][curNext.col] = false;
                        q.push(curNext);
                    }
                }
            }
        }
        //output
        if (minTime == INT_MAX) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << minTime << " minute(s)." << endl;
        }
    }
    return 0;
}