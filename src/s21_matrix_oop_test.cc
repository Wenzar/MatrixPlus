#include "s21_matrix_oop.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return (RUN_ALL_TESTS());
}

TEST(EqMatrix, not_eq) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2 = S21Matrix();

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrix, not_eq1) {
  S21Matrix matrix1(3, 3);
  S21Matrix matrix2(3, 3);
  matrix2[1][0] = 1;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(SumMatrix, eq) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 3);
  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[0][2] = 3;
  matrix1[1][0] = 4;
  matrix1[1][1] = 5;
  matrix1[1][2] = 6;

  matrix2[0][0] = 7;
  matrix2[0][1] = 8;
  matrix2[0][2] = 9;
  matrix2[1][0] = 10;
  matrix2[1][1] = 11;
  matrix2[1][2] = 12;

  matrix1.SumMatrix(matrix2);

  EXPECT_EQ(matrix1[0][0], 8);
  EXPECT_EQ(matrix1[0][1], 10);
  EXPECT_EQ(matrix1[0][2], 12);
  EXPECT_EQ(matrix1[1][0], 14);
  EXPECT_EQ(matrix1[1][1], 16);
  EXPECT_EQ(matrix1[1][2], 18);
}

TEST(SubMatrix, eq) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 3);
  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[0][2] = 3;
  matrix1[1][0] = 4;
  matrix1[1][1] = 5;
  matrix1[1][2] = 6;

  matrix2[0][0] = 7;
  matrix2[0][1] = 8;
  matrix2[0][2] = 9;
  matrix2[1][0] = 10;
  matrix2[1][1] = 11;
  matrix2[1][2] = 12;

  matrix1.SubMatrix(matrix2);

  EXPECT_EQ(matrix1[0][0], -6);
  EXPECT_EQ(matrix1[0][1], -6);
  EXPECT_EQ(matrix1[0][2], -6);
  EXPECT_EQ(matrix1[1][0], -6);
  EXPECT_EQ(matrix1[1][1], -6);
  EXPECT_EQ(matrix1[1][2], -6);
}

TEST(MulNumber, eq) {
  S21Matrix matrix1(2, 3);

  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[0][2] = 3;
  matrix1[1][0] = 4;
  matrix1[1][1] = 5;
  matrix1[1][2] = 333333333;

  double number = 3.56;
  matrix1.MulNumber(number);

  EXPECT_EQ(matrix1[0][0], 3.56);
  EXPECT_EQ(matrix1[0][1], 7.12);
  EXPECT_EQ(matrix1[1][1], 17.8);
  EXPECT_EQ(matrix1[1][2], 1186666665.48);
}

TEST(MulMatrix, MulMatrix1) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[0][2] = 3;
  matrix1[1][0] = 4;
  matrix1[1][1] = 5;
  matrix1[1][2] = 6;

  matrix2[0][0] = 7;
  matrix2[0][1] = 8;
  matrix2[1][0] = 9;
  matrix2[1][1] = 10;
  matrix2[2][0] = 11;
  matrix2[2][1] = 12;

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1[0][0], 58);
  EXPECT_EQ(matrix1[0][1], 64);
  EXPECT_EQ(matrix1[1][0], 139);
  EXPECT_EQ(matrix1[1][1], 154);
}

TEST(Transpose, Transpose1) {
  S21Matrix matrix1(2, 2);
  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[1][0] = 3;
  matrix1[1][1] = 4;

  S21Matrix matrix2 = matrix1.Transpose();

  EXPECT_EQ(matrix2[0][0], 1);
  EXPECT_EQ(matrix2[0][1], 3);
  EXPECT_EQ(matrix2[1][0], 2);
  EXPECT_EQ(matrix2[1][1], 4);
}

TEST(Determinant, Determinant11) {
  S21Matrix matrix(1, 1);
  matrix[0][0] = 3;
  double det = matrix.Determinant();
  EXPECT_EQ(det, 3);
}

TEST(Determinant, Determinant12) {
  S21Matrix matrix(4, 4);
  matrix[0][0] = 3;
  double det = matrix.Determinant();
  EXPECT_EQ(det, 0);
}

