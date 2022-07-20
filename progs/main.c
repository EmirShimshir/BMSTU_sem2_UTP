#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define INPUT_ERROR 1

#define N 100

typedef int matrix_t[N][N];

unsigned long long microseconds_now(void);
void matrix_mult_no_trans(matrix_t a, matrix_t b, matrix_t c, size_t n);
void matrix_mult_first_trans(matrix_t a, matrix_t b, matrix_t c, size_t n);
void matrix_mult_second_trans(matrix_t a, matrix_t b, matrix_t c, size_t n);
void transpose(matrix_t a, size_t n);
void init_matrix(matrix_t a, size_t n);
void print_matrix_file(matrix_t a, size_t n, FILE *file);
// void print_matrix(matrix_t a,size_t n);

matrix_t a;
matrix_t b;
matrix_t c;

int main(int argc, char *argv[])
{
    if (argc != 3)
        return INPUT_ERROR;

    size_t n = atoi(argv[1]);
    char *prog = argv[2];

    srand(time(NULL));
    init_matrix(a, n);
    // print_matrix(a, n);
    init_matrix(b, n);
    // print_matrix(b, n);

    unsigned long long beg, end;

    if (strcmp("transpose_no", prog) == 0)
    {
        beg = microseconds_now();
        matrix_mult_no_trans(a, b, c, n);
        // print_matrix(c, n);
        end = microseconds_now();
    }
    else if (strcmp("transpose_first", prog) == 0)
    {
        beg = microseconds_now();
        matrix_mult_first_trans(a, b, c, n);
        // print_matrix(c, n);
        end = microseconds_now();
    }
    else if (strcmp("transpose_second", prog) == 0)
    {
        beg = microseconds_now();
        matrix_mult_second_trans(a, b, c, n);
        // print_matrix(c, n);
        end = microseconds_now();
    }
    else
        return INPUT_ERROR;

    printf("%llu\n", (end - beg));

    a[0][0] = b[0][0];
    b[0][0] = c[0][0];
    c[0][0] = a[0][0];

    FILE *check_result = fopen("../progs/result/check_result.txt", "w");
    print_matrix_file(a, n, check_result);
    print_matrix_file(b, n, check_result);
    print_matrix_file(c, n, check_result);
    fclose(check_result);

    return EXIT_SUCCESS;
}

void init_matrix(matrix_t a, size_t n)
{   
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            a[i][j] = rand() % 100 - 50;
}

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}

void transpose(matrix_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

void matrix_mult_no_trans(matrix_t a, matrix_t b, matrix_t c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int element = 0;
            for (size_t k = 0; k < n; k++)
            {
                element += a[i][k] * b[k][j];
            }
            c[i][j] = element;
        }
    }
}

void matrix_mult_second_trans(matrix_t a, matrix_t b, matrix_t c, size_t n)
{
    transpose(b, n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int element = 0;
            for (size_t k = 0; k < n; k++)
            {
                element += a[i][k] * b[j][k];
            }
            c[i][j] = element;
        }
    }
    transpose(b, n);
}

void matrix_mult_first_trans(matrix_t a, matrix_t b, matrix_t c, size_t n)
{
    transpose(a, n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int element = 0;
            for (size_t k = 0; k < n; k++)
            {
                element += a[k][i] * b[k][j];
            }
            c[i][j] = element;
        }
    }
    transpose(a, n);
}

void print_matrix_file(matrix_t a, size_t n, FILE *file)
{
    fprintf(file, "Matrix:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            fprintf(file, "%d ", a[i][j]);
        }
        fprintf(file, "\n");
    }
}

// void print_matrix(matrix_t a, size_t n)
// {
//     printf("Matrix:\n");
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
// }
