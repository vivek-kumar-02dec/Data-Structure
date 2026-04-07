class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        maze[entrance[0]][entrance[1]] = '+';
        q.push({entrance[0], entrance[1]});
        int level = 0;
        while (!q.empty()) {
            level++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [a, b] = q.front();
                q.pop();
                vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto [x, y] : dir) {
                    int nx = a + x;
                    int ny = b + y;
                    if (nx < 0 || nx >= maze.size() || ny < 0 ||
                        ny >= maze[0].size())
                        continue;
                    if (maze[nx][ny] == '.') {
                        if (nx == 0 || ny == 0 || nx == maze.size() - 1 ||
                            ny == maze[0].size() - 1)
                            return level;
                        q.push({nx, ny});
                        maze[nx][ny] = '+';
                    }
                }
            }
        }
        return -1;
    }
};
