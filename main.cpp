#include <iostream>
#include "iomanip"
using namespace std;

const int row = 5;
const int col = 5;
const int height = 10;
int count = 0;

void fill_matrix(int array[][col][row], int level) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < row; j++) {
      for (int k = 0; k < col; k++) {
        if (i < level) {
          array[i][count][k] = 1;
        } else
          array[i][count][k] = 0;
      }
    }
  }
}
void print_matrix(int array[][col][row], int slice) {
  bool cycle = true;
  cout << endl;
  for (int i = 0; i < height && cycle; i++) {
    for (int j = 0; j < row; j++) {
      for (int k = 0; k < col; k++) {
        cout << setw(4) << array[slice - 1][j][k];
      }
      cout << endl;
    }
    cout << endl;
    cycle = false;
  }
}
int main() {

  int matrix[height][col][row]{};
  do {
    cout << "Input level`s height " << count + 1 << endl;
    int level;
    cin >> level;
    if (level > 0 && level <= height) {
      fill_matrix(matrix, level);
      count++;
    } else {
      cout << "Enter Error!" << endl;
      continue;
    }

  } while (count < row);

  count = 0;
  do {
    cout << "Input slice: " << count + 1 << endl;
    int slice;
    cin >> slice;
    if (slice > 0 && slice <= height) {
      print_matrix(matrix, slice);
      count++;
    } else {
      cout << "Enter Error!" << endl;
      continue;
    }
  } while (count < height);
}
