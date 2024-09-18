#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;

struct Matrix {
  int **matrix;
  int rows;
  int cols;

  void(*print_matrix)(Matrix *self);
  void(*reassign_matrix)(Matrix *self, int rows, int cols, int matrix[rows][cols]);
};

void print_matrix(Matrix *self);
void reassagin_matrix(Matrix *self, int rows, int cols, int matrix[rows][cols]);

Matrix *init_matrix(int rows, int cols);
Matrix *add_matrices(Matrix *m1, Matrix *m2);
Matrix *multiply_matrices(Matrix *m1, Matrix *m2);

Matrix *init_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->matrix = malloc(rows * sizeof(int*));
  
  for (int i = 0; i < rows; i++) {
    matrix->matrix[i] = malloc(cols * sizeof(int));
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->matrix[i][j] = 0;
    }
  }

  matrix->rows = rows;
  matrix->cols = cols;
  matrix->print_matrix = print_matrix;
  matrix->reassign_matrix = reassagin_matrix;

  return matrix;
}

void print_matrix(Matrix *self) {
  for (int i = 0; i < self->rows; i++) {
    for (int j = 0; j < self->cols; j++) {
      printf("%d ", self->matrix[i][j]);
    }
    printf("\n");
  }
}

void reassagin_matrix(Matrix *self, int rows, int cols, int matrix[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      self->matrix[i][j] = matrix[i][j];
    }
  }
}

Matrix *add_matrices(Matrix *m1, Matrix *m2) {
  Matrix *res = init_matrix(m1->rows, m1->cols);

  for (int i = 0; i < res->rows; i++) {
    for (int j = 0; j < res->cols; j++) {
      res->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
    }
  }
  return res;
}

Matrix *multiply_matrices(Matrix *m1, Matrix *m2) {
  Matrix *prod = init_matrix(m1->rows, m2->cols);
  for (int i = 0; i < prod->rows; i++) {
    for (int j = 0; j < prod->cols; j++) {
      for (int k = 0; k < m1->cols; k++) {
        prod->matrix[i][j] += m1->matrix[i][k] * m2->matrix[k][j];
      }
    }
  }
  return prod;
}

#endif //MATRIX_UTILS_H