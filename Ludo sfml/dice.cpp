#include "dice.h"

Dice::Dice()
{
    srand(time(0));
}
int Dice::roll()
{
    int val;
    //if (dice_val.size() == 0)
    //    val = 6;
    //if (dice_val.size() == 1)
    //    val = 6;
    //if (dice_val.size() == 2)
    //    val = 1;
    val = rand() % 6 + 1;
    dice_val.push_back(val);
    return val;
}
int Dice::Dice_Num()
{
    return dice_val.size();
}
vector<int> Dice::get_dice()
{
    return dice_val;
}
void Dice::delete_dice(int x)
{
    auto it = std::find(dice_val.begin(), dice_val.end(), x);
    if (it != dice_val.end())
    {
        dice_val.erase(it);
    }
}
void Dice::empty_dice()
{
    dice_val.clear();

}
int Dice::operator[](int x)
{
    return dice_val[x];
}