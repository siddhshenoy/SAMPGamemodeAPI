#include "JavascriptCode.h"


JavascriptCode::JavascriptCode()
{

}
std::wstring JavascriptCode::LoadCodeFile(const std::wstring& CodeFilePath)
{
	FILE* file;
	if (_wfopen_s(&file, CodeFilePath.c_str(), L"rb"))
	{
		fwprintf(stderr, L"chakrahost: unable to open file: %s.\n", CodeFilePath.c_str());
		return std::wstring();
	}

	unsigned int current = ftell(file);
	fseek(file, 0, SEEK_END);
	unsigned int end = ftell(file);
	fseek(file, current, SEEK_SET);
	unsigned int lengthBytes = end - current;
	char* rawBytes = (char*)calloc(lengthBytes + 1, sizeof(char));

	if (rawBytes == nullptr)
	{
		fwprintf(stderr, L"chakrahost: fatal error.\n");
		return std::wstring();
	}

	fread((void*)rawBytes, sizeof(char), lengthBytes, file);

	wchar_t* contents = (wchar_t*)calloc(lengthBytes + 1, sizeof(wchar_t));
	if (contents == nullptr)
	{
		free(rawBytes);
		fwprintf(stderr, L"chakrahost: fatal error.\n");
		return std::wstring();
	}

	if (MultiByteToWideChar(CP_UTF8, 0, rawBytes, lengthBytes + 1, contents, lengthBytes + 1) == 0)
	{
		free(rawBytes);
		free(contents);
		fwprintf(stderr, L"chakrahost: fatal error.\n");
		return std::wstring();
	}

	std::wstring result = contents;
	free(rawBytes);
	free(contents);
	return result;
}
void JavascriptCode::SetContext(JavascriptContext context)
{
	context.SetActiveContext();
}
void JavascriptCode::SetCodeFile(const std::wstring& CodeFilePath)
{
	m_CodeFilePath = CodeFilePath;
	m_CodeFile = LoadCodeFile(CodeFilePath);

}
JsValueRef JavascriptCode::Run()
{
	JsValueRef Result;
	JsErrorCode Error = JsRunScript(m_CodeFile.c_str(), m_Context.GetContextIdentifier(), m_CodeFilePath.c_str(), &Result);
	return Result;
}
void JavascriptCode::CreateHostObject(std::wstring ObjectName)
{
	if (m_HostObjects.find(ObjectName) == m_HostObjects.end())
	{
		JsValueRef GlobalObject;
		JsValueRef NewObject;
		JsPropertyIdRef PropertyID;
		JsErrorCode err;
		err = JsCreateObject(&NewObject);
		if (err != JsNoError)
		{
			std::cout << "ChakraCore Error: Failed to create object (" << err << ")" << std::endl;
			return;
		}
		GlobalObject = JavascriptRuntime::GetGlobalObject();
		err = JsGetPropertyIdFromName(ObjectName.c_str(), &PropertyID);
		if (err != JsNoError)
		{
			std::cout << "ChakraCore Error: Failed to get the property id (" << err << ")" << std::endl;
			return;
		}
		err = JsSetProperty(GlobalObject, PropertyID, NewObject, true);
		if (err != JsNoError)
		{
			std::cout << "ChakraCore Error: Failed to set the property id (" << err << ")" << std::endl;
			return;
		}
		m_HostObjects.insert(std::pair<std::wstring, JsValueRef>(ObjectName, NewObject));
	}
}
void JavascriptCode::AttachHostObjectFunction(std::wstring HostObject, std::wstring FunctionName, JsNativeFunction Function, void* CallbackState)
{
	if (m_HostObjects.find(HostObject) != m_HostObjects.end())
	{
		JsValueRef FunctionRef;
		JsPropertyIdRef FunctionProperty;
		JsGetPropertyIdFromName(FunctionName.c_str(), &FunctionProperty);
		JsCreateFunction(Function, CallbackState, &FunctionRef);
		JsSetProperty(m_HostObjects[HostObject], FunctionProperty, FunctionRef, true);
		//return JsNoError;
	}
}
JsValueRef JavascriptCode::CallJSFunction(const char* FunctionName, JsValueRef args[])
{
	JsValueRef func, funcPropId, res;
	JsCreatePropertyId(FunctionName, strlen(FunctionName), &funcPropId);
	JsGetProperty(JavascriptRuntime::GetGlobalObject(), funcPropId, &func);
	JsCallFunction(func, args, 1, &res);
	return NULL;
}
JavascriptCode::~JavascriptCode()
{

}