TEST(CalcComplements, CalcComplements1) {
  S21Matrix matrix1(3, 3);
  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[0][2] = 3;
  matrix1[1][0] = 4;
  matrix1[1][1] = 5;
  matrix1[1][2] = 6;
  matrix1[2][0] = 7;
  matrix1[2][1] = 8;
  matrix1[2][2] = 9;

  S21Matrix matrix2 = matrix1.CalcComplements();

  EXPECT_EQ(matrix2[0][0], -3);
  EXPECT_EQ(matrix2[0][1], 6);
  EXPECT_EQ(matrix2[0][2], -3);
  EXPECT_EQ(matrix2[1][0], 6);
  EXPECT_EQ(matrix2[1][1], -12);
  EXPECT_EQ(matrix2[1][2], 6);
  EXPECT_EQ(matrix2[2][0], -3);
  EXPECT_EQ(matrix2[2][1], 6);
  EXPECT_EQ(matrix2[2][2], -3);
}

TEST(InverseMatrix, InverseMatrix16) {
  S21Matrix matrix(3, 3);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = 4;
  matrix[2][0] = 5;
  matrix[2][1] = 6;
  matrix[2][2] = 10;

  S21Matrix invertedMatrix = matrix.InverseMatrix();

  matrix.MulMatrix(invertedMatrix);

  EXPECT_NEAR(matrix[0][0], 1, 0.0000001);
  EXPECT_NEAR(matrix[0][1], 0, 0.0000001);
  EXPECT_NEAR(matrix[0][2], 0, 0.0000001);
  EXPECT_NEAR(matrix[1][0], 0, 0.0000001);
  EXPECT_NEAR(matrix[1][1], 1, 0.0000001);
  EXPECT_NEAR(matrix[1][2], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][0], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][1], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][2], 1, 0.0000001);
}

TEST(S21Matrix, inverseMatrixTest25) {
  S21Matrix matrix(2, 5);

  try {
    S21Matrix result = matrix.InverseMatrix();
  } catch (std::invalid_argument &err) {
    EXPECT_STREQ(err.what(), "Matrix must be square");
  }
}

TEST(inverseMatrix, inverseMatrix3) {
  S21Matrix matrix(2, 2);

  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[1][0] = 0;
  matrix[1][1] = 0;

  try {
    S21Matrix result = matrix.InverseMatrix();
  } catch (std::invalid_argument &err) {
    EXPECT_STREQ(err.what(), "Matrix is not invertible");
  }
}

TEST(S21Matrix, assignmentOperator2) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(2, 2);
  B[0][0] = 7;
  B[0][1] = 8;
  B[1][0] = 9;
  B[1][1] = 10;

  try {
    A = B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix dimensions must agree");
  }
}

TEST(S21Matrix, assignmentPlusOperator) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(3, 3);
  B[0][0] = 7;
  B[0][1] = 8;
  B[0][2] = 9;
  B[1][0] = 10;
  B[1][1] = 11;
  B[1][2] = 12;

  A += B;

  EXPECT_EQ(A[0][0], 8);
  EXPECT_EQ(A[0][1], 10);
  EXPECT_EQ(A[0][2], 12);
  EXPECT_EQ(A[1][0], 14);
  EXPECT_EQ(A[1][1], 16);
  EXPECT_EQ(A[1][2], 18);
}

TEST(S21Matrix, assignmentPlusOperator2) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(2, 2);
  B[0][0] = 7;
  B[0][1] = 8;
  B[1][0] = 9;
  B[1][1] = 10;

  try {
    A += B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Invalid matrix size.");
  }
}

TEST(S21Matrix, assignmentMinusOperator) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(3, 3);
  B[0][0] = 7;
  B[0][1] = 8;
  B[0][2] = 9;
  B[1][0] = 10;
  B[1][1] = 11;
  B[1][2] = 12;

  A -= B;

  EXPECT_EQ(A[0][0], -6);
  EXPECT_EQ(A[0][1], -6);
  EXPECT_EQ(A[0][2], -6);
  EXPECT_EQ(A[1][0], -6);
  EXPECT_EQ(A[1][1], -6);
  EXPECT_EQ(A[1][2], -6);
}

TEST(S21Matrix, assignmentMinusOperator2) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(2, 2);
  B[0][0] = 7;
  B[0][1] = 8;
  B[1][0] = 9;
  B[1][1] = 10;

  try {
    A -= B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Invalid matrix size.");
  }
}

