#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
/*
 * The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices.
— It is a matter of security to change such things every now and then, to keep the enemy in the dark.
— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
— No, it’s not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.

Now, the minister of finance, who had been eavesdropping, intervened.
— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
— Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
— In fact, I do. You see, there is this programming contest going on... Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above.
1033
1733
3733
3739
3779
8779
8179
The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be purchased.
Input
One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).
Output
One line for each case, either with a number stating the minimal cost or containing the word Impossible.
Sample Input
3
1033 8179
1373 8017
1033 1033
Sample Output
6
7
0
 */

//bfs+判断是否为素数的题

const int MAXNUM = 10001;
bool isNotPrime[MAXNUM] = {false};
bool visited[MAXNUM];
struct Nums {
    int num[4];
};

void checkPrime() {
    //用筛法快速标定素数
    for (int i = 2; i < sqrt(MAXNUM); ++i) {
        if (!isNotPrime[i]) {
            //素数的倍数都不是素数
            for (int j = 2; i * j < MAXNUM; ++j)
                isNotPrime[i*j] = true;
        }
    }
    return;
}

int calNum(int nums[]) {
    return nums[0]*1000 + nums[1]*100 + nums[2]*10 + nums[3];
}

int bfs(int start, int end) {
    if (start == end) {
        return 0;
    }
    memset(visited, 0 , sizeof(visited));
    queue<Nums> q;
    Nums startNum, curNum;
    startNum.num[0] = start / 1000;
    startNum.num[1] = start % 1000 / 100;
    startNum.num[2] = start % 100 / 10;
    startNum.num[3] = start % 10;
    q.push(startNum);
    visited[start] = true;
    int curCost = 0;
    //bfs
    while (!q.empty()) {
        ++curCost;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            curNum = q.front();
            q.pop();
            Nums tmpNum;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= 9; ++j) {
                    //每次更换时都需要复原
                    tmpNum = curNum;
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    if (tmpNum.num[i] != j) {
                        tmpNum.num[i] = j;
                        int tmp = calNum(tmpNum.num);
                        if (tmp == end) {
                            return curCost;
                        }
                        if (!isNotPrime[tmp] && !visited[tmp]) {
                            visited[tmp] = true;
                            q.push(tmpNum);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int start, end;
    checkPrime();
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        int ans = bfs(start, end);
        if (ans == -1) {
            cout << "Impossible" << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}