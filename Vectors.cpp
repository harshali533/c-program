#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<string, vector<int>> studentRecords;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string name;
        vector<int> marks(3);
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter 3 marks: ";
        for (int j = 0; j < 3; ++j) {
            cin >> marks[j];
        }
        cin.ignore();
        studentRecords[name] = marks;
    }

    string topper;
    double highestAvg = 0.0;

    for (const auto& pair : studentRecords) {
        const string& name = pair.first;
        const vector<int>& marks = pair.second;
        double avg = accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
        cout << "Student: " << name << ", Marks: ";
        for (int mark : marks) cout << mark << " ";
        cout << ", Average: " << avg << endl;

        if (avg > highestAvg) {
            highestAvg = avg;
            topper = name;
        }
    }

    cout << "Topper: " << topper << " with average " << highestAvg << endl;

    return 0;
}
