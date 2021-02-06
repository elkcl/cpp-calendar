//
// Created by elk on 05.02.2021.
//

#include <locale>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <date/date.h>
#include <fmt/core.h>
#include <fmt/chrono.h>

using namespace date;
using namespace date::literals;
using namespace std::chrono;
using namespace std::literals;

const int WEEK_COUNT = 6;
const int MAX_LEFT_COLUMN_LENGTH = 5;

int main() {
    std::locale::global(std::locale("ru_RU.utf8"));

    auto today = floor<days>(system_clock::now());
    auto currentYear = year_month_day{today}.year();
    auto currentDay = (sys_days) (1_d/January/currentYear);
    auto y = fmt::format("{:%Y}", fmt::localtime(currentDay));
    fmt::print("{:-^136}\n", y);
    fmt::print("{0:{1}}", "", MAX_LEFT_COLUMN_LENGTH);
    auto wd = (sys_days) year_month_day{Monday[0]/January/currentYear};
    for (int i = 0; i < 7*WEEK_COUNT; ++i) {
        fmt::print("{:%a} ", fmt::localtime(wd));
        wd += days{1};
    }
    std::cout << std::endl;

    while (year_month_day{currentDay}.year() == currentYear) {
        auto m = fmt::format("{:%b}", fmt::localtime(currentDay));
        fmt::print("{0:<{1}}|", m, MAX_LEFT_COLUMN_LENGTH-1);
        auto currentWeekday = Monday;
        auto currentMonth = year_month_day{currentDay}.month();
        while (year_month_day{currentDay}.month() == currentMonth) {
            std::string s;
            if (year_month_weekday{currentDay}.weekday() == currentWeekday) {
                s = fmt::format("{:%e}", fmt::localtime(currentDay));
                currentDay += days{1};
            }
            fmt::print("{:>2} ", s);
            ++currentWeekday;
        }
        std::cout << std::endl;
    }
}
