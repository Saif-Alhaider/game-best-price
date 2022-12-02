#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

#include "./currency_functions.h"
// 16380.5 dianr ≈ 16500 dinar
double roundIraqiPrice(double originalPrice)
{
    double price = originalPrice;
    while (price > 250)
    {
        price = price - 250;
    }
    double leftPrice = 250 - price;

    return originalPrice + leftPrice;
}
// round by 10 or 100 || roundUp(493, 10) = 500
int roundUp(int numToRound, int multiple)
{
    assert(multiple);
    return ((numToRound + multiple - 1) / multiple) * multiple;
}

// array sum all numbers

double totalArraySum(vector<int> list)
{
    double sum = 0;
    for (double const &i : list)
    {
        sum += i;
    }
    return sum;
}

void bestPrice(double cardPurchaseUsd, double globalKeyUsd, double const transactionFee, double const NetworkPaymentFee)
{
    cout << "best option: ";
    if (cardPurchaseUsd < globalKeyUsd)
    {
        cout << "gift cards\nyou can save " << globalKeyUsd - cardPurchaseUsd << "$" << endl;
        cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(globalKeyUsd, transactionFee, NetworkPaymentFee)) - roundIraqiPrice(usdToIqd(cardPurchaseUsd, transactionFee, NetworkPaymentFee));
        return;
    }
    cout << "global key\nyou can save " << cardPurchaseUsd - globalKeyUsd << "$" << endl;
    cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(cardPurchaseUsd, transactionFee, NetworkPaymentFee)) - roundIraqiPrice(usdToIqd(globalKeyUsd, transactionFee, NetworkPaymentFee));
}

// convert usd to iqd with fee 500 dinar due to zain cash transaction fee
// final price in iraqi dinar
double usdToIqd(double price, double const transactionFee, double const networkPaymentFee)
{
    return ((price + networkPaymentFee) * 1480) + transactionFee;
}