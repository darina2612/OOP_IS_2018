#ifndef GROCERY_H
#define GROCERY_H

#include "Stock.h"

class Grocery : public Stock
{
public:
    using Duration = unsigned long long;
    Grocery();

    void SetExpiryDate(Duration expiryDate);
    void SetLowTemperature(bool lowTemperature);

    Duration GetExpiryDate() const;
    bool GetLowTemperature() const;

    void Serialize(SerializeStream& stream) override;
    void Deserialize(DeserializeStream& stream) override;

protected:
    StockTypes _getStockType() const override; // used for serialization
private:
    Duration m_expiryDate;
    bool m_lowTemperature;
};
#endif // GROCERY_H
