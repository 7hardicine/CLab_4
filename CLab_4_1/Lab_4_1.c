#include <stdio.h>
#include <Windows.h>
#define MAXSIZE 40

void Shift(char** str, int i)
{
	int j = 0;
	for (; *(*str + i + j) != '\0'; j++)
	{
		*(*str + i + j) = *(*str + i + j + 1);
	}
	*str = (char*)realloc(*str, i + j);
}
void DeleteQuestionMark(char* str)
{
	for (int i = 1; *(str + i) != '\0'; i++)
	{
		if (*(str + i - 1) == 'а' && *(str + i) == '?')
		{
			Shift(&str, i);
			i--;
		}
	}
}
void CountOfPO(char* str)
{
	int count = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == 'Р' || *(str + i) == 'О')
		{
			count++;
		}
	}
	printf_s("Общее количество 'Р' и 'О' = %d\n", count);
}
char* InputStr()
{
	char* str = (char*)calloc(MAXSIZE, sizeof(char));
	if (str == NULL)
	{
		puts("Ошибка памяти !");
		return 1;
	}
	int i = 0;
	while ((*(str + i++) = (char)getchar()) != '\n');
	*(str + --i) = '\0';
	str = (char*)realloc(str, i + 1);
	return str;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* str = NULL;
	puts("Введите строку:");
	str = InputStr();

	DeleteQuestionMark(str);
	CountOfPO(str);
	puts(str);

	free(str);
	system("pause");
	return 0;
}