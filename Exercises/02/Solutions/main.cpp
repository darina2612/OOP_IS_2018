#include <fstream>
#include <iostream>
#include <cstring>

const size_t MAX_STRING_LENGTH = 128;
const size_t ISBN_STRING_LENGTH = 14;
const size_t MAX_BOOKS_COUNT = 14;

struct Book
{
    char bookName[MAX_STRING_LENGTH];
    char authorName[MAX_STRING_LENGTH];
    char ISBN[ISBN_STRING_LENGTH];
    char genre[MAX_STRING_LENGTH];
    float price;
};

struct Bookstore
{
    size_t currentBooksCount;
    Book books[MAX_BOOKS_COUNT];
};

void initializeBookstore(Bookstore& store, const char* fileName)
{
    std::ifstream inputFile(fileName);

    if(!inputFile)
    {
        std::cout << "Problem opening " << fileName << " for reading!\n";
        return;
    }

    size_t booksCount;
    inputFile >> booksCount;
    inputFile.get();//прочитаме символа за нов ред след стойността

    store.currentBooksCount = (booksCount > MAX_BOOKS_COUNT) ? MAX_BOOKS_COUNT : booksCount;

    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        inputFile.getline(store.books[i].bookName, MAX_STRING_LENGTH);
        inputFile.getline(store.books[i].authorName, MAX_STRING_LENGTH);
        inputFile.getline(store.books[i].ISBN, ISBN_STRING_LENGTH);
        inputFile.getline(store.books[i].genre, MAX_STRING_LENGTH);
        inputFile >> store.books[i].price;
        inputFile.get();//прочитаме символа за нов ред след стойността на price
        inputFile.get();//прочитаме символа за нов ред (празния ред) между два последователни записа
    }

    inputFile.close();
}

bool hasBookWithISBN(const Bookstore& store, const char* isbn)
{
    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        if(strcmp(store.books[i].ISBN, isbn) == 0)
        {
            return true;
        }
    }

    return false;
}

void writeBooksToFile(Book books[], size_t booksCount, const char* fileName)
{
    std::ofstream outputFile(fileName);

    if(!outputFile)
    {
        std::cout << "Problem opening / creating " << fileName << " for writting!\n";
        return;
    }

    for(size_t i = 0; i < booksCount; ++i)
    {
        outputFile << books[i].bookName << std::endl;
        outputFile << books[i].authorName << std::endl;
        outputFile << books[i].ISBN << std::endl;
        outputFile << books[i].genre << std::endl;
        outputFile << books[i].price << std::endl;
        outputFile << std::endl << std::endl;
    }

    outputFile.close();
}

void getAllBooksByAuthorName(const Bookstore& store, const char* authorName, const char* outputFileName)
{
    Book booksByAuthor[MAX_BOOKS_COUNT];

    int booksByAuthorIndex = 0;

    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        if(strcmp(store.books[i].authorName, authorName) == 0)
        {
            booksByAuthor[booksByAuthorIndex++] = store.books[i];
        }
    }

    writeBooksToFile(booksByAuthor, booksByAuthorIndex, outputFileName);
}

void getAllBooksByGenre(const Bookstore& store, const char* genre, const char* outputFileName)
{
    Book booksByGenre[MAX_BOOKS_COUNT];

    int booksByGenreIndex = 0;

    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        if(strcmp(store.books[i].genre, genre) == 0)
        {
            booksByGenre[booksByGenreIndex++] = store.books[i];
        }
    }

    writeBooksToFile(booksByGenre, booksByGenreIndex, outputFileName);
}

void getAllBooksCheaperThan(const Bookstore& store, float price, const char* outputFileName)
{
    Book cheaperBooks[MAX_BOOKS_COUNT];

    int cheaperBooksIndex = 0;

    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        if(store.books[i].price < price)
        {
            cheaperBooks[cheaperBooksIndex++] = store.books[i];
        }
    }

    writeBooksToFile(cheaperBooks, cheaperBooksIndex, outputFileName);
}

int main()
{
    Bookstore store;

    initializeBookstore(store, "SampleBookstoreInfo.txt");

    for(size_t i = 0; i < store.currentBooksCount; ++i)
    {
        std::cout << store.books[i].bookName << std::endl;
        std::cout << store.books[i].authorName << std::endl;
        std::cout << store.books[i].ISBN << std::endl;
        std::cout << store.books[i].genre << std::endl;
        std::cout << store.books[i].price << std::endl;
        std::cout << std::endl;

    }

    std::cout << hasBookWithISBN(store, "9781471331435") << std::endl;
    std::cout << hasBookWithISBN(store, "3143597814713");

    getAllBooksByAuthorName(store, "Ivan Vazov", "BooksByIvanVazov.txt");
    getAllBooksByGenre(store, "Historical Fiction", "HistoricalFictionBooks.txt");
    getAllBooksCheaperThan(store, 20.0, "CheapBooks.txt");

    return 0;
}

