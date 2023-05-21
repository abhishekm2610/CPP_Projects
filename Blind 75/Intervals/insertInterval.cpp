#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int low = newInterval[0];
        int high = newInterval[1];
        int i, j = 0;
        int inserted = 0;
        for (i = 0; i < intervals.size(); i++)
        {
            if (low <= intervals[i][1] && inserted == 0)
            {
                vector<int> newInt(2);
                newInt[0] = intervals[i][0];

                for (j = i + 1; j < intervals.size(); j++)
                {
                    if (intervals[j][0] >= high)
                    {
                        if (intervals[j][0] == high)
                        {
                            newInt[1] = intervals[j][1];
                            i = j;
                        }
                        else
                        {
                            newInt[1] = high;
                            i = j - 1;
                        };
                        break;
                    };
                };

                // cout << intervals[i];
                ans.emplace_back(newInt);
                inserted = 1;
            }
            else
            {
                ans.emplace_back(intervals[i]);
            };
        };

        return ans;
    };
};

void print(std::vector<int> const &a)
{
    std::cout << "The vector elements are : ";
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';
}
int main()
{
    vector<vector<int>> dp{{1, 3}, {6, 9}};
    vector<int> newInterval{2, 5};
    Solution solObj;
    vector<vector<int>> res = solObj.insert(dp, newInterval);
    // Iterating vector by using index
    for (int i = 0; i < res.size(); i++)
    {
        print(res[i]);
        cout << "\n";
    };
}