#include "Electric.h"

Electric::Electric()
    : Stock(), m_warranty(0)
{
}

void Electric::SetWarranty(Duration warranty)
{
    m_warranty = warranty;
}

Electric::Duration Electric::GetWarranty() const
{
    return m_warranty;
}

void Electric::Serialize(SerializeStream& stream)
{
    Stock::Serialize(stream);
    stream << m_warranty << " ";
}

void Electric::Deserialize(DeserializeStream& stream)
{
    Stock::Deserialize(stream);
    stream >> m_warranty;
}

StockTypes Electric::_getStockType() const
{
    return StockTypes::Electrical;
}
