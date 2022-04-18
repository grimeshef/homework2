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
    for (int current_ip_pose = 0; current_ip_pose < _ip_pool.size();
         current_ip_pose++) {
        for (int current_ip_posee = current_ip_pose + 1;
             current_ip_posee < _ip_pool.size();
             current_ip_posee++) {
            auto i = std::stoi((_ip_pool[current_ip_pose][0]));
            auto j = std::stoi(_ip_pool[current_ip_posee][0]);
            if (j > i) {
                _ip_pool[current_ip_pose].swap(_ip_pool[current_ip_posee]);
            }
        }
    }
    return _ip_pool;
}
