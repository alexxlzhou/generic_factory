#include <iostream>
#include <vector>

#include "recursive_factory.hpp"
#include "test_base.hpp"
#include "test_sub_base.hpp"
#include "test_sub_derived_1.h"
#include "test_sub_derived_2.h"

//We can put all the recursive registation here or in the head files
//RECURSIVE_REGISTER_ABSTRACT_FACTORY(TestSubBase, TestSubBase, "TestSubBase");
//RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubDerived1, "TestSubDerived1");
//RECURSIVE_REGISTER_FACTORY(TestSubBase, TestSubDerived2, "TestSubDerived2");

class TestSubDerived3 : public TestSubDerived1 {
public:
	TestSubDerived3() : TestSubDerived1() { setName("SubDer3"); };

	std::string name() const {
		return "A TestSubDerived3 named " + getName();
	}
};
RECURSIVE_REGISTER_FACTORY(TestSubDerived1, TestSubDerived3, "TestSubDerived3");


int main()
{
	const auto& ch0 = GenericFactory<TestSubBase>::getChildren();
	std::cout << "recursively registered TestSubBase factory:\n";
	for (const auto& it : ch0) {
		std::cout << it.first << std::endl;
		std::cout << "\tCreated " << it.second()->name() << std::endl;
	}
	std::cout << "\n";

	const auto& ch1 = GenericFactory<TestSubDerived1>::getChildren();
	std::cout << "recursively registered TestSubDerived1 factory:\n";
	for (const auto& it : ch1) {
		std::cout << it.first << std::endl;
		std::cout << "\tCreated " << it.second()->name() << std::endl;
	}
	std::cout << "\n";

	const auto& ch2 = GenericFactory<TestSubDerived2>::getChildren();
	std::cout << "recursively registered TestSubDerived2 factory:\n";
	for (const auto& it : ch2) {
		std::cout << it.first << std::endl;
		std::cout << "\tCreated " << it.second()->name() << std::endl;
	}
	std::cout << "\n";

}
