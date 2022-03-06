#include "generic_factory.hpp"
#ifdef RECURSIVE
#include "recursive_factory.hpp"
#endif
#include "test_sub_derived_2.h"

TestSubDerived2::TestSubDerived2() : _name("SubDer2") {

}

std::string TestSubDerived2::name() const {
	return "A SubTestDerived2 named " + _name;
}

void TestSubDerived2::setName(const std::string& name) {
	_name = name;
}


#ifdef RECURSIVE
DEFINE_RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubDerived2, "TestSubDerived2");
#else
REGISTER_CHILD_INTO_FACTORY(TestSubBase, TestSubDerived2, "TestSubDerived2");
#endif // RECURSIVE
