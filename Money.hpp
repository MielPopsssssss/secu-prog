
#ifndef MONEY_HPP
#define MONEY_HPP
#include <iostream>

class Money
{
    private:
        int dollars;
        int cents;
    public:
        Money operator+(const Money &wallet)const;
        Money operator-(const Money &wallet)const;
        Money operator*(const double nb)const;

        bool operator==(const Money &wallet)const;
        bool operator!=(const Money &wallet)const;
        bool operator<(const Money &wallet)const;
        bool operator>(const Money &wallet)const;
        bool operator<=(const Money &wallet)const;
        bool operator>=(const Money &wallet)const;

        Money &operator+=(const Money &wallet);
        Money &operator-=(const Money &wallet);
        Money &operator*=(const double nb);
        Money &operator=(const Money &wallet);

        Money(void);
        Money(int dollars, int cents);

        friend std::ostream &operator<<(std::ostream &out, const Money &wallet);
        friend std::istream &operator>>(std::istream &in, Money &wallet);

        void setDollars(int d);
        void setCents(int c);
        int getDollars();
        int getCents();
        void addDollar(int d);
        void addCents(int c);
        void print();

};


#endif