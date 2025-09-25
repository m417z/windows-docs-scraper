# WerUnregisterRuntimeExceptionModule function

## Description

Removes the registration of the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) exception handler.

## Parameters

### `pwszOutOfProcessCallbackDll` [in]

The name of the exception handler DLL whose registration you want to remove.

### `pContext` [in, optional]

A pointer to arbitrary context information that was passed to the callback.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**WER_E_NOT_FOUND**|The list of registered runtime exception handlers does not contain the specified exception handler.|

## Remarks

To register your runtime exception handler, call the [WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule) function.

## See also

[WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)