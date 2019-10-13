#include <iostream>
#include <vector>
using namespace std;
/*
    在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
    Input
    输入含有多组测试数据。
    每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
    当为-1 -1时表示输入结束。
    随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
    Output
    对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
    Sample Input
    2 1
    #.
    .#
    4 4
    ...#
    ..#.
    .#..
    #...
    -1 -1
    Sample Output
    2
    1
 */

int n = 0, k = 0;
vector<pair<int, int> > qipan; // vj(poj)的 G++ 编译器报错，嵌套尖括号时需要空格
bool x[8], y[8]; // 回溯中记录 x 轴和 y 轴是否被占
int ans;           // 方案数

void helper(int t, int start) {
    if (t >= k) {
        ans++;
        return;
    }
    for (int i = start; i < qipan.size(); i++) {
        if (x[qipan[i].first] && y[qipan[i].second]) {
            x[qipan[i].first] = false;
            y[qipan[i].second] = false;
            helper(t + 1, i + 1);
            x[qipan[i].first] = true;
            y[qipan[i].second] = true;
        }
    }
}

int main() {
    char temp;
    while (cin >> n >> k) {
        //-1 means end
        if (n == -1) {
            break;
        }
        //initialize for every case
        qipan.clear();
        ans = 0;
        for (int i = 0; i < 8; i++) {
            x[i] = true;
            y[i] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> temp;
                if (temp == '#') {
                    qipan.push_back(make_pair(i, j));
                }
            }
        }

        helper(0, 0);
        cout << ans << endl;
    }

    return 0;
}