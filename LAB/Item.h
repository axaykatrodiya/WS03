//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds
{
   class Item
   {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char *name);

   public:
      void setEmpty();
      void set(const char *name, double price, bool taxed);
      void display() const;
      bool isValid() const;
      double price() const;
      double tax() const;
      void display(const char *name) const;
      void display(double price) const;
      void display(bool taxed) const;
   };
}

#endif // !SDDS_SUBJECT_H