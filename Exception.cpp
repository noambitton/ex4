#include "Exception.h"
#include <iostream>
using std::cout;
using std::string;
using std::ostream;
using std::endl;

InvalidPlayerName::InvalidPlayerName() : runtime_error("invalid name"){}

DeckFileNotFound::DeckFileNotFound() : runtime_error("Deck File Error: File not found") {}

DeckFileFormatError::DeckFileFormatError(int lineNumberInDeckfile) :runtime_error("Deck File Error: File not found"){}

DeckFileInvalidSize::DeckFileInvalidSize() : runtime_error("Deck File Error: Deck size is invalid"){}
