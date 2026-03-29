#include <iostream>
#include <string>
using namespace std;
// n皇后问题
const int N = 100;
int n;
int path[N];  // 每一列的皇后的行位置,枚举每一行皇后放置到哪个位置上去
// 思路：依次搜索每个path能放置的数，最终输出结果
int dj[2 * N], fdj[2 * N];
char a[N][N];                          // 存放棋盘
bool col[N], djx[N * 2], fdjx[N * 2];  // col他的索引相当于行号，数值相当于列号
// 观察对角线会发现，正对角线坐标i+j的值都是相等的，而反对角线的j-i都是相等扽
// 需要处理的细节是反对角线会出现负数的情况 ，所以统一给加上n保证数值不变
void dfs(int t) {
    if (t == n + 1) {
        // 轮到n+1的位置放置数值了，说明1-n位置已经放完了，可以输出
        for (int i = 1; i <= n; i++)
            puts(a[i] + 1);
        puts("");
        return;
    }
    // 不满足输出条件继续寻找该位置可以放置的数
    for (int i = 1; i <= n; i++) {  // i枚举的是t行列，一直在问第i列放行么
        if (!col[i] && !djx[t + i] && !fdjx[i - t + n]) {
            djx[t + i] = true;
            fdjx[i - t + n] = true;
            col[i] = true;
            // 这里需要对整行做处理
            for (int j = 1; j <= n; j++) {
                if (j == i)
                    a[t][j] = 'Q';
                else
                    a[t][j] = '.';
            }
            dfs(t + 1);
            djx[t + i] = false;
            fdjx[i - t + n] = false;
            col[i] = false;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}
