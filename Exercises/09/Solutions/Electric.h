#ifndef ELECTRIC_H
#define ELECTRIC_H

#include "Stock.h"

class Electric : public Stock
{
public:
    using Duration = unsigned long long;

    Electric();

    void SetWarranty(Duration warranty);
    Duration GetWarranty() const;

    void Serialize(SerializeStream& stream) override;
    void Deserialize(DeserializeStream& stream) override;

protected:
    StockTypes _getStockType() const override; // used for serialization
private:
    Duration m_warranty;
};
#endif // ELECTRIC_H
