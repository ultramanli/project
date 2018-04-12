
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);

__global__ void test(int *thI,int *blI,int *blD,int *tidd)
{
	int tid = threadIdx.x+blockIdx.x *blockDim.x;
	tidd[tid] = tid;
	thI[tid] = threadIdx.x;
	blI[tid] = blockIdx.x;
	blD[tid] = blockDim.x;
}

int main(void)
{
	int *dev_thI, *dev_blI,*dev_blD,int *dev_tidd;
	int thI[4],blI[4],blD[4],tidd[4];

	cudaMalloc((void**)&dev_thI, 4 * sizeof(int));
	cudaMalloc((void**)&dev_blI, 4 * sizeof(int));
	cudaMalloc((void**)&dev_blD, 4 * sizeof(int));
	cudaMalloc((void**)&dev_tidd, 4 * sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		thI[i] = 999;
		blI[i] = 999;
		blD[i] = 999;
		tidd[i] = 999;
	}
	//cudaMemcpy(dev_a, a, 4 * sizeof(int), cudaMemcpyHostToDevice);
	test<< <2, 2>> >(dev_thI,dev_blI,dev_blD,dev_tidd);
	cudaMemcpy(thI, dev_thI, 4 * sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(blI, dev_blI, 4 * sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(blD, dev_blD, 4 * sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(tidd, dev_tidd, 4 * sizeof(int), cudaMemcpyDeviceToHost);
	for (int i = 0; i < 4; i++)
	{
		printf("This Tid=%d\n", tidd[i]);
		printf("This ThreadIdx.x=%d \n", thI[i]);
		printf("This BlockIdx.x=%d \n", blI[i]);
		printf("This BlockDim.x=%d \n\n", blD[i]);
	}
	cudaFree(dev_thI);
	cudaFree(dev_blI);
	cudaFree(dev_blD);
	cudaFree(dev_tidd);
	return 0;
}


