#pragma once
#include "../../../java.h"

class C_Entity
{
public:
	static jclass getClass();
	static jobject getInstance();

	static void setSprinting(bool state);
};