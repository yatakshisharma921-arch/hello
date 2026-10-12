#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int trapRainWater(vector<vector<int>> &h)
{
    int m = h.size(), n = h[0].size(), ans = 0;
    if (m < 3 || n < 3)
        return 0;

    priority_queue<vector<int>, vector<vector<int>>,
                   greater<vector<int>>>
        pq;
    vector<vector<bool>> vis(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++)
        for (int j : {0, n - 1})
        {
            pq.push({h[i][j], i, j});
            vis[i][j] = 1;
        }

    for (int j = 1; j < n - 1; j++)
        for (int i : {0, m - 1})
        {
            pq.push({h[i][j], i, j});
            vis[i][j] = 1;
        }

    int d[] = {0, 1, 0, -1, 0};

    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = c[1] + d[k];
            int y = c[2] + d[k + 1];

            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y])
                continue;

            vis[x][y] = 1;
            ans += max(0, c[0] - h[x][y]);
            pq.push({max(c[0], h[x][y]), x, y});
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> heightMap = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}};

    cout << "Trapped water: " << trapRainWater(heightMap) << endl;
    return 0;
}
