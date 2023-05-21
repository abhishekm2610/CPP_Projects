#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
    void print(std::vector<int> const &input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            std::cout << input.at(i) << ' ';
        }
    }

    void dfs(int i, int j, vector<vector<int>> &grid, map<vector<int>, bool> &visited)
    {
        if (visited.find({i, j}) == visited.end())
        {
            visited[{i, j}] = true;
            if (i < grid.size() - 1 && grid[i + 1][j] == 1)
            {
                cout << grid[i][j + 1] << "oomb \n";
                dfs(i + 1, j, grid, visited);
            };
            if (j < grid[i].size() && grid[i][j + 1] == 1)
            {
                cout << grid[i][j + 1] << "oomb \n";

                dfs(i, j + 1, grid, visited);
            };
        }
        else
        {
            return;
        }
        return;
    };

    int shortestBridge(vector<vector<int>> &grid)
    {
        map<vector<int>, bool> mp1;
        map<vector<int>, bool> mp2;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, mp1);
                    break;
                };
            };
            if (mp1.size() != 0)
            {
                break;
            };
        };

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (mp1.find({i, j}) == mp1.end())
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(i, j, grid, mp2);
                        break;
                        cout << grid[i][j] << i << j << endl;
                    };
                };
            };
        };

        // for (auto it = mp1.cbegin(); it != mp1.cend(); ++it)
        // {
        //     dfs2((*it).first[0], (*it).first[1], mp1, mp2);
        //     // print((*it).first);
        //     cout << "MP1" << (*it).second << "\n";
        // };
        // for (auto it = mp2.cbegin(); it != mp2.cend(); ++it)
        // {
        //     print((*it).first);
        //     cout << "MP2" << (*it).second << "\n";
        // };
        int ans = INT_MAX;
        for (auto i : mp1)
            for (auto j : mp2)
                ans = min(ans, (abs(i.first[0] - j.first[0]) + abs(i.first[0] - j.first[1]) - 1));
        return ans;
    };
};

int main()
{
    vector<vector<int>> dp{{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    // vector<int> newInterval{2, 5};
    Solution solObj;
    cout << solObj.shortestBridge(dp);
    // Iterating vector by using index
    // for (int i = 0; i < res.size(); i++)
    // {
    //     print(res[i]);
    //     cout << "\n";
    // };
}

// // C++ program to print the elements
// // of the vector
// #include <iostream>
// #include <vector>
// using namespace std;

// template <typename S>
// ostream &operator<<(ostream &os,
//                     const vector<S> &vector)
// {
//     // Printing all the elements
//     // using <<
//     for (auto element : vector)
//     {
//         os << element << " ";
//     }
//     return os;
// }

// // Driver Code
// int main()
// {
//     // vector containing integer elements
//     vector<int> A = {10, 20, 30,
//                      40, 50, 60};

//     cout << A << endl;

//     return 0;
// }
