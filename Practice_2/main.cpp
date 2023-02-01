#include<iostream>

void Fill(int* mas, size_t N)
{
	srand(time(0));
	for (int i = 0; i < N; ++i)
	{
		mas[i] = rand() % 100;
	}
}

void Print(int* mas, size_t N)
{
	for (int i = 0; i < N; ++i)
		std::cout << mas[i] << " ";
	std::cout << std::endl;
}

void Copy(int* mas, int* paste, size_t N)
{
	unsigned long long* p_paste = (unsigned long long*)paste;
	unsigned long long* p_mas = (unsigned long long*)mas;
	for (int i = 0; i < N / sizeof(long long); ++i)
	{
		*(p_paste++) = *(p_mas++);
	}
	unsigned char* p1 = (unsigned char*)p_paste;
	unsigned char* p2 = (unsigned char*)p_mas;
	for (int i = 0; i < N % sizeof(long long); ++i)
	{
		*(p1++) = *(p2++);
	}
}

int main()
{
	const int N = 23;
	int mas[N];
	int tmp[N];
	Fill(mas, N);
	Print(mas, N);
	Copy(mas, tmp, sizeof(mas));
	Print(tmp, N);
	return 0;
}