#include <iostream>
#include <vector>

using namespace std;

bool if_element_exists(vector<vector<int>>& matrix, pair<int, int> position, int value) {
	for (int i = 0; i < matrix.size(); i++) {					// Check Rows
		if (value == matrix[position.first][i]);
	}
	return false;
}