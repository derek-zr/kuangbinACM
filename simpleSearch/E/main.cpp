#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
 * Given a positive integer n, write a program to find out a nonzero multiple m of n whose decimal representation contains only the digits 0 and 1.
 * You may assume that n is not greater than 200 and there is a corresponding m containing no more than 100 decimal digits.
Input
The input file may contain multiple test cases. Each line contains a value of n (1 <= n <= 200). A line containing a zero terminates the input.
Output
For each value of n in the input print a line containing the corresponding value of m. The decimal representation of m must not contain more than 100 digits.
 If there are multiple solutions for a given value of n, any one of them is acceptable.
Sample Input
2
6
19
0
Sample Output
10
100100100100100100
111111111111111111
 */

//这道题也是bfs题，因为最大位数有100位， 用dfs容易超时
//具体的用到一个技巧，就是用一个数的余数来代表这个数,比如11 % 3 = 2, 那么110 % 3 = 2，
// 所以可以用余数 2 代替原数 11/110，原数11/110直接按位 push 进一个数组保存即可。这样自然处理了大数的情况

const int MAXN= 201;
const int MAXDIGITS = 100;   //最多100位

struct State {
    int mod;
    vector<int> nums;
};

int main() {
    bool visited[MAXN];   //访问数组，剪枝
    queue<State> q;
    int n;

    vector<int> curNums;
    State curState, startState;
    startState.mod = 1;
    startState.nums.push_back(1);
    int curMod;

    while (cin >> n && n) {
        memset(visited, 0, sizeof(visited));
        q = queue<State> ();
        q.push(startState);
        visited[1] = true;

        //bfs
        while (!q.empty()) {
            curState = q.front();
            q.pop();
            bool found = false;
            //遍历0/1两种情况
            for (int i = 0; i <= 1; ++i) {
                curNums = curState.nums;
                curNums.push_back(i);
                //计算加上一位0、1后的余数，并更新
                curMod = curState.mod * 10 + i;
                curMod = curMod % n;
                if (curMod == 0 && curNums.size() <= MAXDIGITS) {
                    for (int j = 0; j < curNums.size(); ++j) {
                        cout << curNums[j];
                    }
                    cout << "\n";
                    //goto next;
                    found = true;
                    break;
                }
                if (!visited[curMod]) {
                    visited[curMod] = true;
                    q.push({curMod, curNums});
                }
            }
            if (found)  break;
        }
        //next:;
    }

    return 0;
}