#pragma once

#include <stdio.h>
#include <ChakraCore/ChakraCore.h>

class JavascriptRuntime
{
private:
	JsRuntimeHandle m_RuntimeHandle;
public:
	JavascriptRuntime();
	void CreateRuntime();
	JsRuntimeHandle GetRuntime();
	static JsValueRef GetGlobalObject();
	~JavascriptRuntime();
};

