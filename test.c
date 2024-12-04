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



//���ڸ������Ĵ洢��ʽ
//��-1��->����λ
//s->����λ
//m->��Ч����
//e->�ƶ���1.С����λ��
//(-1)^s * m * 2^e
//1(����λ)11111111(e�Ķ�����λ)11111111111111111111111(����λ)
//  1λ-s       8λ-e(e+127)               23λ������  ��0���� -m

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
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pfloat��ֵΪ��%f\n", *pfloat);
//
//	*pfloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pfloat��ֵΪ��%f\n", *pfloat);
//
//	return 0;
//}



////����һ���������飬ʵ��һ��������
////�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿��
////����ż��λ������ĺ�벿�֡�

void reverse(int* p, int sz)
{	
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//����������ż��
		while (p[left] % 2)
		{
			left++;
		}
		//��������������
		while (p[right] % 2 == 0)
		{
			right--;
		}
		//����λ��
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
	int sz = sizeof(arr) / sizeof(arr[0]);//��Ԫ�ظ���
	int i = 0;
	//����
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	//������ż��λ��
	reverse(arr, sz);
	//��ӡ
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}



//ʹ�ö�̬���鳤��
void reverse(int* p, int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // ����������ż��
        while (p[left] % 2)
        {
            left++;
        }
        // ��������������
        while (p[right] % 2 == 0)
        {
            right--;
        }
        // ����λ��
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

    // ��̬�����ڴ�
    int* arr = (int*)malloc(sz * sizeof(int));
    if (arr == NULL)  // ����ڴ�����Ƿ�ɹ�
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // ��������
    printf("Enter %d integers:\n", sz);
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }

    // ������ż��λ��
    reverse(arr, sz);

    // ��ӡ����
    printf("Reversed array: ");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �ͷŶ�̬������ڴ�
    free(arr);

    return 0;
}





//��������԰���������
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);  // ��������
}

void reverse(int* p, int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // ����������ż��
        while (p[left] % 2)
        {
            left++;
        }
        // ��������������
        while (p[right] % 2 == 0)
        {
            right--;
        }
        // ����λ��
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

    // ��̬�����ڴ�
    int* arr = (int*)malloc(sz * sizeof(int));
    if (arr == NULL)  // ����ڴ�����Ƿ�ɹ�
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // ��������
    printf("Enter %d integers:\n", sz);
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }

    // �ֱ���ȡż��������
    int* evens = (int*)malloc(sz * sizeof(int)); // �洢ż��
    int* odds = (int*)malloc(sz * sizeof(int));  // �洢����
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

    // ��ż���������ֱ�����
    qsort(evens, even_count, sizeof(int), compare);
    qsort(odds, odd_count, sizeof(int), compare);

    // �ϲ�ż������������
    int idx = 0;
    for (int i = 0; i < even_count; i++)
    {
        arr[idx++] = evens[i];
    }
    for (int i = 0; i < odd_count; i++)
    {
        arr[idx++] = odds[i];
    }

    // ��ӡ����������
    printf("Array with evens and odds sorted separately: ");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �ͷ��ڴ�
    free(arr);
    free(evens);
    free(odds);

    return 0;
}
