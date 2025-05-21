#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent an activity
struct Activity {
    int start;
    int finish;
};

// Comparator to sort activities by their finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void selectActivities(vector<Activity>& activities) {
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected non-conflicting activities are:\n";

    // The first activity always gets selected
    int lastFinishTime = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    // Consider the rest of the activities
    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinishTime) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinishTime = activities[i].finish;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and finish time for each activity:\n";
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start >> activities[i].finish;
    }

    selectActivities(activities);

    return 0;
}