TEST(S21Matrix, assignmentMulOperator) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(3, 3);
  B[0][0] = 7;
  B[0][1] = 8;
  B[0][2] = 9;
  B[1][0] = 10;
  B[1][1] = 11;
  B[1][2] = 12;

  A *= B;

  EXPECT_EQ(A[0][0], 27);
  EXPECT_EQ(A[0][1], 30);
  EXPECT_EQ(A[0][2], 33);
  EXPECT_EQ(A[1][0], 78);
  EXPECT_EQ(A[1][1], 87);
  EXPECT_EQ(A[1][2], 96);
}

TEST(S21Matrix, assignmentMulOperator2) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(2, 2);
  B[0][0] = 7;
  B[0][1] = 8;
  B[1][0] = 9;
  B[1][1] = 10;

  try {
    A *= B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Invalid matrix size.");
  }
}

TEST(S21Matrix, assignmentMulNumberOperator) {
  S21Matrix A(3, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  A *= 2;

  EXPECT_EQ(A[0][0], 2);
  EXPECT_EQ(A[0][1], 4);
  EXPECT_EQ(A[0][2], 6);
  EXPECT_EQ(A[1][0], 8);
  EXPECT_EQ(A[1][1], 10);
  EXPECT_EQ(A[1][2], 12);
}

TEST(S21Matrix, eqOperator) {
  S21Matrix A(2, 2);
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;

  S21Matrix B(2, 2);
  B[0][0] = 1;
  B[0][1] = 2;
  B[1][0] = 3;
  B[1][1] = 4;

  EXPECT_TRUE(A == B);
}

TEST(S21Matrix, assignmentMulMatrix) {
  S21Matrix A(2, 3);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;

  S21Matrix B(3, 2);
  B[0][0] = 7;
  B[0][1] = 8;
  B[1][0] = 9;
  B[1][1] = 10;
  B[2][0] = 11;
  B[2][1] = 12;

  S21Matrix C = A * B;

  EXPECT_EQ(C[0][0], 58);
  EXPECT_EQ(C[0][1], 64);
  EXPECT_EQ(C[1][0], 139);
  EXPECT_EQ(C[1][1], 154);
}

TEST(S21Matrix, transposeTest1) {
  S21Matrix A(2, 2);
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;

  S21Matrix B = A.Transpose();

  EXPECT_EQ(B[0][0], 1);
  EXPECT_EQ(B[0][1], 3);
  EXPECT_EQ(B[1][0], 2);
  EXPECT_EQ(B[1][1], 4);
}

TEST(S21Matrix, transposeTest2) {
  S21Matrix A(2, 4);
  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[0][3] = 4;
  A[1][0] = 5;
  A[1][1] = 6;
  A[1][2] = 7;
  A[1][3] = 8;

  S21Matrix B = A.Transpose();

  EXPECT_EQ(B[0][0], 1);
  EXPECT_EQ(B[0][1], 5);
  EXPECT_EQ(B[1][0], 2);
  EXPECT_EQ(B[1][1], 6);
  EXPECT_EQ(B[2][0], 3);
  EXPECT_EQ(B[2][1], 7);
  EXPECT_EQ(B[3][0], 4);
  EXPECT_EQ(B[3][1], 8);

  EXPECT_EQ(B.GetRows(), 4);
  EXPECT_EQ(B.GetCols(), 2);
}

TEST(S21Matrix, transposeTest3) {
  S21Matrix A(3, 1);

  A[0][0] = 1;
  A[1][0] = 2;
  A[2][0] = 3;

  S21Matrix B = A.Transpose();

  EXPECT_EQ(B[0][0], 1);
  EXPECT_EQ(B[0][1], 2);
  EXPECT_EQ(B[0][2], 3);
  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetCols(), 3);
}

TEST(S21Matrix, GetRows) {
  S21Matrix matrix(7, 4);
  ASSERT_EQ(matrix.GetRows(), 7);
  ASSERT_EQ(matrix.GetCols(), 4);
}

TEST(S21Matrix, matrix2) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix1(matrix);

  ASSERT_TRUE(matrix.EqMatrix(matrix1));
}

