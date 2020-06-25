void printMat(int mat[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
