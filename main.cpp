#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <algorithm>
using namespace std;
void printArray(vector<int> list);
void leastPriceUsd(double gamePriceLira, double &gameGiftCardPriceUsdG2A);
double totalArraySum(vector<int> list);
double roundIraqiPrice(double originalPrice);
double usdToIqd(double price)
{
    return (price * 1480) + 500;
}
void lessPrice(double cardPurchaseUsd, double globalKeyUsd);
void headLine(string title);
int roundUp(int numToRound, int multiple);
int main()
{
    string gameTitle;
    double steamPriceLira;
    double gameGiftCardPriceUsdG2A = 0;
    double g2aGameGlobalKeyPrice;
    //{{tl card,price in usd}}

    cout << "please enter the game title: ";
    getline(cin, gameTitle); // cyberpunk 2077
    cout << "Enter " + gameTitle << " price in steam in lira: ";
    cin >> steamPriceLira; // 124,50 tl
    cout << "Enter " + gameTitle << " global key price in g2a in usd: ";
    cin >> g2aGameGlobalKeyPrice; // 33.92 usd
    headLine("By Gift Card");
    leastPriceUsd(steamPriceLira, gameGiftCardPriceUsdG2A);
    headLine("By Global Key");
    cout << "price of the global key in iraqi dinar with 500 fee is: " << usdToIqd(g2aGameGlobalKeyPrice) << " rounded to " << roundIraqiPrice(usdToIqd(g2aGameGlobalKeyPrice))<<" "<<endl;
     headLine("best option");
    lessPrice(gameGiftCardPriceUsdG2A,g2aGameGlobalKeyPrice);
}

void leastPriceUsd(double gamePriceLira, double &gameGiftCardPriceUsdG2A)
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
    gamePriceLira = roundUp(gamePriceLira,10);
    for (size_t i = 6; i != -1; i--)
    {
    cashagain:
        if (gamePriceLira >= steamGiftCardUsd[i][0])
        {
            usedCards.push_back(steamGiftCardUsd[i][0]);
            cout << gamePriceLira << " - " << steamGiftCardUsd[i][0] << " = " << gamePriceLira - steamGiftCardUsd[i][0] << endl;
            gamePriceLira = gamePriceLira - steamGiftCardUsd[i][0];
            if (gamePriceLira > steamGiftCardUsd[i][0])
            {
                goto cashagain;
            }

            if (gamePriceLira < 10 && gamePriceLira != 0)
            {
                usedCards.push_back(steamGiftCardUsd[0][0]);
            }
        }
        else if (gamePriceLira < 10 && gamePriceLira !=0)
        {
            usedCards.push_back(steamGiftCardUsd[0][0]);
            break;
        }
    }

    gamePriceLira = steamGiftCardUsd[0][0] - gamePriceLira;

    printArray(usedCards);
    cout << totalArraySum(usedCards) << " tl" << endl;
    cout << "left over: " << gamePriceLira << " tl" << endl;

    for (auto i : usedCards)
        for (auto j : steamGiftCardUsd)
            if (i == j[0])
                gameGiftCardPriceUsdG2A += j[1];

    cout << "price in dollar is: " << gameGiftCardPriceUsdG2A << '$' << endl;
    double priceInIraqiDinar = usdToIqd(gameGiftCardPriceUsdG2A);
    cout << "price in dinar with fee 500 dinar is: " << priceInIraqiDinar << " dinar "
         << "rounded to " << roundIraqiPrice(priceInIraqiDinar) << endl;
}

void printArray(vector<int> list)
{
    sort(list.begin(), list.end());

    cout << '[';
    for (int i = 0; i < list.size(); i++)
    {
        if (i == list.size() - 1)
        {
            cout << list[i];
            break;
        }
        cout << list[i] << ',';
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
    cout << "best option: ";
    if (cardPurchaseUsd < globalKeyUsd)
    {
        cout << "gift cards\nyou can save " << globalKeyUsd - cardPurchaseUsd << "$" << endl;
        cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(globalKeyUsd)) - roundIraqiPrice(usdToIqd(cardPurchaseUsd));
        return;
    }
    cout << "global key\nyou can save " << cardPurchaseUsd - globalKeyUsd << "$" << endl;
    cout << "or you can save in dinar " << roundIraqiPrice(usdToIqd(cardPurchaseUsd)) - roundIraqiPrice(usdToIqd(globalKeyUsd));
}

void headLine(string title){
    cout << "+" << setw(7 + title.length()) << setfill('-') << "" << setw(7) << ""
         << "+" << endl;
    cout.fill(' ');
    cout << '|' << setw(7) << "" << title << setw(7) << ""
         << "|" << endl;
    cout << "+" << setw(7 + title.length()) << setfill('-') << "" << setw(7) << ""
         << "+" << endl;
}
int roundUp(int numToRound, int multiple) 
{
    assert(multiple);
    return ((numToRound + multiple - 1) / multiple) * multiple;
}