#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // dist[r][c] stores the minimum health lost to reach cell (r, c)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        deque<pair<int, int>> dq;

        // Start position (0, 0)
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            // If we reached the target early
            if (r == m - 1 && c == n - 1) {
                break;
            }

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;

                        if (weight == 0) {
                            dq.push_front({nr, nc}); // 0-cost edge
                        } else {
                            dq.push_back({nr, nc}); // 1-cost edge
                        }
                    }
                }
            }
        }

        // Remaining health must be at least 1
        return (health - dist[m - 1][n - 1]) >= 1;
    }
};