TEST(S21Matrix, matrix4) {
  S21Matrix matrix(2, 8);

  try {
    matrix.SetRows(0);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid rows count");
  }
}

TEST(S21Matrix, SetRows) {
  S21Matrix matrix(81, 242);

  matrix.SetRows(3);
  matrix.SetCols(31);

  ASSERT_EQ(matrix.GetRows(), 3);
  ASSERT_EQ(matrix.GetCols(), 31);

  matrix.SetRows(100);
  matrix.SetCols(90);

  ASSERT_EQ(matrix.GetRows(), 100);
  ASSERT_EQ(matrix.GetCols(), 90);

  try {
    matrix.SetRows(0);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid rows count");
  }

  try {
    matrix.SetCols(-10);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid columns count");
  }
}

TEST(S21Matrix, SetCols) {
  S21Matrix matrix(3, 3);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;

  matrix.SetCols(5);
  matrix.SetRows(5);

  ASSERT_EQ(matrix.GetRows(), 5);
  ASSERT_EQ(matrix.GetCols(), 5);

  EXPECT_EQ(matrix[0][0], 1);
  EXPECT_EQ(matrix[0][1], 2);
  EXPECT_EQ(matrix[0][2], 3);
  EXPECT_EQ(matrix[1][0], 4);
  EXPECT_EQ(matrix[1][1], 5);
  EXPECT_EQ(matrix[1][2], 6);
  EXPECT_EQ(matrix[2][0], 7);
  EXPECT_EQ(matrix[2][1], 8);
  EXPECT_EQ(matrix[2][2], 9);
  EXPECT_EQ(matrix[3][0], 0);
  EXPECT_EQ(matrix[3][1], 0);
  EXPECT_EQ(matrix[3][2], 0);
  EXPECT_EQ(matrix[4][0], 0);
  EXPECT_EQ(matrix[4][1], 0);
  EXPECT_EQ(matrix[4][2], 0);
}

TEST(S21Matrix, InverseMatrix) {
  S21Matrix matrix(3, 3);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = 4;
  matrix[2][0] = 5;
  matrix[2][1] = 6;
  matrix[2][2] = 10;

  S21Matrix invertedMatrix = matrix.InverseMatrix();

  matrix.MulMatrix(invertedMatrix);

  EXPECT_NEAR(matrix[0][0], 1, 0.0000001);
  EXPECT_NEAR(matrix[0][1], 0, 0.0000001);
  EXPECT_NEAR(matrix[0][2], 0, 0.0000001);
  EXPECT_NEAR(matrix[1][0], 0, 0.0000001);
  EXPECT_NEAR(matrix[1][1], 1, 0.0000001);
  EXPECT_NEAR(matrix[1][2], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][0], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][1], 0, 0.0000001);
  EXPECT_NEAR(matrix[2][2], 1, 0.0000001);
}

TEST(S21Matrix, inverseMatrixTest2) {
  S21Matrix A(2, 5);

  try {
    S21Matrix result = A.InverseMatrix();
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix must be square");
  }
}

TEST(S21Matrix, inverseMatrixTest3) {
  S21Matrix A(2, 2);

  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 0;
  A[1][1] = 0;

  try {
    S21Matrix result = A.InverseMatrix();
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix is not invertible");
  }
}

