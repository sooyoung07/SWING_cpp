#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100  // ������ �ִ� ����
#define MAX_AUTHOR_LENGTH 100  // ������ �ִ� ����
#define MAX_PUBLISHER_LENGTH 100  // ���ǻ��� �ִ� ����

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
} Book;

void addBook(FILE* file)  // ���� �߰� �Լ� ����
{
    Book newBook;

    // ���� ���� �Է� �ޱ�
    printf("������ �̸�: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);

    printf("����: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);

    printf("���ǻ�: ");
    fgets(newBook.publisher, MAX_PUBLISHER_LENGTH, stdin);

    // ���Ͽ� ���� ���� �߰�
    fseek(file, 0, SEEK_END);  // ���� �����͸� ���� ������ �̵�
    fwrite(&newBook, sizeof(Book), 1, file);  // ���� ������ ���Ͽ� ����
}

void displayBooks(FILE* file)  // ���� ���� ��� �Լ� ����
{
    Book currentBook;
    rewind(file);  // ���� �����͸� ������ ó������ �̵�

    while (fread(&currentBook, sizeof(Book), 1, file) == 1) {
        printf("����: %s", currentBook.title);
        printf("����: %s", currentBook.author);
        printf("���ǻ�: %s", currentBook.publisher);
    }
}

void searchBook(FILE* file, const char* keyword)  // ���� �˻� �Լ� ����
{
    Book currentBook;
    rewind(file);  // ���� �����͸� ������ ó������ �̵�
    int found = 0;

    while (fread(&currentBook, sizeof(Book), 1, file) == 1) {
        if (strstr(currentBook.title, keyword) != NULL) {
            printf("���ǻ�� %s", currentBook.publisher);
            found = 1;
        }
    }

    if (!found) {
        printf("�˻� ����� �����ϴ�.\n");
    }
}
int main() {
    FILE* bookFile = fopen("books.dat", "a+");  // ���� ������ ������ ���� ����

    if (bookFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    int choice;
    do {
        printf("====================\n");
        printf("1. ���� �б�\n");
        printf("2. �߰�\n");
        printf("3. ���\n");
        printf("4. �˻�\n");
        printf("5. ���� ����\n");
        printf("6. ����\n");
        printf("====================\n");
        printf("�������� �Է��Ͻÿ�: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            fclose(bookFile);  // ������ �����ִ� ���� �ݱ�
            bookFile = fopen("books.dat", "r");  // ���� ���� ���� �б� ���
            if (bookFile == NULL) {
                printf("������ �� �� �����ϴ�.\n");
                return 1;
            }
            printf("���� ���� ����!\n");
            break;
        case 2:
            fclose(bookFile);  // ������ �����ִ� ���� �ݱ�
            bookFile = fopen("books.dat", "a");  // ���� ���� ���� �߰� ���
            if (bookFile == NULL) {
                printf("������ �� �� �����ϴ�.\n");
                return 1;
            }
            addBook(bookFile);
            fclose(bookFile);
            break;
        case 3:
            fclose(bookFile);  // ������ �����ִ� ���� �ݱ�
            bookFile = fopen("books.dat", "r");  // ���� ���� ���� �б� ���
            if (bookFile == NULL) {
                printf("������ �� �� �����ϴ�.\n");
                return 1;
            }
            displayBooks(bookFile);
            fclose(bookFile);
            break;
        case 4:
            fclose(bookFile);  // ������ �����ִ� ���� �ݱ�
            bookFile = fopen("books.dat", "r");  // ���� ���� ���� �б� ���
            if (bookFile == NULL) {
                printf("������ �� �� �����ϴ�.\n");
                return 1;
            }

            char keyword[100];
            printf("����: ");
            fgets(keyword, 100, stdin);
            keyword[strcspn(keyword, "\n")] = '\0';  // ���� ���� ����

            searchBook(bookFile, keyword);
            fclose(bookFile);
            break;
        case 5:
            fclose(bookFile);  // ������ �����ִ� ���� �ݱ�
            bookFile = fopen("books.dat", "w");  // ���� ���� ���� ���� ���
            if (bookFile == NULL) {
                printf("������ �� �� �����ϴ�.\n");
                return 1;
            }
            printf("���� ���� ����!(2)\n");
            fclose(bookFile);
            break;
        case 6:
            break;
        }
    } while (choice != 6);

    fclose(bookFile);

    return 0;
}