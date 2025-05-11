#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define MAXSIZE 40

void Shift(char** str, int FirstWordLen, int len, int totalShift)
{
    for (int j = len; j >= FirstWordLen; j--)
    {
        *(*str + j + totalShift) = *(*str + j);
    }
}
void WordsWithoutE(char* str)
{
    int isWord = 0;
    int isWithE = 0;
    int counter = 0;
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (isWord == 0 && *(str + i) != ' ')
        {
            isWord = 1;
        }
        if (isWord && (*(str + i) == 'Е'))
        {
            isWithE = 1;
        }
        if (*(str + i) == ' ' || *(str + i + 1) == '\0')
        {
            if (isWord)
            {
                if (isWithE == 0)
                {
                    counter++;
                }
                isWithE = 0;
            }
            isWord = 0;
        }
    }
    printf_s("Количество слов без буквы Е = %d\n", counter);
}
char* InputStr()
{
    char* str = (char*)calloc(MAXSIZE, sizeof(char));
    if (str == NULL)
    {
        puts("Ошибка памяти !");
        return NULL;
    }
    int i = 0;
    while ((*(str + i++) = (char)getchar()) != '\n' && i < MAXSIZE - 1);
    *(str + --i) = '\0';
    str = (char*)realloc(str, i + 1);
    return str;
}

void RepeatFirstWord(char** str)
{
    int len = strlen(*str);
    int FirstWordLen = 0;
    while (*(*str + FirstWordLen) != ' ' && *(*str + FirstWordLen) != '\0')
    {
        FirstWordLen++;
    }
    int repeats = 3;
    int totalShift = (FirstWordLen + 1) * (repeats - 1);
    *str = (char*)realloc(*str, len + totalShift + 1);
    Shift(str, FirstWordLen, len, totalShift);
    for (int i = 1; i < repeats; i++)
    {
        *(*str + FirstWordLen * i + i - 1) = ' ';
        for (int j = 0; j < FirstWordLen; j++)
        {
            *(*str + FirstWordLen * i + i + j) = *(*str + j);
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char* str = NULL;
    puts("Введите строку:");
    str = InputStr();
    WordsWithoutE(str);
    RepeatFirstWord(&str);
    puts(str);

    free(str);
    system("pause");
    return 0;
}