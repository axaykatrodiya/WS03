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
#include "Bill.h"
using namespace std;
namespace sdds
{

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid() const
    {
        bool flow = true;
        bool flag = true;

        for (int i = 0; i < m_noOfItems && flag; i++)
        {
            if (!m_items[i].isValid())
            {
                flow = false;
                flag = false;
            }
        }

        return flow;
    }
    double Bill::totalTax() const
    {
        double result = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            result += m_items[i].tax();
        }
        return result;
    }

    double Bill::totalPrice() const
    {
        double result = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            result += m_items[i].price();
        }

        return result;
    }
    void Bill::Title() const
    {
        cout << "+--------------------------------------+\n";
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
            cout.unsetf(ios::left);
        }
        else
        {
            cout << "| Invalid Bill                         |\n";
        }

        cout << "+----------------------+---------+-----+\n";
        cout << "| Item Name            | Price   + Tax |\n";
        cout << "+----------------------+---------+-----+\n";
    }
    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+\n";

        if (isValid())
        {
            cout << "|                Total Tax: ";
            display(totalTax());
            cout << "|              Total Price: ";
            display(totalPrice());
            cout << "|          Total After Tax: ";
            display(totalTax() + totalPrice());
        }
        else
        {
            cout << "| Invalid Bill                         |\n";
        }

        cout << "+--------------------------------------+\n";
    }
    void Bill::display(double price) const
    {
        cout.width(10);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << price << " |" << endl;
        cout.unsetf(ios::fixed);
    }
    void Bill::init(const char *title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[noOfItems];
            for (int i = 0; i < noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char *item_name, double price, bool taxed)
    {
        bool flow = false;
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            flow = true;
        }
        return flow;
    }
    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }
    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }

}