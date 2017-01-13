#ifndef UIDef
#define UIDef

enum CommandType
{
    ADD,
    REMOVE,
    REMOVE_ALL,
    SEARCH,
    ERROR
};

CommandType getCommand();

#endif
