//==============================================
// Name           : AKSHAY MUKESHBHAI KATRODIYA
// Email          : amkatrodiya@myseneca.ca
// Student ID     : 125298208
// Section        : NAA
// Date           : 06/09/2021(wednesday)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "cstring.h"
namespace sdds
{

    int strLen(const char *s)
    {
        int len = 0;

        while (s[len])
        {
            len++;
        }

        return len;
    }

    void strnCpy(char *des, const char *src, int len)
    {
        int i = 0;
        if (strLen(src) >= len)
        {
            while (i < len)
            {
                des[i] = src[i];
                i++;
            }
        }
        else
        {
            while (i < strLen(src))
            {
                des[i] = src[i];
                i++;
            }
        }
        des[i] = '\0';
    }
}