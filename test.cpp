#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
double roundIraqiPrice(double originalPrice)
{
    double price = originalPrice;
    while (price > 250)
    {
        price = price - 250;
    }
    double leftPrice = 250 - price;
    cout << originalPrice+ leftPrice;

    return originalPrice+ int(leftPrice);
}

int main()
{
    roundIraqiPrice(16380.4);
}

/*

if value is greater than value behind it and not equal values in dinar list that are less than 1000
25600 - 25000 = 600 < 750
=> 750 - 600 = 150 => 25600 + 150 = 25750
50,240 - 50000 = 240 < 250
50,100 - 50000 = 100 < 250
else if value is less than value behind it and equal values in dinar list that are less than 1000
12,000 - 10,000 = 2,000 - 1000 = 1000 - 1000 = 0 ! done

3,750 - 1000 = 2750 - 1000 = 1750 - 1000 = 750 - 500 = 250 - 250 =0 ! done

else if value is less than 1000 and not equals values in the list
100 < 250 = 250

790 <750
*/
// 16380 = 10000 + 6000 + 380
// 16380 / 10^4 = 10000

/*
if (price > iraqiDinarPrices[i] )
        {
            cout << price << " - " << iraqiDinarPrices[i] << " = " << price - iraqiDinarPrices[i] << endl;
            price = price - iraqiDinarPrices[i];

            if (price < 1000 && !isContain(price, iraqiDinarPrices))
            {
                cout << price<< endl;
                goto jmp;
            }
            if (price == 250)
                price = 0;
        }

        jmp:
    for (int i = 0; i < 3; i++)
    {
        if (price < iraqiDinarPrices[i])
        {
            price = iraqiDinarPrices[i];
            break;
        }
    }
*/