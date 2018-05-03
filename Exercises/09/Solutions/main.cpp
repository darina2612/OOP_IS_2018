#include "Store.h"
#include "Electric.h"

int main()
{
    Store exampleStore;

    Electric* stock1 = new Electric();
    stock1->SetBarcode("123456");
    stock1->SetBrand("Brand1");
    stock1->SetInitalPrice(123);
    stock1->SetOriginCountry("Bulgaria");
    stock1->SetRetailPrice(321);
    stock1->SetWholesalePrice(765);

    exampleStore.AddArticle(stock1);
    exampleStore.SaveToFile("test.txt");
    Store exampleStore2;
    exampleStore2.RestoreFromFile("test.txt");
    exampleStore2.PrintArticles();
    return 0;
}
