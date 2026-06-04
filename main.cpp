#include <iostream>
#include <fstream>
#include <vector>

#include <Windows.h>

void coreBypass(std::vector <std::vector<int>>& matrix, int peak, std::vector<bool>& visited) {
	visited[peak] = true;
	std::cout << peak << " ";

	int peaks = matrix.size() - 1;
	for (int j = 1; j <= peaks; ++j) {
		if (matrix[peak][j] == 1 && !visited[j]) {
			coreBypass(matrix, j, visited);
		}
	}
}



int main() {
	SetConsoleOutputCP(1251);
	int lines{}, columns{};
	std::vector <std::vector<int>> matrix{};
	

	std::ifstream file("input.txt");
	if (file.is_open()) {
		file >> columns;
		lines = columns;
		matrix.resize(lines+1, std::vector<int>(columns+1));
		for (int i = 1; i <= lines; ++i) {
			for (int j = 1; j <= columns; ++j) {
				file >> matrix[i][j];
			}
		}
	}
	file.close();

	std::vector <bool> visited(lines + 1, false);

	std::cout << "Порядок обхода вершин: ";
	coreBypass(matrix, 1, visited);
	std::cout << "\n";
	return 0;
}