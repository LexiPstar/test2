#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}



//关于浮点数的存储方式
//（-1）->符号位
//s->符号位
//m->有效数字
//e->移动到1.小数点位数
//(-1)^s * m * 2^e
//1(符号位)11111111(e的二进制位)11111111111111111111111(数字位)
//  1位-s       8位-e(e+127)               23位不满足  候补0补齐 -m

//int main()
//{
//	//float a = 5.5;
//	//101.1
//	//1.011 * 2^2
//	//s=0 m=1.011 e=2
//	//0 1000 0001  01100000000000000000000
//	
//	int n = 9;
//	float* pfloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pfloat的值为：%f\n", *pfloat);
//
//	*pfloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pfloat的值为：%f\n", *pfloat);
//
//	return 0;
//}



////输入一个整数数组，实现一个函数，
////来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分
////所有偶数位于数组的后半部分。

void reverse(int* p, int sz)
{	
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//从左向右找偶数
		while (p[left] % 2)
		{
			left++;
		}
		//从右向左找奇数
		while (p[right] % 2 == 0)
		{
			right--;
		}
		//交换位置
		if (left < right)
		{
			int tmp = p[right];
			p[right] = p[left];
			p[left] = tmp;	
			left++;
			right--;
		}		
	}
}

int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//求元素个数
	int i = 0;
	//输入
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	//交换奇偶数位置
	reverse(arr, sz);
	//打印
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}



//使用动态数组长度
void reverse(int* p, int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // 从左向右找偶数
        while (p[left] % 2)
        {
            left++;
        }
        // 从右向左找奇数
        while (p[right] % 2 == 0)
        {
            right--;
        }
        // 交换位置
        if (left < right)
        {
            int tmp = p[right];
            p[right] = p[left];
            p[left] = tmp;
            left++;
            right--;
        }
    }
}

int main()
{
    int sz;
    printf("Enter the size of the array: ");
    scanf("%d", &sz);

    // 动态分配内存
    int* arr = (int*)malloc(sz * sizeof(int));
    if (arr == NULL)  // 检查内存分配是否成功
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 输入数组
    printf("Enter %d integers:\n", sz);
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 交换奇偶数位置
    reverse(arr, sz);

    // 打印数组
    printf("Reversed array: ");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 释放动态分配的内存
    free(arr);

    return 0;
}





//交换后各自按升序排列
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);  // 升序排列
}

void reverse(int* p, int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // 从左向右找偶数
        while (p[left] % 2)
        {
            left++;
        }
        // 从右向左找奇数
        while (p[right] % 2 == 0)
        {
            right--;
        }
        // 交换位置
        if (left < right)
        {
            int tmp = p[right];
            p[right] = p[left];
            p[left] = tmp;
            left++;
            right--;
        }
    }
}



int main()
{
    int sz;
    printf("Enter the size of the array: ");
    scanf("%d", &sz);

    // 动态分配内存
    int* arr = (int*)malloc(sz * sizeof(int));
    if (arr == NULL)  // 检查内存分配是否成功
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 输入数组
    printf("Enter %d integers:\n", sz);
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 分别提取偶数和奇数
    int* evens = (int*)malloc(sz * sizeof(int)); // 存储偶数
    int* odds = (int*)malloc(sz * sizeof(int));  // 存储奇数
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evens[even_count++] = arr[i];
        }
        else
        {
            odds[odd_count++] = arr[i];
        }
    }

    // 对偶数和奇数分别排序
    qsort(evens, even_count, sizeof(int), compare);
    qsort(odds, odd_count, sizeof(int), compare);

    // 合并偶数和奇数数组
    int idx = 0;
    for (int i = 0; i < even_count; i++)
    {
        arr[idx++] = evens[i];
    }
    for (int i = 0; i < odd_count; i++)
    {
        arr[idx++] = odds[i];
    }

    // 打印排序后的数组
    printf("Array with evens and odds sorted separately: ");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 释放内存
    free(arr);
    free(evens);
    free(odds);

    return 0;
}
