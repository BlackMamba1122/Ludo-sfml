#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Dice
{
    vector<int>dice_val;

public:
    Dice();
    int roll();
    int Dice_Num();
    vector<int> get_dice();
    void delete_dice(int x);
    void empty_dice();
    int operator[](int x);
};
