#ifndef PLAYERTRAIL_EXCEPTION_H
#define PLAYERTRAIL_EXCEPTION_H

#include <stdexcept>   // for exception, runtime_error
using std::string;

class InvalidPlayerName : public std::runtime_error
{
public:
    explicit InvalidPlayerName();
};

class DeckFileNotFound : public std::runtime_error
{
public:
    explicit DeckFileNotFound();
};

class DeckFileFormatError : public std::runtime_error
{
public:
    explicit DeckFileFormatError(int lineNumberInDeckfile);
};

class DeckFileInvalidSize : public std::runtime_error
{
public:
    explicit DeckFileInvalidSize();
};

#endif //PLAYERTRAIL_EXCEPTION_H
