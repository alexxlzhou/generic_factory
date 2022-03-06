#ifndef TEST_SUB_DERIVED_2_H
#define TEST_SUB_DERIVED_2_H

#include "test_sub_base.hpp"

class TestSubDerived2 : public TestSubBase {
	std::string _name;
public:
	TestSubDerived2();
	std::string name() const override;
	void setName(const std::string&) override;
	const std::string& getName() const { return _name; }
};

#ifdef RECURSIVE
DECLARE_RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubDerived2);
#endif // 

#endif // TEST_SUB_DERIVED_2_H
