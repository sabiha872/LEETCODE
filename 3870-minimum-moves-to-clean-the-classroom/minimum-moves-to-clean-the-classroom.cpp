class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectMask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;

        int startR = 0;
        int startC = 0;

        // Find starting point and number each litter
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                litterBit[r][c] = -1;

                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount++;
                }
            }
        }

        // No litter to collect
        if (litterCount == 0)
            return 0;

        int allCollected = (1 << litterCount) - 1;

        // visited[row][col][energy][mask]
        VVVVB visited(
            m,
            VVVB(
                n,
                VVB(
                    maxEnergy + 1,
                    VB(1 << litterCount, false)
                )
            )
        );

        queue<State> q;

        q.push({startR, startC, maxEnergy, 0});

        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                State curr = q.front();
                q.pop();

                // All litter collected
                if (curr.collectMask == allCollected)
                    return moves;

                // No energy left
                if (curr.energyLeft == 0)
                    continue;

                for (auto& dir : directions) {

                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    // Out of bounds
                    if (nextRow < 0 || nextRow >= m ||
                        nextCol < 0 || nextCol >= n) {
                        continue;
                    }

                    // Wall
                    if (classroom[nextRow][nextCol] == 'X')
                        continue;

                    int nextEnergy = curr.energyLeft - 1;
                    int nextMask = curr.collectMask;

                    char cell = classroom[nextRow][nextCol];

                    // Recharge
                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    }

                    // Collect litter
                    else if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    // New state
                    if (!visited[nextRow][nextCol]
                                [nextEnergy]
                                [nextMask]) {

                        visited[nextRow][nextCol]
                                [nextEnergy]
                                [nextMask] = true;

                        q.push({
                            nextRow,
                            nextCol,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};