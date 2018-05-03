#ifndef STORE_H
#define STORE_H

#include "Stock.h"
#include "Vector.h"
#include "String.h"

class Store
{
public:
    using Article = Stock;
    using ArticlePtr = Article*;

    Store();
    ~Store();

    void AddArticle(ArticlePtr article);
    void SaveToFile(const String& fileName);
    void RestoreFromFile(const String& fileName);
    void PrintArticles();

private:
    Vector<ArticlePtr> m_articles;
};

#endif // STORE_H
