#include "NonGrocery.h"

NonGrocery::NonGrocery()
    : Stock(), m_toxic(false)
{
}

void NonGrocery::SetToxic(bool toxic)
{
    m_toxic = toxic;
}

bool NonGrocery::GetToxic() const
{
    return m_toxic;
}

void NonGrocery::Serialize(SerializeStream& stream)
{
    Stock::Serialize(stream);
    stream << m_toxic << " ";
}

void NonGrocery::Deserialize(DeserializeStream& stream)
{
    Stock::Deserialize(stream);
    stream >> m_toxic;
}

StockTypes NonGrocery::_getStockType() const
{
    return StockTypes::Nongrocery;
}
