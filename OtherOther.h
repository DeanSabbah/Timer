#pragma once

#include "other.h"

class OtherOther : public Other {
public:
	OtherOther(std::string text);
	inline void foo() const { std::cout << "bar otherother!" << std::endl; }
	inline void bar() const { std::cout << text_ << " foobar otherother!" << std::endl; }
	inline void thing() const { std::cout << "thing otherother! " << thing_->get_text() <<std::endl; }

private:
	Other* thing_;
};