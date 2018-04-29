#include <iostream>

struct box
{
    int data;
    box* next;

    box(int data, box* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void insert123AfterOdds(box* listStart)
{
    box* currentElement = listStart;

    while(currentElement != nullptr)
    {
        if(currentElement->data % 2 != 0)
        {
            //добавяме 123 след текущия нечетен елемент, само ако след него вече няма 123 или ако е последен
            if(currentElement->next == nullptr || currentElement->next->data != 123)
            {
                box* newElement = new box(123);
                newElement->next = currentElement->next;
                currentElement->next = newElement;
            }

            //След като сме добавили 123 след текущия(или след текущия вече е имало 123),
            //то седващият на текущия е отново нечетен (123 е нечетно).
            //Искаме да "прескочим" новодобавения елемент, за да избегнем безкрайно добавяне на 123, затова:
            currentElement = currentElement->next;

            if(currentElement ==  nullptr)
            {
                break;
            }
        }

        currentElement = currentElement->next;
    }
}

int sumOfDigits(int number)
{
    if(number < 0)
    {
        number *= -1;
    }

    int sum = 0;

    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

//предаваме по референция указател към началото на списъка с цел ако първия елемент трябва да бъде изтрит,
//то на подадения указател да се присвои адреса на новия пръв елемент
void removeElementsWithEvenDigitsSum(box*& listStart)
{
    box* currentElement = listStart;
    box* previousElement = nullptr;

    while(currentElement != nullptr)
    {
        if(sumOfDigits(currentElement->data) % 2 == 0)
        {
            if(previousElement != nullptr)
            {
                previousElement->next = currentElement->next;
            }

            box* currentCopy = currentElement;
            currentElement = currentElement->next;

            //присвояваме на указателя към първия елемент провилната стойност
            if(currentCopy == listStart)
                listStart = currentElement;

            delete currentCopy;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }

}

void printList(box* listStart)
{
    box* currentElement = listStart;

    while(currentElement != nullptr)
    {
        std::cout << currentElement->data << " ";
        currentElement = currentElement->next;
    }

    std::cout << std::endl;
}

void deleteList(box* listStart)
{
    box* currentElement = listStart;

    while(currentElement != nullptr)
    {
        box* currentCopy = currentElement;
        currentElement = currentElement->next;

        delete currentCopy;
    }
}

int main()
{
    box* listStart = new box(13, new box (44, new box(12, new box(111, nullptr))));

    insert123AfterOdds(listStart);
    printList(listStart);

    removeElementsWithEvenDigitsSum(listStart);
    printList(listStart);

    deleteList(listStart);

    return 0;
}
