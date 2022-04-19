#include "ip_filter.h"

#include <utility>


// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


std::vector<std::vector<std::string>> filter(const std::vector<std::vector<std::string>>& ip_pool)
{
    auto _ip_pool = ip_pool;
    for (int current_ip = 0; current_ip < _ip_pool.size();
         current_ip++) {
        for (int other_ip = current_ip + 1;
             other_ip < _ip_pool.size();
             other_ip++) {
            auto current_ip_first_part = std::stoi((_ip_pool[current_ip][0]));
            auto other_ip_first_part = std::stoi(_ip_pool[other_ip][0]);
            if (other_ip_first_part == current_ip_first_part) {
                auto current_ip_second_part = std::stoi((_ip_pool[current_ip][1]));
                auto other_ip_second_part = std::stoi(_ip_pool[other_ip][1]);
                if (other_ip_second_part == current_ip_second_part) {
                    auto current_ip_third_part = std::stoi((_ip_pool[current_ip][2]));
                    auto other_ip_third_part = std::stoi(_ip_pool[other_ip][2]);
                    if (other_ip_third_part == current_ip_third_part) {
                        auto current_ip_forth_part = std::stoi((_ip_pool[current_ip][3]));
                        auto other_ip_forth_part = std::stoi(_ip_pool[other_ip][3]);
                        if (other_ip_forth_part > current_ip_forth_part) {
                            _ip_pool[current_ip].swap(_ip_pool[other_ip]);
                        }
                    }
                    else if (other_ip_third_part > current_ip_third_part) {
                        _ip_pool[current_ip].swap(_ip_pool[other_ip]);
                    }
                }
                else if (other_ip_second_part > current_ip_second_part){
                    _ip_pool[current_ip].swap(_ip_pool[other_ip]);
                }
            }
            else if (other_ip_first_part > current_ip_first_part) {
                _ip_pool[current_ip].swap(_ip_pool[other_ip]);
            }
        }
    }
    return _ip_pool;
}
