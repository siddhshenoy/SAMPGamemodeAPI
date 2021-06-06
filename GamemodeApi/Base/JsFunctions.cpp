#include "JsFunctions.h"


JsValueRef CALLBACK JsFunctions::SAMPAPI_Print(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState)
{
	for (unsigned int index = 1; index < argumentCount; index++)
	{
		if (index > 1)
		{
			//sampgdk::logprintf(" ");
			std::wcout << L" ";
		}

		JsValueRef stringValue;
		JsConvertValueToString(arguments[index], &stringValue);

		const wchar_t* string;
		size_t length;
		JsStringToPointer(stringValue, &string, &length);
		std::wcout << string;
		//sampgdk::logprintf("%s", string);
	}
	std::wcout << L"\r\n";
	return JS_INVALID_REFERENCE;
}
JsValueRef CALLBACK JsFunctions::SAMPAPI_GetMaxPlayers(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState)
{
	JsValueRef Result;
	JsIntToNumber(MAX_PLAYERS, &Result);
	return Result;
}
JsValueRef CALLBACK JsFunctions::SAMPAPI_IsPlayerNpc(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState)
{
	if (argumentCount > 1) {
		JsValueRef NumberRef;
		JsValueRef Result;
		int id;
		JsConvertValueToNumber(arguments[1], &NumberRef);
		JsNumberToInt(NumberRef, &id);
		bool result = IsPlayerNPC(id);
		JsBoolToBoolean(result, &Result);
		return Result;
	}
}
JsValueRef CALLBACK JsFunctions::SAMPAPI_GetPlayerPos(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState)
{
	if (argumentCount == 2)
	{

		//JsValueRef 
		int playerid;
		float p[3];
		JsNumberToInt(arguments[1], &playerid);
		GetPlayerPos(playerid, &p[0], &p[1], &p[2]);
		JsValueRef Array;
		
		JsCreateArray(3, &Array);
		for (int i = 0; i < 3; i++) {
			JsValueRef index;
			JsValueRef pos;
			JsIntToNumber(i, &index);
			JsDoubleToNumber((double)p[i], &pos);
			JsSetIndexedProperty(Array, index, pos);
		}
		//JsSetIndexedProperty(Array,)
		return Array;
	}
	return JS_INVALID_REFERENCE;
}

JsValueRef CALLBACK JsFunctions::SAMPAPI_IsPlayerConnected(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState)
{
	if (argumentCount == 2)
	{
		int playerid;
		JsValueRef BoolResult;
		JsNumberToInt(arguments[1], &playerid);
		bool result = IsPlayerConnected(playerid);
		JsBoolToBoolean(result, &BoolResult);
		return BoolResult;
	}
	return JS_INVALID_REFERENCE;
}