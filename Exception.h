#ifndef PLAYERTRAIL_EXCEPTION_H
#define PLAYERTRAIL_EXCEPTION_H

#include <stdexcept>   // for exception

class InvalidPlayerName : public std::exception
{
public:
    explicit InvalidPlayerName() = default;
    const char* what() const noexcept override
    {
            return "Invalid name";
    }
};

class DeckFileNotFound : public std::exception
{
public:
    explicit DeckFileNotFound() = default;
    const char* what() const noexcept override
    {
            return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
public:
    explicit DeckFileFormatError(int lineNumberInDeckfile) : m_lineNumberInDeckfile(lineNumberInDeckfile){ };
    const char* what() const noexcept override{
            return "File format error in line "+ m_lineNumberInDeckfile;
    }
private:
    int m_lineNumberInDeckfile;
};

class DeckFileInvalidSize : public std::exception
{
public:
    explicit DeckFileInvalidSize() = default;
    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};

#endif //PLAYERTRAIL_EXCEPTION_H
