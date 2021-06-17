//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include "CalorieList.h"

using namespace std;

namespace sdds
{

    bool CalorieList::isValid() const
    {
        bool flow = true;
        bool flag = true;

        for (int i = 0; i < m_totalFoodItems && flag; i++)
        {
            if (!m_food[i].isValid())
            {
                flow = false;
                flag = false;
            }
        }

        return flow;
    }

    int CalorieList::totalCal() const
    {
        int result = 0;

        for (int i = 0; i < m_totalFoodItems; i++)
        {
            result += m_food[i].calorie();
        }

        return result;
    }

    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+\n";
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |\n";
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |\n";
        }

        cout << "+--------------------------------+------+------------+\n";
        cout << "| Food name                      | Cals | When       |\n";
        cout << "+--------------------------------+------+------------+\n";
    }

    void CalorieList::Footer() const
    {
        cout << "+--------------------------------+------+------------+\n";
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << totalCal() << " |            |\n";
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |\n";
        }

        cout << "+----------------------------------------------------+\n";
    }

    CalorieList::CalorieList()
    {
        m_food = nullptr;
        m_totalFoodItems = 0;
        m_counter = 0;
    }

    CalorieList::~CalorieList()
    {
        if (m_food != nullptr)
        {
            delete[] m_food;
            m_food = nullptr;
        }
    };

    void CalorieList::init(int totalFood)
    {
        if (totalFood > 0)
        {
            m_totalFoodItems = totalFood;
            m_counter = 0;
            m_food = new Food[totalFood];
        }
    }

    bool CalorieList::add(const char *f_name, int cals, int when)
    {
        bool result = false;
        if (m_counter < m_totalFoodItems)
        {
            m_food[m_counter].set(f_name, cals, when);
            m_counter++;
            result = true;
        }
        return result;
    }

    void CalorieList::display() const
    {
        Title();

        for (int i = 0; i < m_totalFoodItems; i++)
        {
            m_food[i].display();
        }

        Footer();
    }

    void CalorieList::deallocate()
    {
        delete[] m_food;
        m_food = nullptr;
    }
}