#include <iostream>
#include <vector>
#include <queue>

int uniquePathsIII(std::vector<std::vector<int>> &grid) {
    int valid = 0;
    std::pair<int,int> startCoords;
    std::pair<int,int> endCoords;
    int blockers = 0;
    int xSize = grid[0].size();
    int ySize = grid.size();
    int target = xSize*ySize;
    std::vector<std::vector<int>> tempGrid = grid;

    // i=y j=x
    for(int i = 0; i < ySize; i++) {
        for(int j = 0; j < xSize; j++) {
            if(grid[i][j] == 1) {
                startCoords.first = j;
                startCoords.second = i;
            }
            else if(grid[i][j] == 2) {
                endCoords.first = j;
                endCoords.second = i;
            }
            else if(grid[i][j] == -1) {
                blockers++;
            }
        }
    }
    target -= blockers;

    std::queue<std::vector<std::pair<int,int>>> q;
    std::vector<std::pair<int,int>> path = {startCoords};
    q.push(path);
    std::pair<int,int> tempPair;
    while(q.size() > 0) {
        path = q.front();
        q.pop();
        // Check if done, skip the adding stuff if true
        if(path.size() == target && path.back() == endCoords) {
            valid++;
            continue;
        }
        // Block off visited nodes
        for(int i = 0; i < path.size(); i++) {
            tempPair = path[i];
            tempGrid[tempPair.second][tempPair.first] = -1;
        }
        // Add 4 directions to queue if valid
        std::pair<int,int> tempPair2 = path.back();
        // 1 left
        tempPair = tempPair2;
        if(tempPair.first > 0) {
            if(tempGrid[tempPair.second][tempPair.first-1] != -1) {
                // Update last move, push to path, push path to queue, reset path to check for others
                tempPair.first -= 1;
                path.push_back(tempPair);
                q.push(path);
                path.pop_back();
            }
        }
        // 1 right
        tempPair = tempPair2;
        if(tempPair.first < xSize-1) {
            if(tempGrid[tempPair.second][tempPair.first+1] != -1) {
                // Update last move, push to path, push path to queue, reset path to check for others
                tempPair.first += 1;
                path.push_back(tempPair);
                q.push(path);
                path.pop_back();
            }
        }
        // 1 down
        tempPair = tempPair2;
        if(tempPair.second > 0) {
            if(tempGrid[tempPair.second-1][tempPair.first] != -1) {
                // Update last move, push to path, push path to queue, reset path to check for others
                tempPair.second -= 1;
                path.push_back(tempPair);
                q.push(path);
                path.pop_back();
            }
        }
        // 1 up
        tempPair = tempPair2;
        if(tempPair.second < ySize-1) {
            if(tempGrid[tempPair.second+1][tempPair.first] != -1) {
                // Update last move, push to path, push path to queue, reset path to check for others
                tempPair.second += 1;
                path.push_back(tempPair);
                q.push(path);
                path.pop_back();
            }
        }

        // Reset tempGrid
        tempGrid = grid;
    }
    return valid;

}



int main() {
    std::vector<std::vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    int ret = uniquePathsIII(grid);
    std::cout << ret << std::endl;
    return 0;
}