TEST(S21Matrix, inverseMatrixTest4) {
  S21Matrix A(5, 5);
  A[0][0] = 12;
  A[0][1] = 2.254353453;
  A[0][2] = 335.534534;
  A[0][3] = 4.5334;
  A[0][4] = 5.423;
  A[1][0] = 0.5433;
  A[1][1] = 1;
  A[1][2] = 4.53453;
  A[1][3] = 230;
  A[1][4] = 3520.53453;
  A[2][0] = 5.000001;
  A[2][1] = 6.0000235;
  A[2][2] = 50;
  A[2][3] = 76.534;
  A[2][4] = 50.534;
  A[3][0] = 7457.5435;
  A[3][1] = 0.000002;
  A[3][2] = 3554774.5670;
  A[3][3] = 1.532543;
  A[3][4] = 3.3232;
  A[4][0] = 6346.5345;
  A[4][1] = 450.434543;
  A[4][2] = 4352;
  A[4][3] = 705345353453;
  A[4][4] = 631;

  S21Matrix inverseMatrix = A.InverseMatrix();

  A.MulMatrix(inverseMatrix);

  EXPECT_NEAR(A[0][0], 1, 0.0000001);
  EXPECT_NEAR(A[0][1], 0, 0.0000001);
  EXPECT_NEAR(A[0][2], 0, 0.0000001);
  EXPECT_NEAR(A[0][3], 0, 0.0000001);
  EXPECT_NEAR(A[0][4], 0, 0.0000001);
  EXPECT_NEAR(A[1][0], 0, 0.0000001);
  EXPECT_NEAR(A[1][1], 1, 0.0000001);
  EXPECT_NEAR(A[1][2], 0, 0.0000001);
  EXPECT_NEAR(A[1][3], 0, 0.0000001);
  EXPECT_NEAR(A[1][4], 0, 0.0000001);
  EXPECT_NEAR(A[2][0], 0, 0.0000001);
  EXPECT_NEAR(A[2][1], 0, 0.0000001);
  EXPECT_NEAR(A[2][2], 1, 0.0000001);
  EXPECT_NEAR(A[2][3], 0, 0.0000001);
  EXPECT_NEAR(A[2][4], 0, 0.0000001);
  EXPECT_NEAR(A[3][0], 0, 0.0000001);
  EXPECT_NEAR(A[3][1], 0, 0.0000001);
  EXPECT_NEAR(A[3][2], 0, 0.0000001);
  EXPECT_NEAR(A[3][3], 1, 0.0000001);
  EXPECT_NEAR(A[3][4], 0, 0.0000001);
  EXPECT_NEAR(A[4][0], 0, 0.0000001);
  EXPECT_NEAR(A[4][1], 0, 0.0000001);
  EXPECT_NEAR(A[4][2], 0, 0.0000001);
  EXPECT_NEAR(A[4][3], 0, 0.0000001);
  EXPECT_NEAR(A[4][4], 1, 0.0000001);
}

TEST(S21Matrix, SubMatrix2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);

  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;
  A[2][0] = 7;
  A[2][1] = 8;
  A[2][2] = 9;

  B[0][0] = 1;
  B[0][1] = 2;
  B[0][2] = 3;
  B[1][0] = 4;
  B[1][1] = 5;
  B[1][2] = 6;
  B[2][0] = 7;
  B[2][1] = 8;
  B[2][2] = 9;

  S21Matrix C = A - B;

  for (int i = 0; i < C.GetRows(); i++) {
    for (int j = 0; j < C.GetCols(); j++) {
      ASSERT_EQ(C[i][j], 0);
    }
  }
}

TEST(S21Matrix, SumMatrix2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);

  A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 6;
  A[2][0] = 7;
  A[2][1] = 8;
  A[2][2] = 9;

  B[0][0] = -1;
  B[0][1] = -2;
  B[0][2] = -3;
  B[1][0] = -4;
  B[1][1] = -5;
  B[1][2] = -6;
  B[2][0] = -7;
  B[2][1] = -8;
  B[2][2] = -9;

  S21Matrix C = A + B;

  for (int i = 0; i < C.GetRows(); i++) {
    for (int j = 0; j < C.GetCols(); j++) {
      ASSERT_EQ(C[i][j], 0);
    }
  }
}

TEST(S21Matrix, MumMatrix2) {
  S21Matrix A(2, 2);

  A[0][0] = 1;
  A[0][1] = 2;

  A[1][0] = 4;
  A[1][1] = 5;

  S21Matrix C = A * 1;

  ASSERT_EQ(C[0][0], 1);
  ASSERT_EQ(C[0][1], 2);
  ASSERT_EQ(C[1][0], 4);
  ASSERT_EQ(C[1][1], 5);
}

TEST(S21Matrix, Matrix2334) {
  S21Matrix A(2, 2);

  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 4;
  A[1][1] = 5;

  S21Matrix C = S21Matrix(std::move(A));

  ASSERT_EQ(C[0][0], 1);
  ASSERT_EQ(C[0][1], 2);
  ASSERT_EQ(C[1][0], 4);
  ASSERT_EQ(C[1][1], 5);
}
