#ifndef NON_GROCERY_H
#define NON_GROCERY_H

#include "Stock.h"

class NonGrocery : public Stock
{
public:
    NonGrocery();

    void SetToxic(bool toxic);
    bool GetToxic() const;

    void Serialize(SerializeStream& stream) override;
    void Deserialize(DeserializeStream& stream) override;

protected:
    StockTypes _getStockType() const override; // used for serialization
private:
    bool m_toxic;
};

#endif // NON_GROCERY_H
