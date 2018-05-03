#include "Grocery.h"

Grocery::Grocery()
 : Stock(), m_expiryDate(0), m_lowTemperature(false)
{
}

void Grocery::SetExpiryDate(Duration expiryDate)
{
    m_expiryDate = expiryDate;
}

void Grocery::SetLowTemperature(bool lowTemperature)
{
    m_lowTemperature = lowTemperature;
}

Grocery::Duration Grocery::GetExpiryDate() const
{
    m_expiryDate;
}

bool Grocery::GetLowTemperature() const
{
    return m_lowTemperature;
}

void Grocery::Serialize(SerializeStream& stream)
{
    Stock::Serialize(stream);
    stream << m_expiryDate << " " << m_lowTemperature << " ";
}

void Grocery::Deserialize(DeserializeStream& stream)
{
    Stock::Deserialize(stream);
    stream >> m_expiryDate >> m_lowTemperature;
}

StockTypes Grocery::_getStockType() const
{
    return StockTypes::Grocery;
}
