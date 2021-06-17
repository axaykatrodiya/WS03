//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include "cstring.h"
#include "Item.h"
#define TAX 0.13
using namespace std;
namespace sdds
{
    void Item::setName(const char *name)
    {
        strnCpy(m_itemName, name, 20);
    }
    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = 0.0;
    }
    void Item::set(const char *name, double price, bool taxed)
    {
        if (name != nullptr && price > 0)
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
        else
        {
            setEmpty();
        }
    }
    double Item::price() const
    {
        return m_price;
    }
    double Item::tax() const
    {
        double tax = 0.0;
        if (m_taxed)
        {
            tax = (m_price * TAX);
        }
        return tax;
    }
    bool Item::isValid() const
    {
        bool result = false;
        if (*m_itemName != '\0' && m_price > 0)
        {
            result = true;
        }

        return result;
    }
    void Item::display() const
    {
        if (isValid())
        {
            display(m_itemName);
            display(m_price);
            display(m_taxed);
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
    void Item::display(const char *name) const
    {
        char pad = cout.fill('.');
        cout << "| ";
        cout.setf(ios::left);
        cout.width(20);
        cout << m_itemName;
        cout.fill(pad);
        cout.unsetf(ios::left);
    }

    void Item::display(double price) const
    {
        cout << " | ";
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << m_price;
        cout.unsetf(ios::fixed);
    }

    void Item::display(bool taxed) const
    {
        if (taxed == 1)
        {
            cout << " | Yes |" << endl;
        }
        else if (taxed == 0)
        {
            cout << " | No  |" << endl;
        }
    }
}
