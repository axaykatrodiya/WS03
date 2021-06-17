//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "Food.h"

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
namespace sdds
{
    class CalorieList
    {
        int m_totalFoodItems;
        int m_counter;
        Food *m_food;

        bool isValid() const;
        int totalCal() const;
        void Title() const;
        void Footer() const;

    public:
        CalorieList();
        ~CalorieList();
        void init(int totalFood);
        bool add(const char *food_name, int calNum, int consumTime);
        void display() const;
        void deallocate();
    };
} // namespace sdds
#endif