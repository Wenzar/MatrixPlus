#include <cmath>
#include <cstring>
#include <iostream>

#include "gtest/gtest.h"

class S21Matrix {
 private:
  // Attributes
  int rows_ = 0, cols_ = 0;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated
  void Create();
  void Swap(S21Matrix &other);
  void Copy(const S21Matrix &other);

 public:
  S21Matrix();  // Default constructor
  S21Matrix(int rows_, int cols_);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();  // Destructor

  bool EqMatrix(const S21Matrix &other);

  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalculateMinor(int row, int cols);
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  int GetRows();
  int GetCols();
  void SetRows(int rows);
  void SetCols(int cols);
  double *operator[](int index);

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double value);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double value);
  double &operator()(const int row, const int column);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other);
};
