#ifndef COMPUTE_H
#define COMPUTE_H
#include "Data_manager.h"
#include "Calendar.h"

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

/**
 * @brief "Your comment here"
 *
 */
class Compute
{
private:

public:
/**
 * @brief Construct a new Compute object
 *
 */
    Compute();
    template <typename T>
    /**
     * @brief "your comment here"
     *
     * @param a "your comment here"
     * @param b "your comment here"
     * @return true "your comment here"
     * @return false "your comment here"
     */
    bool operator()(T const &a, T const &b) const;

    /**
     * @brief Get the weeknumber data object
     *
     * @param obj "your comment here"
     * @param weeknummer "your comment here"
     * @return float "your comment here"
     */
    float get_weeknumber_data(Datamanager &obj, const int weeknummer);

    /**
     * @brief Get the weekindex object
     *
     * @param start_point 
     * @param Week 
     * @return std::vector<int> 
     */
    std::vector<int> get_weekindex(const int start_point, const uint8_t Week);

    /**
     * @brief 
     *
     * @param starting_point 
     * @param my_month 
     * @param my_week_size 
     * @return std::vector<int> 
     */
    std::vector<int> test_test(int starting_point, Month my_month, const uint8_t my_week_size);

    /**
     * @brief Get the monthnumber data object
     *
     * @param obj 
     * @param starting_point 
     * @param my_week_size 
     * @return float 
     */
    float get_monthnumber_data(Datamanager &obj, int starting_point, const uint8_t my_week_size);

    /**
     * @brief Get the Q data object
     * 
     * @param obj 
     * @param starting_point 
     * @return float 
     */
    float get_Q_data(Datamanager &obj, int starting_point);

    /**
     * @brief Get the year data object
     * 
     * @param obj 
     * @return float 
     */
    float get_year_data(Datamanager &obj);

    template <typename T>
    /**
     * @brief 
     * 
     * @param input_data 
     * @param L_or_H 
     * @return std::vector<T> 
     */
    std::vector<T> sort_data(std::vector<T> input_data, const char L_or_H );

    /**
     * @brief 
     * 
     * @param obj 
     */
    void test_me_(Datamanager &obj);
};

#endif // !COMPUTE_H
