#ifndef RECURSIVE_FACTORY_HPP
#define RECURSIVE_FACTORY_HPP

// created by alexxlzhou

#include <type_traits>
#include <iostream>
#include "generic_factory.hpp"

template<typename ClassName, typename... Args>
GenericFactory<ClassName, Args...>& getGenericFactory() {
	return GenericFactory<ClassName, Args...>::getGenericFactory();
}

// CHILD_NAME not used in declaration, removing it is an option
#define DECLARE_RECURSIVE_REGISTER_FACTORY(INTERFACE_TYPENAME, CHILD_TYPENAME, ...) \
namespace GenericFactoryInternals { \
	inline bool recursiveRegisterChild(GenericFactory<CHILD_TYPENAME, ##__VA_ARGS__>& factory, const std::string & name, std::function<std::unique_ptr<CHILD_TYPENAME>(##__VA_ARGS__)> maker) \
	{ \
		if(!factory.registerChild(name, maker)) {\
			std::cout << "can not register " << name << " to class " << #CHILD_TYPENAME << std::endl; return false;\
		}\
		if (!std::is_same<INTERFACE_TYPENAME, CHILD_TYPENAME>::value) {\
			recursiveRegisterChild(getGenericFactory<INTERFACE_TYPENAME, ##__VA_ARGS__>(), name, maker);\
		}\
		return true;\
	}\
} \


#define DEFINE_RECURSIVE_REGISTER_FACTORY(INTERFACE_TYPENAME, CHILD_TYPENAME, CHILD_NAME, ...) \
namespace GenericFactoryInternals { \
	bool CHILD_TYPENAME##_Recursive_Registered = recursiveRegisterChild(getGenericFactory<CHILD_TYPENAME, ##__VA_ARGS__>(), CHILD_NAME, \
										[]() {return std::make_unique<CHILD_TYPENAME>(##__VA_ARGS__);} );\
} \

// CHILD_NAME not used in declaration, removing it is an option
#define RECURSIVE_REGISTER_ABSTRACT_FACTORY(INTERFACE_TYPENAME, CHILD_TYPENAME, ...) \
namespace GenericFactoryInternals { \
	inline bool recursiveRegisterChild(GenericFactory<CHILD_TYPENAME, ##__VA_ARGS__>& factory, const std::string & name, std::function<std::unique_ptr<CHILD_TYPENAME>(##__VA_ARGS__)> maker) \
	{ \
		if(!factory.registerChild(name, maker)) {\
			std::cout << "can not register " << name << " to class " << #CHILD_TYPENAME << std::endl; return false;\
		}\
		if (!std::is_same<INTERFACE_TYPENAME, CHILD_TYPENAME>::value) {\
			recursiveRegisterChild(getGenericFactory<INTERFACE_TYPENAME, ##__VA_ARGS__>(), name, maker);\
		}\
		return true;\
	}\
} \

#define RECURSIVE_REGISTER_FACTORY(INTERFACE_TYPENAME, CHILD_TYPENAME, CHILD_NAME, ...) \
namespace GenericFactoryInternals { \
	inline bool recursiveRegisterChild(GenericFactory<CHILD_TYPENAME, ##__VA_ARGS__>& factory, const std::string & name, std::function<std::unique_ptr<CHILD_TYPENAME>(##__VA_ARGS__)> maker) \
	{ \
		if(!factory.registerChild(name, maker)) {\
			std::cout << "can not register " << name << " to class " << #CHILD_TYPENAME << std::endl; return false;\
		}\
		if (!std::is_same<INTERFACE_TYPENAME, CHILD_TYPENAME>::value) {\
			recursiveRegisterChild(getGenericFactory<INTERFACE_TYPENAME, ##__VA_ARGS__>(), name, maker);\
		}\
		return true;\
	}\
	const bool CHILD_TYPENAME##_Recursive_Registered = recursiveRegisterChild(getGenericFactory<CHILD_TYPENAME, ##__VA_ARGS__>(), CHILD_NAME, \
										[]() {return std::make_unique<CHILD_TYPENAME>(##__VA_ARGS__);} );\
} \


#endif 