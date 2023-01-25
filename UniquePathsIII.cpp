#include <iostream>
#include <vector>
#include <queue>



int uniquePathsIII(std::vector<std::vector<int>> &grid) {
    int startX;
    int startY;
    int xSize;
    int ySize;
    int toVisit;
    int blocked = 0;
    std::queue< std::vector< std::pair<int,int> > > q;
    int paths = 0;

    xSize = grid[0].size();
    ySize = grid.size();

    for(int i = 0; i < xSize; i++) {
        for(int n = 0; n < ySize; n++) {
            if(grid[i][n] == 1) {
                startX = i;
                startY = n;
            }
            else if(grid[i][n] == -1) {
                blocked++;
            }
        }
    }
    toVisit = xSize*ySize - blocked;
    
    std::pair<int,int> temp(startX, startY);
    std::vector<std::pair<int,int>> tempVec{temp};
    q.push(tempVec);
    while(q.size() > 0) {
        tempVec = q.front();
        q.pop();

        // Inc paths if end reached on last step
        if(tempVec.size() == toVisit && grid[tempVec.back().first][tempVec.back().second] == 2) {
            paths++;
            continue;
        }

        // Block off visited
        for(int i = 0; i < tempVec.size(); i++) {
            grid[tempVec[i].first][tempVec[i].second] = -1;
        }
        // Up 1
        if(tempVec.back().first > 0) {
            // Up 1 left 1
            if(tempVec.back().second > 0) {
                temp.first = tempVec.back().first - 1;
                temp.second = tempVec.back().second - 1;
                if(grid[temp.first][temp.second] == 0) {
                    tempVec.push_back(temp);
                    q.push(tempVec);
                    tempVec.pop_back();
                }
                else if(grid[temp.first][temp.second] == 2 && tempVec.size() == toVisit-1) {
                    std::cout << "uwu" << std::endl;
                }
            }
            // Up 1 right 1
            if(tempVec.back().second < ySize-1) {
                temp.first = tempVec.back().first - 1;
                temp.second = tempVec.back().second + 1;
                if(grid[temp.first][temp.second] == 0) {
                    tempVec.push_back(temp);
                    q.push(tempVec);
                    tempVec.pop_back();
                }
                else if(grid[temp.first][temp.second] == 2 && tempVec.size() == toVisit-1) {
                    std::cout << "uwu" << std::endl;
                }
            }
        }
        // Down 1
        if (tempVec.back().first < xSize-1) {
            // Down 1 left 1
            if(tempVec.back().second > 0) {
                temp.first = tempVec.back().first + 1;
                temp.second = tempVec.back().second - 1;
                if(grid[temp.first][temp.second] == 0) {
                    tempVec.push_back(temp);
                    q.push(tempVec);
                    tempVec.pop_back();
                }
                else if(grid[temp.first][temp.second] == 2 && tempVec.size() == toVisit-1) {
                    std::cout << "uwu" << std::endl;
                }
            }
            // Down 1 right 1
            if(tempVec.back().second < ySize-1) {
                temp.first = tempVec.back().first + 1;
                temp.second = tempVec.back().second + 1;
                if(grid[temp.first][temp.second] == 0) {
                    tempVec.push_back(temp);
                    q.push(tempVec);
                    tempVec.pop_back();
                }
                else if(grid[temp.first][temp.second] == 2 && tempVec.size() == toVisit-1) {
                    std::cout << "uwu" << std::endl;
                }
            }
        }

        // Unblock visited
        for(int i = 0; i < tempVec.size(); i++) {
            grid[tempVec[i].first][tempVec[i].second] = 0;
        }
    }
    return paths;
}

int main() {

    return 0;
}