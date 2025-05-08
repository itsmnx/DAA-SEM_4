//fractional knapsack

#include<bits/stdc++.h>
using namespace std;

void knapsackcal(vector<int>& p, vector<int>& w) {
    int n = p.size();
    int maxcap = 15;
    vector<pair<float, pair<int, int>>> items;

    for (int i = 0; i < n; i++) {
        float ratio = (float)p[i] / w[i];
        items.push_back({ratio, {p[i], w[i]}});
    }

    sort(items.begin(), items.end(), [](const pair<float, pair<int, int>>& a, const pair<float, pair<int, int>>& b) {
        return a.first > b.first;
    });

    int currentWeight = 0;
    float totalProfit = 0.0;

    for (const auto& item : items) {
        int profit = item.second.first;
        int weight = item.second.second;
        float ratio = item.first;

        if (currentWeight + weight <= maxcap) {
            currentWeight += weight;
            totalProfit += profit;
        }
        else {
            int remainingCapacity = maxcap - currentWeight;
            totalProfit += profit * ((float)remainingCapacity / weight);
            break;
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    vector<int> profit = {10, 5, 15, 7, 6, 18, 3};
    vector<int> weight = {2, 3, 5, 7, 1, 4, 1};
    knapsackcal(profit, weight);
    return 0;
}
