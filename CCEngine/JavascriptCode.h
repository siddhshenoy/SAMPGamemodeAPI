#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "JavascriptRuntime.h"
#include "JavascriptContext.h"

class JavascriptCode
{
private:
	std::wstring m_CodeFilePath;
	std::wstring m_CodeFile;
	JavascriptContext m_Context;
	std::unordered_map<std::wstring, JsValueRef> m_HostObjects;
private:
	std::wstring LoadCodeFile(const std::wstring& CodeFilePath);
public:
	JavascriptCode();
	void SetContext(JavascriptContext context);
	void SetCodeFile(const std::wstring& CodeFilePath);
	void CreateHostObject(std::wstring ObjectName);
	void AttachHostObjectFunction(std::wstring HostObject, std::wstring FunctionName, JsNativeFunction Function, void* CallbackState);
	JsValueRef CallJSFunction(const char* FunctionName, JsValueRef args[]);
	JsValueRef Run();
	~JavascriptCode();
public:
	static JsValueRef* GetDefaultArgs()
	{
		JsValueRef* jsargs = new JsValueRef[1];
		JsValueRef undefined;
		JsGetUndefinedValue(&undefined);
		jsargs[0] = undefined;
		return jsargs;
	}
};

