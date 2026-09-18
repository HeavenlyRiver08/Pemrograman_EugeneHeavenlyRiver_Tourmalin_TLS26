#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> circle;
    for (int i = 1; i <= N; i++) {
        circle.push_back(i);
    }

    vector<int> eliminationOrder;
    int current = 0; // current starting position

    while (circle.size() > 1) {
        // Move to the K-th person
        for (int i = 1; i < K; i++) {
            current = (current + 1) % circle.size();
        }

        int removed = circle[current];
        eliminationOrder.push_back(removed);

        // Remove the eliminated astronaut
        circle.erase(circle.begin() + current);

        // Update K
        if (removed % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        // Next counting starts from the next astronaut after the removed one
        if (!circle.empty()) {
            current = current % circle.size();
        }
    }

    cout << "Elimination order: ";
    for (int x : eliminationOrder) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Last astronaut remaining: " << circle[0] << "\n";

    return 0;
}