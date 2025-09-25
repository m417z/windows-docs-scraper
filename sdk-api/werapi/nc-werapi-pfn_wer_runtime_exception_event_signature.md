# PFN_WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE callback function

## Description

[Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) calls this function to get the report parameters that uniquely describe the problem.

The **PFN_WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE** type defines a pointer to this callback function. You must use "OutOfProcessExceptionEventSignatureCallback" as the name of the callback function.

## Parameters

### `pContext` [in]

A pointer to arbitrary context information that you specified when you called the [WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule) function to register the exception handler.

### `pExceptionInformation` [in]

A [WER_RUNTIME_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_runtime_exception_information) structure that contains the exception information.

### `dwIndex` [in]

The index of the report parameter. Valid values are 0 to 9. The first call to this function must set the index to 0, and each successive call must increment the index value sequentially.

### `pwszName` [out]

A caller-allocated buffer that you use to specify the parameter name.

### `pchName` [in, out]

The size, in characters, of the *pwszName* buffer. The size includes the null-terminating character.

### `pwszValue` [out]

A caller-allocated buffer that you use to specify the parameter value.

### `pchValue` [in, out]

The size, in characters, of the *pwszValue* buffer. The size includes the null-terminating character.

## Return value

Return **S_OK** on success. If you return other failure codes, WER reverts to its default crash reporting behavior.

## Remarks

You must implement this function in your exception handler DLL.

To generate error reports for application-specific issues, the application must create a short description of the problem using a few basic pieces of information called report parameters. Report parameters include information such as the application name, application version, module name, module version, and error code. The combination of these report parameters describes a unique problem.

WER calls this callback function only if you set the *pbOwnershipClaimed* parameter of your [OutOfProcessExceptionEventCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event) callback function to **TRUE**. The *pdwSignatureCount* parameter of **OutOfProcessExceptionEventCallback** determines the number of times that WER will call this callback function.

## See also

[WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)