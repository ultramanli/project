
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<time.h>
#include <stdio.h>

#define N 4
#define NN 2000
__global__ void mat(int *a, int *b, int *c)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];
}

int main(void)

{
	int a[NN][NN], b[NN][NN];
	long long c[NN][NN];
	int *dev_a, *dev_b;
	long long *dev_c;
	clock_t start, end;
	int i, j, t, k,n=1000, ptime;
	cudaMalloc((void**)&dev_a, NN*sizeof(int));
	cudaMalloc((void**)&dev_b, NN* sizeof(int));
	cudaMalloc((void**)&dev_c, NN* sizeof(long));

	for(i=0;i<n;i++)
	{ 
		t = i + 1;
		for (j = 0; j < n; j++)
		{
			a[i][j] = t++;
			b[i][j] = 1;

		}
	}
	
	cudaMemcpy(dev_a, a, NN* sizeof(int*), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, b, NN*sizeof(int*), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_c, c, NN*sizeof(long*), cudaMemcpyHostToDevice);

	start = clock();
	mat << <1, 10 >> > (dev_a, dev_b, dev_c);
	end = clock();
	ptime = end - start;
	printf("Time=%d", ptime);

	
	
}
