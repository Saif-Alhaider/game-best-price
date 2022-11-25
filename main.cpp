#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void printArray(vector<int> list);
void leastPriceUsd(double gamePriceLira, double &g2aGamePriceUsd);
double totalArraySum(vector<int> list);
double roundIraqiPrice(double originalPrice);
double usdToIqd(double price)
{
    return (price * 1480) + 500;
}
void lessPrice(double cardPurchaseUsd, double globalKeyUsd);
int main()
{
    string gameTitle;
    double steamPriceLira;
    double g2aGamePriceUsd = 0;
    double g2aGameGlobalKeyPrice;
    //{{tl card,price in usd}}

    cout << "please enter the game title: ";
    getline(cin, gameTitle); // cyberpunk 2077
    cout << "Enter " + gameTitle << " price in steam in lira: ";
    cin >> steamPriceLira; // 124,50 tl
    leastPriceUsd(steamPriceLira, g2aGamePriceUsd);
    cout << "Enter " + gameTitle << " global key price in g2a in usd: ";
    cin >> g2aGameGlobalKeyPrice; // 33.92 usd
    cout << "price of the global key in iraqi dinar is: " << usdToIqd(g2aGameGlobalKeyPrice) << " rounded to " << roundIraqiPrice(usdToIqd(g2aGameGlobalKeyPrice))<<" ";
    lessPrice(g2aGamePriceUsd,g2aGameGlobalKeyPrice);
}

void leastPriceUsd(double gamePriceLira, double &g2aGamePriceUsd)
{
    double steamGiftCardUsd[7][2] = {
        {10, 1.33},
        {20, 2.01},
        {50, 3.95},
        {100, 7.39},
        {200, 14.83},
        {250, 17.90},
        {300, 21.96},
    };
    vector<int> usedCards;
    for (size_t i = 6; i != 0; i--)
    {
        if (gamePriceLira > steamGiftCardUsd[i][0])
        {
            cout << gamePriceLira << " - " << steamGiftCardUsd[i][0] << " = " << gamePriceLira - steamGiftCardUsd[i][0] << endl;
            usedCards.push_back(steamGiftCardUsd[i][0]);
            gamePriceLira = gamePriceLira - steamGiftCardUsd[i][0];
            if (gamePriceLira > 10)
            {
                usedCards.push_back(steamGiftCardUsd[0][0]);
            }
        }
    }
    gamePriceLira = steamGiftCardUsd[0][0] - gamePriceLira;
    cout << string(100, '-') << endl;
    cout << "gift cards to buy in tl" << endl;
    printArray(usedCards);
    cout << totalArraySum(usedCards) << " tl" << endl;
    cout << "left over: " << gamePriceLira << " tl" << endl;

    for (auto i : usedCards)
        for (auto j : steamGiftCardUsd)
            if (i == j[0])
                g2aGamePriceUsd += j[1];

    cout << "price in dollar is: " << g2aGamePriceUsd << '$' << endl;
    double priceInIraqiDinar = usdToIqd(g2aGamePriceUsd);
    cout << "price in dinar with fee 500 dinar is: " << priceInIraqiDinar << " dinar "
         << "rounded to " << roundIraqiPrice(priceInIraqiDinar) << endl;
}

void printArray(vector<int> list)
{
    sort(list.begin(), list.end());

    cout << '[';
    for (auto const &i : list)
    {
        if (i == list[list.size() - 1])
            cout << i;
        else
            cout << i << ',';
    }
    cout << ']';
    cout << endl;
}

double totalArraySum(vector<int> list)
{
    double sum = 0;
    for (double const &i : list)
    {
        sum += i;
    }
    return sum;
}

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

void lessPrice(double cardPurchaseUsd, double globalKeyUsd)
{
    if (cardPurchaseUsd < globalKeyUsd)
    {
        cout << "buying the game using gift cards is the best option you can save " << globalKeyUsd - cardPurchaseUsd << "$" << endl;
        cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(globalKeyUsd)) - roundIraqiPrice(usdToIqd(cardPurchaseUsd));
        return;
    }
    cout << "buying the game using global key is the best option you can save " << cardPurchaseUsd - globalKeyUsd << "$" << endl;
    cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(cardPurchaseUsd)) - roundIraqiPrice(usdToIqd(globalKeyUsd));
}