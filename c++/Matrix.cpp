#include <iomanip>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Matrix {
   public:
      Matrix();
      Matrix(const Matrix& target);
      void loadFromFile(string filename);
      void saveToFile(string filename);
      int getRowCount();
      int getColCount();
      double getEntry(int row, int col);
      void setRowCount(int size);
      void setColCount(int size);
      bool setEntry(int row, int col, double value);
      void display();
      double getNorm();
      void transpose();   
   private:
      int* rows;
      int* cols;
      double matrix[100][100];
};

Matrix::Matrix() { 
   rows = new int;
   cols = new int;
   *rows = 0;
   *cols = 0;
}

Matrix::Matrix(const Matrix& target) {
   rows = new int;
   cols = new int;
   *rows = *(target.rows);
   *cols = *(target.cols);
   
   for (int i = 0; i < *rows; ++i) {
      for (int j = 0; j < *cols; ++j) {
        matrix[i][j] = target.matrix[i][j];
      }
   }
}

void Matrix::loadFromFile(string filename) {
  ifstream inFS;
  int num1, num2;
   
  inFS.open(filename);
   
  if (!inFS.is_open()) {
    cout << "Unable to open file" << endl;
    return;
  }
   
  inFS >> num1;
  inFS >> num2;
   
  this->setRowCount(num1);
  this->setColCount(num2);
   
  for (int i = 0; i < num1; ++i) {
    for (int j = 0; j < num2; ++j) {
        inFS >> matrix[i][j];
    }
  }
   
  inFS.close();
}

void Matrix::saveToFile(string filename) {
   ofstream outFS;
   
   outFS.open(filename);
   
   if (!outFS.is_open()) {
      cout << "Unable to write to file" << endl;
      return;
   }
   
   outFS << *rows << endl;
   outFS << *cols << endl;
   
   for (int i = 0; i < *rows; ++i) {
      for (int j = 0; j < *cols; ++j) {
         outFS << matrix[i][j];
         if(i != *rows) {
            outFS << " ";
         }
      }
      outFS << endl;
   }
   
   outFS.close();
}
   
// getter method for # of rows
int Matrix::getRowCount() {
   return *rows;
}

// getter method for # of columns
int Matrix::getColCount() {
   return *cols;
}

// getter method for an entry of matrix
double Matrix::getEntry(int row, int col) {
   if ((row > -1 && row < *rows) && (col > -1 && col < *cols)) {
      return matrix[row][col];
   }
   else {
      return NAN;
   }
}

// setter method for # of rows
void Matrix::setRowCount(int size) {
   if (*rows < 0) {
      *rows = 0;
   }
   else if (*rows > 100) {
      *rows = 100;
   }
   else {
      *rows = size;
   }
}

// setter method for # of columns
void Matrix::setColCount(int size) {
   if (*cols < 0) {
      *cols = 0;
   }
   else if (*cols > 100) {
      *cols = 100;
   }
   else {
      *cols = size;
   }
}

// setter method for an entry of matrix
bool Matrix::setEntry(int row, int col, double value) {
   if ((row > -1 && row < *rows) && (col > -1 && col < *cols)) {
      matrix[row][col] = value;
      return true;
   }
   else {
      return false;
   }
}

// print method of matrix
void Matrix::display() {
   for (int i = 0; i < *rows; ++i) {
      cout << " | ";
      for (int j = 0; j < *cols; ++j) {
         cout << fixed << setprecision(2) << setw(6) << matrix[i][j] << " ";
      }
      cout << "| " << endl;
   }
}

double Matrix::getNorm() {
   double total = 0.0; 
   
   for (int i = 0; i < *rows; ++i) {
      for (int j = 0; j < *cols; ++j) {
         total+=pow(matrix[i][j], 2);
      }
   }
   return sqrt(total);
}

// transposed matrix
void Matrix::transpose() {
   double copyMatrix[100][100];
   int k = 0;
   
   for (int i = 0; i < *rows; ++i) {
      for (int j = 0; j < *cols; ++j) {
         copyMatrix[k][i] = matrix[i][j];
         k = k + 1;
      }
      k = 0;
   }
   
   for (int i = 0; i < *cols; ++i) {
      for (int j = 0; j < *rows; ++j) {
         matrix[i][j] = copyMatrix[i][j];
      }
   }
   
   int num1 = *cols;
   int num2 = *rows;
   
   this->setRowCount(num1);
   this->setColCount(num2);
}

int main() {
   // 1.
   Matrix matrix;
   string fileName;
   int row, col;
   double value;
   
   // 2.
   cout << "Enter the file to load: ";
   cin >> fileName;
   cout << endl;
   
   // 3.
   matrix.loadFromFile(fileName);
   
   // 4.
   matrix.display();
   
   // 5.
   cout << "The Frobenius Norm is " << matrix.getNorm() << endl;
   
   // 6.
   cout << "Enter the row: ";
   cin >> row;
   cout << endl;
   // 7.
   cout << "Enter the col: ";
   cin >> col;
   cout << endl;
   // 8.
   cout << "Enter the value: ";
   cin >> value;
   cout << endl;
   // 9.
   matrix.setEntry(row, col, value);
   
   // 10.
   Matrix newMatrix = matrix;
   
   // 11.
   newMatrix.transpose();
   
   // 12.
   newMatrix.saveToFile("A1.txt");
   
   // 13.
   matrix.display();
   
   // 14.
   return 0;
}
