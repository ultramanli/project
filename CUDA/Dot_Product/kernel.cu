
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include"D:\CUDA_files\cuda_by_example\common\book.h"
#include "D:\CUDA_files\cuda_by_example\appendix_a\lock.h"
#include <stdio.h>

#define imin(a,b) (a<b?a:b)

const int N = 33 * 1024;
const int threadsPerBlock = 256;
const int blocksPerGrid = imin(32, (N + threadsPerBlock - 1) / threadsPerBlock);

__global__ void dot(float *a, float *b, float *c)
{
	__shared__ float cache[threadsPerBlock];
	int tid = threadIdx.x + blockIdx.x*blockDim.x;
	int cacheIndex = threadIdx.x;//CacheID=threadID
	float temp = 0;////////
	while (tid < N){
		temp += a[tid] * b[tid];
		tid += blockDim.x*gridDim.x;
	}

	cache[cacheIndex] = temp;//Set value in cache
	__syncthreads();//Wait every threads finish work
	int i = blockDim.x / 2;//For this caculate threadPerBlock must /2=0
	while (i != 0){
		if (cacheIndex < i)
			cache[cacheIndex] += cache[cacheIndex + i];
		__syncthreads();
		i /= 2;
	}
	if (cacheIndex == 0){
		c[blockIdx.x] = cache[0];
	}
}
int main(void)
{
	float *a, *b, c, *partial_c;
	float *dev_a, *dev_b, *dev_partial_c;

	//Set memory on CPU
	a = (float*)malloc(N*sizeof(float));
	b = (float*)malloc(N*sizeof(float));
	partial_c = (float*)malloc(blocksPerGrid*sizeof(float));

	//Set memory on GPU
	cudaMalloc((void**)&dev_a, N*sizeof(float));
	cudaMalloc((void**)&dev_b, N*sizeof(float));
	cudaMalloc((void**)&dev_partial_c, N*sizeof(float));

	//Fill Host's memory(set array a&b value)
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i * 2;
	}

	//Copy array a&b to GPU
	cudaMemcpy(dev_a, a, N*sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, b, N*sizeof(float), cudaMemcpyHostToDevice);

	dot << <blocksPerGrid, threadsPerBlock >> >(dev_a, dev_b, dev_partial_c);

	//Copy array c to CPU
	cudaMemcpy(partial_c, dev_partial_c, blocksPerGrid*sizeof(float), cudaMemcpyDeviceToHost);

	//Finish final caculate at CPU
	c = 0;
	for (int i = 0; i < blocksPerGrid; i++){
		c += partial_c[i];
	}
    #define sum_squares(x) (x*(x+1)*(2*x+1)/6)
	printf("Does GPU value %.6g=%.6g?\n", c, 2 * sum_squares((float)(N - 1)));

	//Free memory on GPU
	cudaFree(dev_a);
	cudaFree(dev_b);
	cudaFree(dev_partial_c);

	//Free memory on CPU
	free(a);
	free(b);
	free(partial_c);




}