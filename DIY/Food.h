//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
    class Food
    {
        char m_foodName[31];
        int m_cals;
        int m_when;

    public:
        Food();
        void set(const char *fname, int cal, int time);
        bool isValid() const;
        int calorie() const;
        void display() const;
        void display(const char *name) const;
        void display(int time) const;
    };
}
#endif