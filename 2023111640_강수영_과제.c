#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100  // 제목의 최대 길이
#define MAX_AUTHOR_LENGTH 100  // 저자의 최대 길이
#define MAX_PUBLISHER_LENGTH 100  // 출판사의 최대 길이

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
} Book;

void addBook(FILE* file)  // 도서 추가 함수 정의
{
    Book newBook;

    // 도서 정보 입력 받기
    printf("도서의 이름: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);

    printf("저자: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);

    printf("출판사: ");
    fgets(newBook.publisher, MAX_PUBLISHER_LENGTH, stdin);

    // 파일에 도서 정보 추가
    fseek(file, 0, SEEK_END);  // 파일 포인터를 파일 끝으로 이동
    fwrite(&newBook, sizeof(Book), 1, file);  // 도서 정보를 파일에 쓰기
}

void displayBooks(FILE* file)  // 도서 정보 출력 함수 정의
{
    Book currentBook;
    rewind(file);  // 파일 포인터를 파일의 처음으로 이동

    while (fread(&currentBook, sizeof(Book), 1, file) == 1) {
        printf("제목: %s", currentBook.title);
        printf("저자: %s", currentBook.author);
        printf("출판사: %s", currentBook.publisher);
    }
}

void searchBook(FILE* file, const char* keyword)  // 도서 검색 함수 정의
{
    Book currentBook;
    rewind(file);  // 파일 포인터를 파일의 처음으로 이동
    int found = 0;

    while (fread(&currentBook, sizeof(Book), 1, file) == 1) {
        if (strstr(currentBook.title, keyword) != NULL) {
            printf("출판사는 %s", currentBook.publisher);
            found = 1;
        }
    }

    if (!found) {
        printf("검색 결과가 없습니다.\n");
    }
}
int main() {
    FILE* bookFile = fopen("books.dat", "a+");  // 도서 정보를 저장할 파일 열기

    if (bookFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int choice;
    do {
        printf("====================\n");
        printf("1. 파일 읽기\n");
        printf("2. 추가\n");
        printf("3. 출력\n");
        printf("4. 검색\n");
        printf("5. 파일 쓰기\n");
        printf("6. 종료\n");
        printf("====================\n");
        printf("정수값을 입력하시오: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            fclose(bookFile);  // 이전에 열려있던 파일 닫기
            bookFile = fopen("books.dat", "r");  // 도서 정보 파일 읽기 모드
            if (bookFile == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return 1;
            }
            printf("파일 오픈 성공!\n");
            break;
        case 2:
            fclose(bookFile);  // 이전에 열려있던 파일 닫기
            bookFile = fopen("books.dat", "a");  // 도서 정보 파일 추가 모드
            if (bookFile == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return 1;
            }
            addBook(bookFile);
            fclose(bookFile);
            break;
        case 3:
            fclose(bookFile);  // 이전에 열려있던 파일 닫기
            bookFile = fopen("books.dat", "r");  // 도서 정보 파일 읽기 모드
            if (bookFile == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return 1;
            }
            displayBooks(bookFile);
            fclose(bookFile);
            break;
        case 4:
            fclose(bookFile);  // 이전에 열려있던 파일 닫기
            bookFile = fopen("books.dat", "r");  // 도서 정보 파일 읽기 모드
            if (bookFile == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return 1;
            }

            char keyword[100];
            printf("제목: ");
            fgets(keyword, 100, stdin);
            keyword[strcspn(keyword, "\n")] = '\0';  // 개행 문자 제거

            searchBook(bookFile, keyword);
            fclose(bookFile);
            break;
        case 5:
            fclose(bookFile);  // 이전에 열려있던 파일 닫기
            bookFile = fopen("books.dat", "w");  // 도서 정보 파일 쓰기 모드
            if (bookFile == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return 1;
            }
            printf("파일 오픈 성공!(2)\n");
            fclose(bookFile);
            break;
        case 6:
            break;
        }
    } while (choice != 6);

    fclose(bookFile);

    return 0;
}