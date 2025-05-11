#include "OtherOther.h"

OtherOther::OtherOther(std::string text) : Other(text) {
	thing_ = new Other("More Scope!");
}