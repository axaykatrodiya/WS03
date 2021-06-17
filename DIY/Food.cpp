//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include "Food.h"
#include "cstring.h"
using namespace std;

namespace sdds
{
    Food::Food()
    {
        m_foodName[0] = '\0';
        m_cals = -1;
        m_when = 0;
    }

    void Food::set(const char *fname, int cal, int time)
    {
        if (fname != nullptr && fname[0] != '\0' && cal > -1 && cal <= 3000 && time > 0 && time < 5)
        {
            strnCpy(m_foodName, fname, 30);
            m_cals = cal;
            m_when = time;
        }
    }

    bool Food::isValid() const
    {
        bool result = false;
        if (m_foodName[0] != '\0')
        {
            result = true;
        }
        return result;
    }

    int Food::calorie() const
    {
        return m_cals;
    }

    void Food::display() const
    {
        if (isValid())
        {
            display(m_foodName);

            cout << " | ";
            cout.width(4);
            cout << m_cals;

            display(m_when);
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    void Food::display(const char *name) const
    {
        char padding = cout.fill('.');
        cout << "| ";
        cout.setf(ios::left);
        cout.width(30);
        cout << name;
        cout.fill(padding);
        cout.unsetf(ios::left);
    }

    void Food::display(int time) const
    {
        cout << " | ";
        cout.setf(ios::left);
        cout.width(11);

        if (time == 1)
        {
            cout << "Breakfast"
                 << "|\n";
        }
        else if (time == 2)
        {
            cout << "Lunch"
                 << "|\n";
        }
        else if (time == 3)
        {
            cout << "Dinner"
                 << "|\n";
        }
        else if (time == 4)
        {
            cout << "Snack"
                 << "|\n";
        }
        cout.unsetf(ios::left);
    }
}