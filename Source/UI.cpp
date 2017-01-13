#include <iostream>
#include "../Header/UI.h"

CommandType getCommand()
{
    char str[10] = {'\0'};

    std::cin >> str;

    if(strcmp(str, "add") == 0)
        return ADD;
    if(strcmp(str, "remove") == 0)
        return REMOVE;
    if(strcmp(str, "removeall") == 0)
        return REMOVE_ALL;
    if(strcmp(str, "search") == 0)
        return SEARCH;

    return ERROR;
}
