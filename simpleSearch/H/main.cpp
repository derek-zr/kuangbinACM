#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * You are given two pots, having the volume of A and B liters respectively. The following operations can be performed:

FILL(i)        fill the pot i (1 ≤ i ≤ 2) from the tap;
DROP(i)      empty the pot i to the drain;
POUR(i,j)    pour from pot i to pot j; after this operation either the pot j is full (and there may be some water left in the pot i),
 or the pot i is empty (and all its contents have been moved to the pot j).
Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.

Input
On the first and only line are the numbers A, B, and C. These are all integers in the range from 1 to 100 and C≤max(A,B).

Output
The first line of the output must contain the length of the sequence of operations K. The following K lines must each describe one operation.
 If there are several sequences of minimal length, output any one of them. If the desired result can’t be achieved,
 the first and only line of the file must contain the word ‘impossible’.

Sample Input
3 5 4
Sample Output
6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)
 */

//bfs题，难点在于要输出中间过程，因此我们需要记录中间状态。当找到符合条件的答案时，反向推回正确路径。
//由于需要得到正确答案的路径，因此这里不能使用queue（之前的状态不能直接pop），而需要用vector存储之前所有的状态，方便回溯复原。

struct State {
    int A, B;
    int prev;     //记录上一个操作的下标，方便回溯
};

vector<State> s;
bool visited[102][102];
int a, b ,c;
stack<int> paths;    //从结尾向初始状态压栈，从而恢复整个路径

bool isValid(int i) {
    //检查当前的状态是否已经符合题目的要求，并且回溯输出结果
    if (s[i].A  ==  c || s[i].B == c) {
        int prev = s[i].prev;
        paths.push(i);
        //直到找到起始状态
        while (prev != -1) {
            paths.push(prev);
            prev = s[prev].prev;
        }
        if (!paths.empty()) {
            State cur = s[paths.top()];
            paths.pop();
            cout << paths.size() << endl;   //方案路径的长度
            while (!paths.empty()) {
                //输出具体的方案路径，根据A和B的大小情况确定进行了什么操作
                State nextS = s[paths.top()];
                paths.pop();
                if (nextS.A < cur.A && nextS.B == cur.B) {
                    cout << "DROP(1)" << endl;
                }
                else if (nextS.A == cur.A && nextS.B  < cur.B) {
                    cout << "DROP(2)" << endl;
                }
                else if (nextS.A > cur.A && nextS.B == cur.B) {
                    cout << "FILL(1)" << endl;
                }
                else if (nextS.A == cur.A && nextS.B > cur.B) {
                    cout << "FILL(2)" << endl;
                }
                else if (nextS.A < cur.A && nextS.B > cur.B) {
                    cout << "POUR(1,2)" << endl;
                }
                else {
                    cout << "POUR(2,1)" << endl;
                }
                cur = nextS;    //更新状态
            }
        }
        return true;
    }
    return false;
}

int main() {
    cin >> a >> b >> c;

    s.push_back({0,0,-1});   //prev为-1表明已经到了初始状态
    visited[0][0] = true;
    //bfs
    for (int i = 0; i < s.size(); ++i) {
        State tmp = s[i];
        //遍历各种操作
        //1. 当A容器中当前的水小于其容量时，可以fill A，也可以从B中pour出到A
        if (tmp.A < a) {
            if (!visited[a][s[i].B]) {
                visited[a][s[i].B] = true;
                //fill a
                s.push_back({a, s[i].B, i});
                //判断是否合格
                if (isValid(s.size() - 1)) {
                    return 0;
                }
            }
            if (s[i].B) {
                int t = min(a-s[i].A, s[i].B);
                //pour from B to A
                if (!visited[s[i].A+t][s[i].B-t]) {
                    visited[s[i].A+t][s[i].B-t] = true;
                    s.push_back({s[i].A+t, s[i].B-t, i});
                    if (isValid(s.size()-1)) {
                        return 0;
                    }
                }
            }
        }
        //2. 当B容器中当前的水小于其容量时，可以fill B，也可以从A中pour出到B
        if (tmp.B < b) {
            if (!visited[s[i].A][b]) {
                visited[s[i].A][b] = true;
                //fill b
                s.push_back({s[i].A, b, i});
                //判断是否合格
                if (isValid(s.size() - 1)) {
                    return 0;
                }
            }
            //3. 只要AB不为空，那么都可以进行drop操作
            if (s[i].A) {
                int t = min(b-s[i].B, s[i].A);
                //pour from A to B
                if (!visited[s[i].A-t][s[i].B+t]) {
                    visited[s[i].A-t][s[i].B+t] = true;
                    s.push_back({s[i].A-t, s[i].B+t, i});
                    if (isValid(s.size()-1)) {
                        return 0;
                    }
                }
            }
        }
        if (s[i].B) {
            if (!visited[s[i].A][0]) {
                visited[s[i].A][0] = true;
                //drop a
                s.push_back({s[i].A, 0 ,i});
                if (isValid(s.size() - 1)) {
                    return 0;
                }
            }
        }
        if (s[i].A) {
            if (!visited[0][s[i].B]) {
                visited[0][s[i].B] = true;
                //drop b
                s.push_back({0, s[i].B ,i});
                if (isValid(s.size() - 1)) {
                    return 0;
                }
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}