#include "Stock.h"

Stock::Stock()
    : m_brand(), m_barcode(), m_originCountry(), m_retailPrice(), m_wholesalePrice(), m_initalPrice()
{
}

Stock::~Stock()
{
}

void Stock::SetBrand(const String& brand)
{
    m_brand = brand;
}

void Stock::SetBarcode(const String& barcode)
{
    m_barcode = barcode;
}

void Stock::SetOriginCountry(const String& originCountry)
{
    m_originCountry = originCountry;
}

void Stock::SetRetailPrice(Price retailPrice)
{
    m_retailPrice = retailPrice;
}

void Stock::SetWholesalePrice(Price wholesalePrice)
{
    m_wholesalePrice = wholesalePrice;
}

void Stock::SetInitalPrice(Price initalPrice)
{
    m_initalPrice = initalPrice;
}

const String& Stock::GetBrand() const
{
    return m_brand;
}

const String& Stock::GetBarcode() const
{
    m_barcode;
}

const String& Stock::GetOriginCountry() const
{
    m_originCountry;
}

Stock::Price Stock::GetRetailPrice() const
{
    m_retailPrice;
}

Stock::Price Stock::GetWholesalePrice() const
{
    m_wholesalePrice;
}

Stock::Price Stock::GetInitalPrice() const
{
    m_initalPrice;
}

void Stock::Serialize(SerializeStream& stream)
{
    stream << static_cast<int>(_getStockType()) << " " << m_brand << " "
           << m_barcode <<  " " << m_originCountry << " " << m_retailPrice
           << " " << m_wholesalePrice << " " << m_initalPrice << " ";
}

void Stock::Deserialize(DeserializeStream& stream)
{
    stream >> m_brand >> m_barcode >> m_originCountry
           >> m_retailPrice >> m_wholesalePrice >> m_initalPrice;
}

StockTypes Stock::_getStockType() const
{
    return StockTypes::Regular;
}
