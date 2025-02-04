#ifndef TEST_SUB_DERIVED_1_H
#define TEST_SUB_DERIVED_1_H

#include "test_sub_base.hpp"

class TestSubDerived1 : public TestSubBase {
	std::string _name;
public:
	TestSubDerived1();
	std::string name() const override;
	void setName(const std::string&) override;
	const std::string& getName() const { return _name; }
};

#ifdef RECURSIVE
DECLARE_RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubDerived1);
#endif // 

#endif // TEST_SUB_DERIVED_1_H
