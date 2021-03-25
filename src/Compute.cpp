#include "Compute.h"
#include <algorithm>




Compute::Compute()
{
    // std::cout << " hello compute" << std::endl;
}

template<typename T>
bool Compute::operator()(T const &a, T const &b) const { return a > b; } // because std::reverse  doesn't work


float Compute::get_weeknumber_data(Datamanager &obj, const int weeknummer)
{
    auto header_data = obj.get_header_box();
    std::vector<float> mydata;
    size_t i = 0;
    float header_value = 0.0;

    for (auto &data : header_data)
    {
        if (i != 0)
            mydata.push_back(obj.get_week_item_data(weeknummer, data));
        i++;
    }

    for (auto &value : mydata)
    {
        header_value += value;
    }

    return header_value;
}



float Compute::get_year_data(Datamanager &obj)
{
    return 1;
}


std::vector<int> Compute::get_weekindex(const int start_point, const uint8_t Week_sise)
{
    std::vector<int> result;
    result.clear();
    for (size_t i = 0; i < Week_sise; i++)
    {
        auto data = i + start_point;
        result.push_back(data); // todo maybe use array or don't forget to erase the data before using it again (otherwise bugs)
    }
    return result;
}

std::vector<int> Compute::test_test(int starting_point, Month my_month,  const uint8_t my_week_size)
{
    // std::vector<int> result = this->get_weekindex(starting_point, my_week_size);
    auto result = this->get_weekindex(starting_point, my_week_size);
    // Month my_month;
    // Weeks my_week_size;

    // switch (my_month)
    // {
    // case january:
    //     starting_point =1;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // case february:
    //     starting_point = 5;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // case march:
    //     starting_point = 9;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // case april:
    //     starting_point = 14;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // case may:
    //     starting_point = 18;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // case june:
    //     // starting_point = 1;
    //     result = this->get_weekindex(starting_point, my_week_size);
    //     break;
    // default:
    //     std::cout << "Default: Value is:000 " << 0 << std::endl;
    // }

    // for (size_t i = 0; i < result.size(); i++)
    // {
    //     /* code */
    // }

    for (auto it = result.begin(); it != result.end(); ++it)
        std::cout <<"++++++>>" << *it;

    std::cout << "\n";

    return result;
}

float Compute::get_monthnumber_data(Datamanager &obj, int starting_point,  const uint8_t my_week_size)
{
    // std::vector<int> result = this->get_weekindex(starting_point, my_week_size);
    auto data_week = this->get_weekindex(starting_point, my_week_size);
    float result = 0;

    for (auto it = data_week.begin(); it != data_week.end(); ++it)
        std::cout <<"++++++>>" << *it;

    std::cout << "\n";

    for (auto &i : data_week)
    {
        result += this->get_weeknumber_data(obj, i);
    }

    return result;
}

float Compute::get_Q_data(Datamanager &obj, int starting_point)
{
    const uint8_t myweek_size = 0; // todo replace with kind of month_size
    auto month_data = this->get_monthnumber_data(obj, starting_point, myweek_size);
    return 1.0;
}

template<typename T>
std::vector<T> Compute::sort_data(std::vector<T> input_data, const char L_or_H )
{
    auto myvector = input_data;
    std::vector<T> result;
    if (L_or_H == 'H')
    {
        std::sort(myvector.begin(), myvector.end(), Compute());
        for (auto &i : myvector)
            result.push_back(i);
    }
    else if (L_or_H =='L')
    {
        std::sort(myvector.begin(), myvector.end());
        for (auto &i : myvector)
            result.push_back(i);
    }
    else
        result.clear();
    return result;
}

void Compute::test_me_(Datamanager &obj)
{
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33, 1};
    std::vector<int> myvector(myints, myints + 9); // 32 71 12 45 26 80 53 33
    std::vector<float> v;
    for (size_t i = 0; i < 7; i++)
    {
        v.push_back(i);
    }


    auto vv = this->sort_data(myvector, 'H');
    for (auto& i : vv)
    {
        std::cout << "=> " << i << std::endl;
    }

    std::cout << "=============> " << std::endl;
    auto vvc = this->sort_data(myvector, 'S');
        std::cout << "=>. "  << std::endl;
    for (auto& i : vvc)
    {
        std::cout << "=> " << i << std::endl;
    }

    std::cout << "=============> " << std::endl;
    auto vvcc = this->sort_data(myvector, 'L');
    for (auto& i : vvcc)
    {
        std::cout << "=> " << i << std::endl;
    }
}