#include "search.h"

int main()
{
    std::string file_to_find;
    std::cout << "Enter file name: ";
    std::cin >> file_to_find;
    std::filesystem::path home{"/"};
    std::thread th(search,home,file_to_find);
    th.join();
    return 0;
}