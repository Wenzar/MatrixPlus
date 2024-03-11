#include "s21_matrix_oop.h"

void S21Matrix::Create() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int k = 0; k < cols_; k++) {
      matrix_[i][k] = 0;
    }
  }
}

S21Matrix::S21Matrix() : rows_(2), cols_(2) { Create(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Incorrect cols and rows value");
  }
  Create();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  Create();
  Copy(other);
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  // Освобождаем ресурсы, выделенные под матрицу
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  int error = 1;  // Инициализируем переменную error как успешное выполнение
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    error = 0;  // Размеры матриц не совпадают
  } else {
    for (int i = 0; i < rows_ && error; i++) {
      for (int j = 0; j < cols_ && error; j++) {
        double diff = fabs(matrix_[i][j] - other.matrix_[i][j]);
        if (matrix_[i][j] != other.matrix_[i][j] && diff > 1e-7) {
          error = 0;  // Элементы матриц не совпадают
        }
      }
    }
  }
  return error;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_) {
    throw std::invalid_argument("Invalid matrix size.");
  }
  try {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } catch (const std::exception &err) {
    throw std::invalid_argument(err.what());
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_) {
    throw std::invalid_argument("Invalid matrix size.");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  try {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] *= num;
      }
    }
  } catch (const std::exception &err) {
    throw std::invalid_argument(err.what());
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Invalid matrix size.");
  }
  try {
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < cols_; k++) {
          result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    Swap(result);
  }

  catch (const std::exception &err) {
    throw std::invalid_argument(err.what());
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix must be square");
  }

  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int j = 0; j < cols_; j++) {
      int sign = j % 2 == 0 ? 1 : -1;

      result += sign * matrix_[0][j] * CalculateMinor(0, j).Determinant();
    }
  }

  return result;
}

S21Matrix S21Matrix::CalculateMinor(int row, int cols) {
  S21Matrix minor_matrix(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (i != row && j != cols)
        minor_matrix.matrix_[i - (i > row)][j - (j > cols)] = matrix_[i][j];

  return minor_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix must be square");
  }
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      const double sign = (i + j) % 2 == 0 ? 1 : -1;
      result.matrix_[i][j] = sign * CalculateMinor(i, j).Determinant();
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (std::abs(determinant) < 0.0000001) {
    throw std::invalid_argument("Matrix is not invertible");
  }

  S21Matrix complements = CalcComplements();
  S21Matrix transposedComplements = complements.Transpose();
  determinant = 1.0f / determinant;

  if (rows_ > 1) {
    transposedComplements.MulNumber(determinant);
  } else {
    transposedComplements.matrix_[0][0] = determinant;
  }

  return transposedComplements;
}

void S21Matrix::Swap(S21Matrix &other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

void S21Matrix::Copy(const S21Matrix &other) {
  const int rows = std::min(rows_, other.rows_);
  const int columns = std::min(cols_, other.cols_);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) throw std::invalid_argument("Invalid rows count");
  S21Matrix tmp(rows, cols_);
  tmp.Copy(*this);
  Swap(tmp);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) throw std::invalid_argument("Invalid columns count");
  S21Matrix tmp(rows_, cols);
  tmp.Copy(*this);
  Swap(tmp);
}

/// @brief Оператор доступа к элементам матрицы
/// @param index
/// @return
double *S21Matrix::operator[](int index) {
  if (index < 0) {
    throw std::out_of_range("Index is out of range");
  }
  return matrix_[index];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result = S21Matrix(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result = S21Matrix(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result = S21Matrix(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double value) {
  S21Matrix result = S21Matrix(*this);
  result.MulNumber(value);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double value) {
  MulNumber(value);
  return *this;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  Copy(other);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  Swap(other);
  return *this;
}