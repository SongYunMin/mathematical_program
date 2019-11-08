#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
		작성자 :		송윤민
		최초작성일 : 2019.10.11일
		실행환경 :	Visual Studio 2017
		작성목적 :	C 이용 행렬곱 구현
		필요사항 :	제어변수 변화에 따른 실행시간, 메모리 사용량 변화 측정

		수정사항 :	2019-10-11-23:12 -	기본적인 행렬곱 (IJK) 프로그램 작성
					2019-10-26-10:23 -	제어변수 변화
					2019-10-28-00-57 -	2차원 동적할당은 메모리가 불 규칙적으로 사용된다
										또한 1차원 할당을 받았을때는 메모리가 규칙적으로 사용된다.
					2019-11-09-03-53 -	행 우선 언어에서 가장 빠른 알고리즘은 제어변수 IKJ 순서 알고리즘

		오류사항 :	2019-10-27-00:49 - 시간변수 for문에 따라 time 이상하게 출력됨
*/

int num;		// N의 크기
clock_t start_1, end_1;

// 행렬 출력을 위한 함수
void print_Matrix(int ** MATRIX)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%10.1d", MATRIX[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// IKJ행렬곱 계산 함수
void matrix_multiply(int ** A_Matrix, int ** B_Matrix,
	int ** Result_Matrix)
{
	start_1 = clock();
	for (int i = 0; i < num; i++) {
		for (int k = 0; k < num; k++) {
			for (int j = 0; j < num; j++) {
				Result_Matrix[i][j] += A_Matrix[i][k] * B_Matrix[k][j];
			}
		}
	}
	end_1 = clock();
}

// 할당 해제 함수
void Allocation_Delete(int ** Matrix)
{
	for (int i = 0; i < num; i++)
		free(Matrix[i]);
	free(Matrix);
}

int main(void)
{
	printf("n 입력 : "); scanf("%d", &num);
	int **A_Matrix;
	int **B_Matrix;
	int **Result_Matrix;
	int i, j, k;
	srand(time(NULL));

	// 동적 할당
	A_Matrix = (int **)malloc(sizeof(int*) * num);
	B_Matrix = (int **)malloc(sizeof(int*) * num);
	Result_Matrix = (int **)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++) {
		A_Matrix[i] = (int*)malloc(sizeof(int) * num);
		B_Matrix[i] = (int*)malloc(sizeof(int) * num);
		Result_Matrix[i] = (int*)malloc(sizeof(int) * num);
	}

	// 행렬의 값으로 0부터 9까지의 난수 대입
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			A_Matrix[i][j] = rand() % 10;
			B_Matrix[i][j] = rand() % 10;
			Result_Matrix[i][j] = 0;
		}
	}

	printf("0 부터 9까지의 난수 대입\n\n");
	printf("A Matrix\n");
	//print_Matrix(A_Matrix);
	printf("B Matrix\n");
	//print_Matrix(B_Matrix);
	matrix_multiply(A_Matrix, B_Matrix, Result_Matrix);
	printf("I->K->J 순서의 행렬곱 출력 : \n");
	print_Matrix(Result_Matrix);
	printf("실행시간 : %lf", (double)(end_1 - start_1) / CLOCKS_PER_SEC);

	// 할당 해제 (Free)
	Allocation_Delete(A_Matrix);
	Allocation_Delete(B_Matrix);
	Allocation_Delete(Result_Matrix);

	return 0;
};