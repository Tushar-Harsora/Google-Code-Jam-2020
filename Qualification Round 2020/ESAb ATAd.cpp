#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void ask_question(int question) {
	cout << question << endl << flush;
}

int get_answer() {
	int value;
	cin >> value;
	return value;
}

int main() {
	int tests, bits;
	cin >> tests >> bits;
	for (int x = 1; x <= tests; x++) {
		vector<int> data(bits + 1, -1);
		pair<int, int> same{ -1,-1 };
		pair<int, int> not_same{ -1,-1 };
		int left = 0, right = bits + 1;
		bool left_turn = true;
		bool is_done = false;
		for (int query = 0; query < 150; query++) {
			int question = -1;
			if (query % 10 == 0 && query != 0) {		// Fluctuation Occurs
				cerr << "Change Array!!!" << endl;
				same = { -1,-1 };
				not_same = { -1,-1 };

				for (int i = 1; i <= bits / 2; i++) {
					if ((data[i] != -1) && (data[bits + 1 - i] != -1)) {
						if (data[i] == data[bits + 1 - i]) {
							same = { i, bits + 1 - i };
						}
						else {
							not_same = { i,bits + 1 - i };
						}
					}
				}
				bool nc = true, rev = true, inv = true, invrev = true;
				int same_first_ind, same_second_ind;
				int not_same_first_ind, not_same_second_ind;
				if (same != make_pair(-1, -1)) {
					ask_question(same.first);
					same_first_ind = get_answer();
					ask_question(same.second);
					same_second_ind = get_answer();

					if (make_pair(data[same.first], data[same.second]) == make_pair(same_first_ind, same_second_ind)) {
						invrev = false;
						inv = false;
					}
					else {
						rev = false;
						nc = false;
					}
				}
				if (not_same != make_pair(-1, -1)) {
					ask_question(not_same.first);
					not_same_first_ind = get_answer();
					ask_question(not_same.second);
					not_same_second_ind = get_answer();

					if (make_pair(data[not_same.first], data[not_same.second]) == make_pair(not_same_first_ind, not_same_second_ind)) {
						rev = false;
						inv = false;
					}
					else {
						invrev = false;
						nc = false;
					}
				}
				if (nc) {
					// Do Nothing
				}
				else if (rev) {
					reverse(data.begin() + 1, data.end());
					left = bits - left + 1;
					right = bits - right + 1;
					swap(left, right);
				}
				else if (inv) {
					for (int i = 1; i < data.size(); i++) {
						data[i] = data[i] == 1 ? 0 : 1;
					}
				}
				else {
					reverse(data.begin() + 1, data.end());
					for (int i = 1; i < data.size(); i++) {
						if (data[i] == -1)
							continue;
						data[i] = data[i] == 1 ? 0 : 1;
					}
					left = bits - left + 1;
					right = bits - right + 1;
					swap(left, right);
				}
				query += 3;
				continue;
			}

			if (left_turn) {
				left++;
				if (data[left] == -1) {				// We Dont Have Bit
					question = left;
				}
				left_turn = false;
			}
			else {
				right--;
				if (data[right] == -1) {
					question = right;
				}
				left_turn = true;
			}
			ask_question(question);
			data[question] = get_answer();
			if (right - 1 == left) {				// Done Array
				is_done = true;
				break;
			}
		}
		
		copy(data.begin() + 1, data.end(), ostream_iterator<int>(cout));
		cout << endl << flush;
		char ch;
		cin >> ch;
		if (ch == 'N') {
			return 0;
		}
		
	}
	return 0;
}