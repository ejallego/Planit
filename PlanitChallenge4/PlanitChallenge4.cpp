// PlanitChallenge4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct MyList {
    std::string store;
    std::string price;
};

void printStoreOrders(std::map<std::string, std::vector<std::string>> shopList)
{
    //print orders sent to restaurant
    std::cout << "==================================" << std::endl;
    for (auto shopit = shopList.begin(); shopit != shopList.end(); ++shopit)
    {
        std::cout << "Orders for " << shopit->first << ": ";
        for (size_t itr = 0; itr < shopit->second.size(); itr++)
        {
            if (itr != 0)
                std::cout << ", ";

            std::cout << shopit->second[itr];
        }
        std::cout << std::endl;
    }
}

void setFoodMapData(std::map<std::string, MyList>& foodMap)
{
    foodMap["pepperoni pizza"] = { "Awesome Pizza Place", "$20" };
    foodMap["cheese pizza"] = { "Awesome Pizza Place", "$8" };
    foodMap["chicken wings"] = { "Awesome Pizza Place", "$12" };
    foodMap["garlic bread"] = { "Awesome Pizza Place", "$5" };
    foodMap["burger"] = { "Wild Burger Joint", "$15" };
    foodMap["milkshake"] = { "Wild Burger Joint", "$8" };
    foodMap["thickshake"] = { "Wild Burger Joint", "$9" };
    foodMap["soda"] = { "Wild Burger Joint", "$3" };
}

int main()
{
    std::map<std::string, MyList> foodMap;
    std::map<std::string, std::vector<std::string>> shopList;

    std::string input;
    bool quit = false;
    
    setFoodMapData(foodMap);                        //set foodmap data
    
    while (!quit) {
        std::cout << "Input order or 'q' to quit: ";
        std::getline(std::cin, input);

        if (input == "q")
        {
            quit = true;
            continue;
        }

        auto it = foodMap.find(input);
        if (it != foodMap.end())
        {
            std::cout << it->second.store << ", " << input << ", " << it->second.price << std::endl;

            if (shopList.find(it->second.store) != shopList.end()) 
            {
                auto itr = shopList.find(it->second.store);
                itr->second.push_back(input);
            }
            else
            {
                std::vector<std::string> order;
                order.push_back(input);
                shopList[it->second.store] = order;
            }
        }
        else
            std::cout << "Not found!" << std::endl;
    }

    printStoreOrders(shopList);                     //print store orders
}