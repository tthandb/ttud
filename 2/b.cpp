#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<long long int, long long int>> leftSet; // set distance - requirement
stack<pair<long long int, long long int>> rightSet;

long long int availability = 0;
long long int cost = 0;

void feedLeft(long long int currVal, bool isFirstTime)
{
    if (isFirstTime)
    {
        if (leftSet.empty())
            return;
        pair<long long int, long long int> temp = leftSet.top();
        leftSet.pop();
        if (currVal < temp.second)
        {
            cost += temp.first * 2 * (temp.second / currVal - 1);
            if (temp.second % currVal != 0)
                leftSet.push({temp.first, temp.second % currVal});
        }
        if (currVal == temp.second)
        {
            return;
        }
        if (currVal > temp.second)
        {
            feedLeft(currVal - temp.second, false);
        }
    }
    else
    {
        if (leftSet.empty())
            return;
        pair<long long int, long long int> temp = leftSet.top();
        leftSet.pop();
        if (currVal < temp.second)
            leftSet.push({temp.first, temp.second - currVal});
        if (currVal == temp.second)
            return;
        if (currVal > temp.second)
        {
            feedLeft(currVal - temp.second, false);
        }
    }
}

void feedRight(long long int currVal, bool isFirstTime)
{
    if (isFirstTime)
    {
        if (rightSet.empty())
            return;
        pair<long long int, long long int> temp = rightSet.top();
        rightSet.pop();
        if (currVal < temp.second)
        {
            cost += temp.first * 2 * (temp.second / currVal - 1);
            if (temp.second % currVal != 0)
                rightSet.push({temp.first, temp.second % currVal});
        }
        if (currVal == temp.second)
        {
            return;
        }
        if (currVal > temp.second)
        {
            feedRight(currVal - temp.second, false);
        }
    }

    else
    {
        if (rightSet.empty())
            return;
        pair<long long int, long long int> temp = rightSet.top();
        rightSet.pop();
        if (currVal < temp.second)
        {
            rightSet.push({temp.first, temp.second - currVal});
        }
        if (currVal == temp.second)
            return;
        if (currVal > temp.second)
        {
            feedRight(currVal - temp.second, false);
        }
    }
}

long long int solve()
{
    while (!leftSet.empty())
    {
        long long int currVal = availability;
        cost += leftSet.top().first * 2;
        feedLeft(currVal, true);
    }

    while (!rightSet.empty())
    {
        long long int currVal = availability;
        cost += rightSet.top().first * 2;
        feedRight(currVal, true);
    }

    return cost;
}

int main()
{
    long long int n;
    cin >> n >> availability;
    long long int x, m;
    vector<pair<long long int, long long int>> left;
    vector<pair<long long int, long long int>> right;
    for (long long int i = 0; i < n; i++)
    {
        cin >> x >> m;
        if (x < 0)
        {
            left.push_back(make_pair(-x, m));
        }
        else if (x > 0)
        {
            right.push_back(make_pair(x, m));
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (long long int j = 0; j < left.size(); j++)
        leftSet.push(left[j]);
    for (long long int k = 0; k < right.size(); k++)
        rightSet.push(right[k]);

    cout << solve() << endl;
}