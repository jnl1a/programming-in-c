// lab6 ex3
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 2 // We have two books in the example

typedef struct {
    char title[40];
    char author[40];
    float price;
} Book;

// Function to perform selection sort based on a given comparison function
void selectionSort(int index[], int n, int (*cmp)(Book, Book)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Fetch books using the current index positions
            FILE *fp = fopen("book.dat", "rb");
            if (fp == NULL) {
                perror("Unable to open file for reading");
                return;
            }

            Book book_i, book_j;
            fseek(fp, index[i] * sizeof(Book), SEEK_SET);
            fread(&book_i, sizeof(Book), 1, fp);
            fseek(fp, index[j] * sizeof(Book), SEEK_SET);
            fread(&book_j, sizeof(Book), 1, fp);
            fclose(fp);

            // If books are out of order based on the comparison function, swap them
            if (cmp(book_i, book_j) > 0) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

// Comparison function to sort books by title (ascending)
int compareByTitle(Book book1, Book book2) {
    return strcmp(book1.title, book2.title);
}

// Comparison function to sort books by author (ascending)
int compareByAuthor(Book book1, Book book2) {
    return strcmp(book1.author, book2.author);
}

// Comparison function to sort books by price (ascending)
int compareByPrice(Book book1, Book book2) {
    if (book1.price < book2.price) return -1;
    if (book1.price > book2.price) return 1;
    return 0;
}

// Function to display books from an index
void displayBooks(int index[], int n, FILE *fp) {
    for (int i = 0; i < n; i++) {
        fseek(fp, index[i] * sizeof(Book), SEEK_SET);
        Book book;
        fread(&book, sizeof(Book), 1, fp);
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n",
               book.title, book.author, book.price);
    }
}

int main(void) {
    Book book1 = {
        "The C Programming Language",
        "Kernighan & Ritchie",
        29.99
    };
    Book book2 = {
        "Clean Code",
        "Robert C. Martin",
        24.99
    };

    // Write books to file
    FILE *fp = fopen("book.dat", "wb");
    if (fp == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }
    fwrite(&book1, sizeof(Book), 1, fp);
    fwrite(&book2, sizeof(Book), 1, fp);
    fclose(fp);

    // Create indexes for the books
    int indexByTitle[MAX_BOOKS] = {0, 1};
    int indexByAuthor[MAX_BOOKS] = {0, 1};
    int indexByPrice[MAX_BOOKS] = {0, 1};

    // Sort indexes by title, author, and price
    selectionSort(indexByTitle, MAX_BOOKS, compareByTitle);
    selectionSort(indexByAuthor, MAX_BOOKS, compareByAuthor);
    selectionSort(indexByPrice, MAX_BOOKS, compareByPrice);

    // Read and display the books in ascending order by title
    printf("Books sorted by Title (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByTitle, MAX_BOOKS, fp);
    fclose(fp);

    // Read and display the books in ascending order by author
    printf("\nBooks sorted by Author (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByAuthor, MAX_BOOKS, fp);
    fclose(fp);

    // Read and display the books in ascending order by price
    printf("\nBooks sorted by Price (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByPrice, MAX_BOOKS, fp);
    fclose(fp);

    // Display the books in descending order by title
    printf("\nBooks sorted by Title (Descending):\n");
    int indexByTitleDesc[MAX_BOOKS] = {0, 1};
    selectionSort(indexByTitleDesc, MAX_BOOKS, compareByTitle);
    for (int i = MAX_BOOKS - 1; i >= 0; i--) {
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n",
               book1.title, book1.author, book1.price);
    }
    return 0;
}
