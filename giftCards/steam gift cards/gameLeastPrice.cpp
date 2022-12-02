#include <iostream>
#include <string>
using namespace std;
#include "gameLeastPrice.h"

void gameLeastPrice(double const transactionFee,double const NetworkPaymentFee)
{
    string gameTitle;
    double gamePriceLira;
    double gameGiftCardPriceUsdG2A = 0;
    double g2aGameGlobalKeyPrice;
    giftCard();
    //{{tl card,price in usd}}

    cin.ignore();
    cout << "please enter the game title: ";
    getline(cin, gameTitle); // cyberpunk 2077
    cout << "Enter " + gameTitle << " price in steam in lira: ";
    cin >> gamePriceLira; // 124,50 tl
    cout << "Enter " + gameTitle << " global key price in g2a in usd: ";
    cin >> g2aGameGlobalKeyPrice; // 33.92 usd
    headLine("By Gift Card");
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
    double originalPrice = gamePriceLira;
    gamePriceLira = roundUp(gamePriceLira, 10);
    for (size_t i = 6; i != -1; i--)
    {
    cashagain:
        if (gamePriceLira >= steamGiftCardUsd[i][0])
        {
            usedCards.push_back(steamGiftCardUsd[i][0]);
            // cout << gamePriceLira << " - " << steamGiftCardUsd[i][0] << " = " << gamePriceLira - steamGiftCardUsd[i][0] << endl;
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
        else if (gamePriceLira < 10 && gamePriceLira != 0)
        {
            usedCards.push_back(steamGiftCardUsd[0][0]);
            break;
        }
    }

    gamePriceLira = steamGiftCardUsd[0][0] - gamePriceLira;
    cout << "gift cards to buy: ";
    printArray(usedCards);
    cout << totalArraySum(usedCards) << " tl" << endl;
    cout << "left over: " << totalArraySum(usedCards) - originalPrice << " tl" << endl;

    for (auto i : usedCards)
        for (auto j : steamGiftCardUsd)
            if (i == j[0])
                gameGiftCardPriceUsdG2A += j[1];

    cout << "price in dollar is: " << gameGiftCardPriceUsdG2A << '$' << endl;
    double priceInIraqiDinar = usdToIqd(gameGiftCardPriceUsdG2A,transactionFee,NetworkPaymentFee);
    cout << "price in dinar with fee "<< transactionFee<<"IQD"<<"and network payment fee with "<<NetworkPaymentFee<<'$'<<"is: "<< priceInIraqiDinar << " dinar "
         << "rounded to " << roundIraqiPrice(priceInIraqiDinar) << endl;
    headLine("By Global Key");
    cout << "price of the global key in iraqi dinar with " <<transactionFee<<"IQD"  <<" and "<<NetworkPaymentFee<<'$'<<" fee is: "<< usdToIqd(g2aGameGlobalKeyPrice,transactionFee,NetworkPaymentFee) << " rounded to " << roundIraqiPrice(usdToIqd(g2aGameGlobalKeyPrice,transactionFee,NetworkPaymentFee)) << " " << endl;
    headLine("best option");
    bestPrice(gameGiftCardPriceUsdG2A, g2aGameGlobalKeyPrice,transactionFee,NetworkPaymentFee);
}