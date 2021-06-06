#pragma once

#include <ChakraCore/ChakraCore.h>
#include "JavascriptRuntime.h"
#include "JavascriptMacros.h"

class JavascriptContext
{
private:
	JsContextRef m_Context;
	long m_ContextIdentifier;
public:
	static long g_Context;
public:
	JavascriptContext();
	void CreateContext(JavascriptRuntime& RT);
	long GetContextIdentifier();
	void SetActiveContext();
	~JavascriptContext();
};

