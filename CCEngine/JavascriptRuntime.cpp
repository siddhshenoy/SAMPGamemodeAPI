#include "JavascriptRuntime.h"


JavascriptRuntime::JavascriptRuntime()
{
	m_RuntimeHandle = NULL;
}
void JavascriptRuntime::CreateRuntime()
{
	JsErrorCode error = JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &m_RuntimeHandle);
	if (error != JsNoError)
	{
		printf("[ChakraCore Error]: Could not create ChakraCore runtime!\r\n");
		exit(1);
	}
}
JsValueRef JavascriptRuntime::GetGlobalObject()
{
	JsValueRef globalObject;
	JsErrorCode error = JsGetGlobalObject(&globalObject);
	if (error != JsNoError)
	{
		printf("[ChakraCore Error]: Could not get the global object..");
		exit(1);
	}
	return globalObject;
}
JsRuntimeHandle JavascriptRuntime::GetRuntime()
{
	return m_RuntimeHandle;
}
JavascriptRuntime::~JavascriptRuntime()
{
	if (m_RuntimeHandle != NULL)
	{
		JsDisposeRuntime(m_RuntimeHandle);
	}
}
