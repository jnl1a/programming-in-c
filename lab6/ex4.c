//lab6 ex4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 10 // Adjust this as needed

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

// Function to load indexes from disk
void loadIndexes(int indexByTitle[], int indexByAuthor[], int indexByPrice[], int *numBooks) {
    FILE *indexFile;

    // Load Title Index
    indexFile = fopen("indexByTitle.dat", "rb");
    if (indexFile != NULL) {
        fread(numBooks, sizeof(int), 1, indexFile);
        fread(indexByTitle, sizeof(int), *numBooks, indexFile);
        fclose(indexFile);
    }

    // Load Author Index
    indexFile = fopen("indexByAuthor.dat", "rb");
    if (indexFile != NULL) {
        fread(indexByAuthor, sizeof(int), *numBooks, indexFile);
        fclose(indexFile);
    }

    // Load Price Index
    indexFile = fopen("indexByPrice.dat", "rb");
    if (indexFile != NULL) {
        fread(indexByPrice, sizeof(int), *numBooks, indexFile);
        fclose(indexFile);
    }
}

// Function to save indexes to disk
void saveIndexes(int indexByTitle[], int indexByAuthor[], int indexByPrice[], int numBooks) {
    FILE *indexFile;

    // Save Title Index
    indexFile = fopen("indexByTitle.dat", "wb");
    if (indexFile != NULL) {
        fwrite(&numBooks, sizeof(int), 1, indexFile);
        fwrite(indexByTitle, sizeof(int), numBooks, indexFile);
        fclose(indexFile);
    }

    // Save Author Index
    indexFile = fopen("indexByAuthor.dat", "wb");
    if (indexFile != NULL) {
        fwrite(indexByAuthor, sizeof(int), numBooks, indexFile);
        fclose(indexFile);
    }

    // Save Price Index
    indexFile = fopen("indexByPrice.dat", "wb");
    if (indexFile != NULL) {
        fwrite(indexByPrice, sizeof(int), numBooks, indexFile);
        fclose(indexFile);
    }
}

int main(void) {
    int numBooks = 0;

    // Load existing indexes from disk
    int indexByTitle[MAX_BOOKS] = {0};
    int indexByAuthor[MAX_BOOKS] = {0};
    int indexByPrice[MAX_BOOKS] = {0};
    loadIndexes(indexByTitle, indexByAuthor, indexByPrice, &numBooks);

    // If no books exist, add a couple of books to start
    FILE *fp = fopen("book.dat", "ab+");
    if (fp == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }

    // Example: adding new books
    if (numBooks == 0) {
        Book book1 = {"The C Programming Language", "Kernighan & Ritchie", 29.99};
        Book book2 = {"Clean Code", "Robert C. Martin", 24.99};
        fwrite(&book1, sizeof(Book), 1, fp);
        fwrite(&book2, sizeof(Book), 1, fp);
        numBooks += 2;
    }

    // Add more books if needed...

    fclose(fp);

    // Update indexes after adding a new book
    indexByTitle[numBooks - 2] = numBooks - 2;
    indexByTitle[numBooks - 1] = numBooks - 1;
    indexByAuthor[numBooks - 2] = numBooks - 2;
    indexByAuthor[numBooks - 1] = numBooks - 1;
    indexByPrice[numBooks - 2] = numBooks - 2;
    indexByPrice[numBooks - 1] = numBooks - 1;

    // Sort indexes by title, author, and price
    selectionSort(indexByTitle, numBooks, compareByTitle);
    selectionSort(indexByAuthor, numBooks, compareByAuthor);
    selectionSort(indexByPrice, numBooks, compareByPrice);

    // Save indexes to disk
    saveIndexes(indexByTitle, indexByAuthor, indexByPrice, numBooks);

    // Display books sorted by title (ascending)
    printf("Books sorted by Title (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByTitle, numBooks, fp);
    fclose(fp);

    // Display books sorted by author (ascending)
    printf("\nBooks sorted by Author (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByAuthor, numBooks, fp);
    fclose(fp);

    // Display books sorted by price (ascending)
    printf("\nBooks sorted by Price (Ascending):\n");
    fp = fopen("book.dat", "rb");
    displayBooks(indexByPrice, numBooks, fp);
    fclose(fp);

    return 0;
}
