#include "Store.h"
#include "Grocery.h"
#include "NonGrocery.h"
#include "Electric.h"
#include <fstream>
#include <sstream>

Store::ArticlePtr ArticlesFactory(StockTypes stockType)
{
    switch (stockType)
    {
        case StockTypes::Grocery:
            return new Grocery();
        case StockTypes::Nongrocery:
            return new NonGrocery();
        case StockTypes::Electrical:
            return new Electric();
        default:
            return new Stock();
    }
    return nullptr;
}

Store::Store()
{
}

Store::~Store()
{
    for(Vector<ArticlePtr>::size_type idx = 0; idx < m_articles.get_size(); idx++)
    {
        delete m_articles[idx];
    }
}

void Store::AddArticle(ArticlePtr article)
{
    m_articles.push_back(article);
}

void Store::SaveToFile(const String& fileName)
{
    std::ofstream out(fileName.data());
    for(Vector<ArticlePtr>::size_type idx = 0; idx < m_articles.get_size(); idx++)
    {
        m_articles[idx]->Serialize(out);
    }
}

void Store::RestoreFromFile(const String& fileName)
{
    std::ifstream in(fileName.data());
    if(in.is_open() == false)
    {
        return;
    }

    int stockType;
    while(in >> stockType)
    {
        ArticlePtr to_add = ArticlesFactory(static_cast<StockTypes>(stockType));
        to_add->Deserialize(in);
        m_articles.push_back(to_add);
    }
}

void Store::PrintArticles()
{
    for(Vector<ArticlePtr>::size_type idx = 0; idx < m_articles.get_size(); idx++)
    {
        std::stringstream ss;
        m_articles[idx]->Serialize(ss);
        std::cout << ss.str() << std::endl;
    }
}
