/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
	此题的解题思路与threeSum一样。
*/

 
#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 2147483647 
void quick_sort(int *arr,int l,int r) 
{
	if(l>=r) return;
	int temp=arr[l];
	int i=l,j=r;
	while(i<j)
	{
		while(i<j && arr[j]>=temp)
			j--;
		if(i<j)
			arr[i++]=arr[j];
		while(i<j && arr[i]<temp)
			i++;
		if(i<j)
			arr[j--]=arr[i];
	}
	arr[i]=temp;
	quick_sort(arr,l,i-1);
	quick_sort(arr,i+1,r);
}
 
int threeSumClosest(int* nums, int numsSize, int target){
    quick_sort(nums,0,numsSize-1);//先排序
	int j=0;
	for(;j<numsSize;j++)
		printf("%d  ",nums[j]);
	int re;
	int *nums_r=nums;
	int *front,*back;
	int sum,sum_abs,sum_abs_r=MAX_INT;
	for(;nums_r<nums+numsSize;nums_r++)
	{
		front=nums_r+1;
		back=nums+numsSize-1;
		while(front<back)
		{
			sum=*front + *back + *nums_r - target;
			sum_abs = sum>0 ? sum : -sum;
			printf("1 sum:%d  abs:%d  abs_r:%d  %d %d %d \n",sum,sum_abs,sum_abs_r,*nums_r,*front,*back);
			if(sum==0) return *front + *back + *nums_r;
			if(sum_abs<sum_abs_r)
			{
				printf("p:%d %d %d \n",*nums_r,*front,*back);
				sum_abs_r=sum_abs;
				re=*front + *back + *nums_r;
				sum > 0 ? back-- : front++;
			}
			else// if(sum_abs>sum_abs_r)
			{
				sum > 0 ? back-- : front++;
			}		
			// else  //sum_abs==sum_abs_r
			// {						
				// while(front<back-1 && *(front+1)==*front) front++;//跳过重复的
				// front++;
				// while(front<back-1 && *(back-1)==*back) back--;//跳过重复的
				// back--;
			// }
			printf("2 sum:%d  abs:%d  abs_r:%d  %d %d %d \n",sum,sum_abs,sum_abs_r,*nums_r,*front,*back);
		}
		while(nums_r<nums+numsSize-1 && *nums_r==*(nums_r+1)) nums_r++;//跳过重复的组
	}
	return re;
}
int main(int argc, char **argv)
{
	int arr[]={4,0,5,-5,3,3,0,-4,-5};
	int len=sizeof(arr)/sizeof(int);
	int target=-2;
	// printf("re:%d\n",threeSumClosest(arr,len,target));
	int *p=arr;
	printf("sizeof(*p):%d\n",sizeof(*p));
	printf("sizeof(p):%d\n",sizeof(p));
	printf("sizeof(arr):%d\n",sizeof(arr));
	
	return 0;
}



