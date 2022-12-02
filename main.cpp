#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#include "./currency functions/currency_functions.cpp"
#include "./currency functions/currency_functions.h"

#include "./styling/styling.cpp"
#include "./styling/styling.h"

#include "giftCards/steam gift cards/gameLeastPrice.h"
#include "giftCards/steam gift cards/gameLeastPrice.cpp"
void gameLeastPrice();

int main()
{
    int answer;
    headLine("please select what gift card you want to buy");
    string choices[5] = {"convert usd price to iqd zain cash price", "Steam Gift Card", "Least Price Steam Game (buying steam key or gift card)", "Netflix Gift Card", "Xbox Game Pass Gift Card"};
    for (size_t i = 0; i < 5; i++)
        cout << i + 1 << ". " << choices[i] << endl;

    cin >> answer;
    if (answer == 1)
    {
        double transactionFee;    // in dinar IQD
        double networkPaymentFee; // in dollar $
        double productPrice = 0;
        string input;
        cout << "enter product price in dollar: ";
        cin >> productPrice;
        cin.ignore();
        cout << "please enter zain cash dinar to dollar transactionFee fee (500IQD): ";

        if (std::cin.peek() == '\n')
            transactionFee = 500;
        else if (!(cin >> transactionFee))
            cout << "Invalid input.\n";
        cin.ignore();

        cout << "please enter zain cash network payment fee (0.75$): ";
        if (std::cin.peek() == '\n')
            networkPaymentFee = 0.75;
        else if (!(cin >> networkPaymentFee))
            cout << "Invalid input.\n";

        cout << "price in dollar with " << networkPaymentFee << '$' << " and " << transactionFee << " dinar is: " << usdToIqd(productPrice, transactionFee, networkPaymentFee) / 1480 << '$' << endl;
        
        cout << "price in dinar with " << networkPaymentFee << '$' << " and " << transactionFee << " dinar is: " << usdToIqd(productPrice, transactionFee, networkPaymentFee) << "IQD"
             << " rounded to " << roundIraqiPrice(usdToIqd(productPrice, transactionFee, networkPaymentFee)) << "IQD" << endl;
    }
    else if (answer == 2)
    {

        double transactionFee = 500;     // in dinar IQD
        double networkPaymentFee = 0.75; // in dollar $
        cout << "please enter zain cash dinar to dollar transactionFee fee (500IQD): ";
        cin >> transactionFee;
        cout << "please enter zain cash network payment fee (0.75$): ";
        cin >> networkPaymentFee;
        gameLeastPrice(transactionFee, networkPaymentFee);
    }
}
