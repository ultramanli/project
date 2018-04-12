
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include"D:\CUDA_files\cuda_by_example\common\book.h"

#include <stdio.h>


#define N 10
__global__ void add(int *a, int *b, int *c)
{
	int tid = threadIdx.x;
	if (tid < N)
	{
		c[tid] = a[tid] + b[tid];

	}

}
int main(void)
{
	int a[N], b[N], c[N];
	int *dev_a, *dev_b, *dev_c;
	
	//Distribure memroy on GPU
	cudaMalloc((void**)&dev_a, N*sizeof(int));
	cudaMalloc((void**)&dev_b, N*sizeof(int));
	cudaMalloc((void**)&dev_c, N*sizeof(int));

	//Set array a&b on CPU
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i*i;
	}

	//Copy array a&b to GPU
	cudaMemcpy(dev_a, a, N*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, b, N*sizeof(int), cudaMemcpyHostToDevice);

	//Using kernel
	////////////////////1-bolck N-thread /////////////////
	add << <1, N >> >(dev_a, dev_b, dev_c);

	//Copy array c to CPU
	cudaMemcpy(c, dev_c, N*sizeof(int), cudaMemcpyDeviceToHost);

	//Show the result
	for (int i = 0; i < N; i++)
	{
		printf("%d+%d=%d\n", a[i], b[i], c[i]);
	}
	
	//Free the memory on GPU
	cudaFree(dev_a);
	cudaFree(dev_b);
	cudaFree(dev_c);

	return 0;
}