# PFN_WER_RUNTIME_EXCEPTION_EVENT callback function

## Description

[Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) calls this function to determine whether the exception handler is claiming the crash.

The **PFN_WER_RUNTIME_EXCEPTION_EVENT** type defines a pointer to this callback function. You must use "OutOfProcessExceptionEventCallback" as the name of the callback function.

## Parameters

### `pContext` [in]

A pointer to arbitrary context information that you specified when you called the [WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule) function to register the exception handler.

### `pExceptionInformation` [in]

A [WER_RUNTIME_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_runtime_exception_information) structure that contains the exception information. Use the information to determine whether you want to claim the crash.

### `pbOwnershipClaimed` [out]

Set to **TRUE** if the exception handler is claiming this crash; otherwise, **FALSE**. If you set this parameter to **FALSE**, do not set the rest of the out parameters.

### `pwszEventName` [out]

A caller-allocated buffer that you use to specify the event name used to identify this crash.

### `pchSize` [in, out]

The size, in characters, of the *pwszEventName* buffer. The buffer is limited to MAX_PATH characters. The size includes the null-terminating character.

### `pdwSignatureCount` [out]

The number of report parameters that you will provide. The valid range of values is one to 10. If you specify a value greater than 10, WER will ignore the value and collect only the first 10 parameters. If you specify zero, the reporting process will be indeterminate.

This value determines the number of times that WER calls your [OutOfProcessExceptionEventSignatureCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event_signature) function.

## Return value

Return **S_OK**, even if the exception handler is not claiming this crash. If you return other failure codes, WER reverts to its default crash reporting behavior if no other handlers are registered.

## Remarks

You must implement this function in your exception handler DLL.

## See also

[WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)