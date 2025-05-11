#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define MAXSIZE 40

char* DeleteQuestionMark(char* str)
{
	for (int i = 1; *(str + i) != '\0'; i++)
	{
		if (*(str + i - 1) == 'а' && *(str + i) == '?')
		{
			*(str + i) = ' ';
		}
	}
}
void CountOfPO(char* str)
{
	int count = 0;
	for (int i = 1; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == 'Р' || *(str + i) == 'О')
		{
			count++;
		}
	}
	printf_s("Общее количество 'Р' и 'О' = %d\n", count);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* str = (char*)calloc(MAXSIZE, sizeof(char));
	if (str == NULL)
	{
		puts("Ошибка памяти !");
		return 1;
	}
	gets_s(str, MAXSIZE);

	DeleteQuestionMark(str);
	CountOfPO(str);
	printf_s("%s\n", str);

	free(str);
	system("pause");
	return 0;
}