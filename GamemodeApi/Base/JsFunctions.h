#pragma once

#include <iostream>
#include <string>
#include <sampgdk/sampgdk.h>
#include <ChakraCore/ChakraCore.h>


class JsFunctions
{
public:
	static JsValueRef CALLBACK SAMPAPI_Print(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState);
	static JsValueRef CALLBACK SAMPAPI_GetMaxPlayers(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState);
	static JsValueRef CALLBACK SAMPAPI_IsPlayerNpc(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState);
	static JsValueRef CALLBACK SAMPAPI_GetPlayerPos(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState);
	static JsValueRef CALLBACK SAMPAPI_IsPlayerConnected(JsValueRef callee, bool isConstructCall, JsValueRef* arguments, unsigned short argumentCount, void* callbackState);
};

