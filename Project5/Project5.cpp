#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int path(vector<vector<int>>& triangle) {
    int n = triangle.size();

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle_1 = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
    vector<vector<int>> triangle_2 = { {-1}, {2, 3}, {1, -1, -3}, {4, 2, 1, 3} };

    cout << "Res_1 = " << path(triangle_1);
    cout << endl;
    cout << "Res_2 = " << path(triangle_2);
    cout << endl;

    return 0;
}
