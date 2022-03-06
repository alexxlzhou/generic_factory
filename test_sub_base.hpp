#ifndef TEST_SUB_BASE_HPP
#define TEST_SUB_BASE_HPP

#include <string>

#ifdef RECURSIVE
#include "recursive_factory.hpp"
#endif 


class TestSubBase {
public:
	virtual std::string name() const = 0;
	virtual void setName(const std::string&) = 0;
	virtual ~TestSubBase() = default;
};

#ifdef RECURSIVE
DECLARE_RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubBase);
#endif // 

#endif // TEST_SUB_BASE_HPP
