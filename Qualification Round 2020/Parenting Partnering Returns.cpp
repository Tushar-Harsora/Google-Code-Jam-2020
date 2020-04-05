#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

int main3() {
	int tests;
	cin >> tests;
	for (int x = 1; x <= tests; x++) {
		int n;
		cin >> n;
		vector<char> tasks(n);
		vector<vector<pair<int, int>>> timeline(24 * 60 + 1);
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			timeline[a].push_back({ 1, i });
			timeline[b].push_back({ -1, i });
		}
		
		for (int i = 0; i < timeline.size(); i++) {		// Ending Times Will Be At Front
			sort(timeline[i].begin(), timeline[i].end());
		}

		int cameron = 0, jamie = 0;
		for (int i = 0; i < timeline.size(); i++) {
			for (const auto& ele : timeline[i]) {
				if (ele.first == 1) {
					if (cameron != 0 && jamie != 0) {
						cout << "Case #" << x << ": " << "IMPOSSIBLE" << "\n";
						goto ends;
					}
					if (cameron == 0) {			// Cameron Is Free
						cameron = ele.second;
					}
					else {						// Jamie Is Free
						jamie = ele.second;
					}
				}
				else {
					if (cameron == 0 && jamie == 0)
						return -1;
					int completed = ele.second;
					if (jamie == completed) {
						tasks[jamie - 1] = 'J';
						jamie = 0;
					}
					else {
						tasks[cameron - 1] = 'C';
						cameron = 0;
					}
				}
			}
		}
		cout << "Case #" << x << ": ";
		copy(tasks.begin(), tasks.end(), ostream_iterator<char>(cout));
		cout << "\n";
	ends:;
	}
	return 0;
}