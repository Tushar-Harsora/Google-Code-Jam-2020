#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main2() {
	int tests;
	cin >> tests;
	for (int x = 1; x <= tests; x++) {
		stringstream ss;
		stack<char> stck;
		string input;
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			while (input[i] - '0' > stck.size()) {
				stck.push('(');
				ss << '(';
			}
			while (input[i] - '0' < stck.size()) {
				stck.pop();
				ss << ')';
			}
			ss << input[i];
		}
		while (!stck.empty()) {
			ss << ')';
			stck.pop();
		}
			
		string ans;
		getline(ss, ans);
		cout << "Case #" << x << ": " << ans << "\n";
	}
	return 0;
}