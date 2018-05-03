#ifndef STOCK_H
#define STOCK_H

#include "StockTypes.h"
#include "String.h"
#include <iostream>

class Stock
{
public:
    using SerializeStream = std::ostream;
    using DeserializeStream = std::istream;
    using Price = double;


    Stock();
    virtual ~Stock();

    void SetBrand(const String& brand);
    void SetBarcode(const String& barcode);
    void SetOriginCountry(const String& originCountry);
    void SetRetailPrice(Price retailPrice);
    void SetWholesalePrice(Price wholesalePrice);
    void SetInitalPrice(Price initalPrice);

    const String& GetBrand() const;
    const String& GetBarcode() const;
    const String& GetOriginCountry() const;
    Price GetRetailPrice() const;
    Price GetWholesalePrice() const;
    Price GetInitalPrice() const;

    virtual void Serialize(SerializeStream& stream);
    virtual void Deserialize(DeserializeStream& stream);
protected:
    virtual StockTypes _getStockType() const; // used for serialization
private:
    String m_brand;
    String m_barcode;
    String m_originCountry;
    Price m_retailPrice;
    Price m_wholesalePrice;
    Price m_initalPrice;
};

#endif // STOCK_H
