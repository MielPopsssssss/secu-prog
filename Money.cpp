#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <random>
#include <iostream>
#include "Money.hpp"

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

//

Money Money::operator+(const Money &wallet)const
{
    Money temp;
    temp.dollars = dollars + wallet.dollars;
    temp.cents = cents + wallet.cents;
    if(temp.cents >= 100)
    {
        temp.cents -= 100;
        temp.dollars++;
    }
    return temp;
}

Money Money::operator-(const Money &wallet)const
{
    Money temp;
    temp.dollars = dollars - wallet.dollars;
    temp.cents = cents - wallet.cents;
    if(temp.cents < 0)
    {
        temp.cents += 100;
        temp.dollars--;
    }
    return temp;
}

Money Money::operator*(const double nb)const
{
    Money temp;
    temp.dollars = dollars * nb;
    temp.cents = cents * nb;
    if(temp.cents >= 100)
    {
        temp.dollars += temp.cents / 100;
        temp.cents %= 100;
    }
    if(temp.cents >= 100)
    {
        temp.cents -= 100;
        temp.dollars++;
    }
    return temp;
}

bool Money::operator==(const Money &wallet)const
{
    if(dollars == wallet.dollars && cents == wallet.cents)
        return true;
    else
        return false;
}

bool Money::operator!=(const Money &wallet)const
{
    if(dollars != wallet.dollars || cents != wallet.cents)
        return true;
    else
        return false;
}

bool Money::operator<(const Money &wallet)const
{
    if(dollars < wallet.dollars)
        return true;
    else if(dollars == wallet.dollars && cents < wallet.cents)
        return true;
    else
        return false;
}

bool Money::operator>(const Money &wallet)const
{
    if(dollars > wallet.dollars)
        return true;
    else if(dollars == wallet.dollars && cents > wallet.cents)
        return true;
    else
        return false;
}

bool Money::operator<=(const Money &wallet)const
{
    if(dollars < wallet.dollars)
        return true;
    else if(dollars == wallet.dollars && cents <= wallet.cents)
        return true;
    else
        return false;
}

bool Money::operator>=(const Money &wallet)const
{
    if(dollars > wallet.dollars)
        return true;
    else if(dollars == wallet.dollars && cents >= wallet.cents)
        return true;
    else
        return false;
}

Money &Money::operator+=(const Money &wallet)
{
    dollars += wallet.dollars;
    cents += wallet.cents;
    if(cents >= 100)
    {
        cents -= 100;
        dollars++;
    }
    return *this;
}

Money &Money::operator-=(const Money &wallet)
{
    dollars -= wallet.dollars;
    cents -= wallet.cents;
    if(cents < 0)
    {
        cents += 100;
        dollars--;
    }
    return *this;
}

Money &Money::operator*=(const double nb)
{
    dollars *= nb;
    cents *= nb;
    while(cents >= 100)
    {
        cents -= 100;
        dollars++;
    }
    if(cents >= 100)
    {
        cents -= 100;
        dollars++;
    }
    return *this;
}

Money &Money::operator=(const Money &wallet)
{
    dollars = wallet.dollars;
    cents = wallet.cents;
    return *this;
}

Money::Money(void)
{
    dollars = 0;
    cents = 0;
}

Money::Money(int dollars, int cents)
{
    this->dollars = dollars;
    this->cents = cents;
}

std::ostream &operator<<(std::ostream &out, const Money &wallet)
{
    out << "$" << wallet.dollars << "." << wallet.cents;
    return out;
}

std::istream &operator>>(std::istream &in, Money &wallet)
{
    char dollarSign;
    in >> dollarSign;
    if(dollarSign != '$')
    {
        cout << "Error: No dollar sign in money input.";
        exit(1);
    }
    in >> wallet.dollars;
    in >> wallet.cents;
    return in;
}







int main()
{
    //test Money class
    Money wallet1(5, 50);
    Money wallet2(10, 25);
    Money wallet3;
    Money wallet4(5, 50);
    Money wallet5(10, 25);
    Money wallet6(5, 50);
    Money wallet7(10, 25);
    Money wallet8(5, 50);
    Money wallet9(10, 25);


    double ze_random = fRand(2.0,100.0);
    ze_random = ceil(ze_random*100)/100;

    cout << "wallet1 = " << wallet1 << endl;
    cout << "wallet2 = " << wallet2 << endl;
    cout << "wallet3 = " << wallet3 << endl;
    cout << "wallet4 = " << wallet4 << endl;
    cout << "wallet5 = " << wallet5 << endl;
    cout << "wallet6 = " << wallet6 << endl;

    cout << "wallet1 + wallet2 = " << wallet1 + wallet2 << endl;
    cout << "wallet1 - wallet2 = " << wallet1 - wallet2 << endl;
    cout << "wallet1 * " << ze_random << " = " << wallet1 * ze_random << endl;

    cout << "wallet1 == wallet2 = " << (wallet1 == wallet2) << endl;
    cout << "wallet1 != wallet2 = " << (wallet1 != wallet2) << endl;
    cout << "wallet1 < wallet2 = " << (wallet1 < wallet2) << endl;
    cout << "wallet1 > wallet2 = " << (wallet1 > wallet2) << endl;
    cout << "wallet1 <= wallet2 = " << (wallet1 <= wallet2) << endl;
    cout << "wallet1 >= wallet2 = " << (wallet1 >= wallet2) << endl;

    cout << "wallet1 == wallet4 = " << (wallet1 == wallet4) << endl;
    cout << "wallet1 != wallet4 = " << (wallet1 != wallet4) << endl;
    cout << "wallet1 < wallet4 = " << (wallet1 < wallet4) << endl;
    cout << "wallet1 > wallet4 = " << (wallet1 > wallet4) << endl;

    cout << "wallet1 += wallet2 = " << (wallet1 += wallet2) << endl;
    cout << "wallet1 -= wallet2 = " << (wallet1 -= wallet2) << endl;
    cout << "wallet1 *= "<< ze_random <<"= " << (wallet1 *= ze_random) << endl;

    cout << "wallet1 = wallet2 = " << (wallet1 = wallet2) << endl;

    return 0;


}