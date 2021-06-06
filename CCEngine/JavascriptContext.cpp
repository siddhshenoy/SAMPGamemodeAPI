#include "JavascriptContext.h"

long JavascriptContext::g_Context;

JavascriptContext::JavascriptContext()
{
	m_Context = NULL;
}
void JavascriptContext::CreateContext(JavascriptRuntime& RT)
{

	JsErrorCode error = JsCreateContext(RT.GetRuntime(), &m_Context);
	if (error != JsNoError)
	{
		JsPrintError("Could not create ChakraCore context!");
		exit(1);
	}
	m_ContextIdentifier = JavascriptContext::g_Context++;
}
long JavascriptContext::GetContextIdentifier()
{
	return m_ContextIdentifier;
}
void JavascriptContext::SetActiveContext()
{
	JsErrorCode error = JsSetCurrentContext(m_Context);
	if (error != JsNoError)
	{
		JsPrintError("Could not set active context!");
		exit(1);
	}
}
JavascriptContext::~JavascriptContext()
{

}