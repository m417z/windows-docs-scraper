# PFN_WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH callback function

## Description

[Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) calls this function to let you customize the debugger launch options and launch string.

The **PFN_WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH** type defines a pointer to this callback function. You must use "OutOfProcessExceptionEventDebuggerLaunchCallback" as the name of the callback function.

## Parameters

### `pContext` [in]

A pointer to arbitrary context information that you specified when you called the [WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule) function to register the exception handler.

### `pExceptionInformation` [in]

A [WER_RUNTIME_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_runtime_exception_information) structure that contains the exception information.

### `pbIsCustomDebugger` [out]

Set to **TRUE** if the custom debugger specified in the *pwszDebuggerLaunch* parameter is used to debug the crash; otherwise, set to **FALSE** to use the default debugger. If you set this parameter to **FALSE**, do not set the *pwszDebuggerLaunch* parameter.

### `pwszDebuggerLaunch` [out]

A caller-allocated buffer that you use to specify the debugger launch string used to launch the debugger. The launch string must include the full path to the debugger and any arguments. If an argument includes multiple words, use quotes to delimit the argument. The debugger string should adhere to the same protocol as the default AeDebug debugger string (see [Configuring Automatic Debugging](https://learn.microsoft.com/windows/desktop/Debug/configuring-automatic-debugging)). The string must contain two formatting specifiers: %ld for the crashing process ID, and %ld for the handle to an event object to be signaled after the custom debugger has attached to the target (for a description of these specifiers, see [Enabling Postmortem Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/enabling-postmortem-debugging)). However, custom debuggers can choose to ignore these parameters.

### `pchDebuggerLaunch` [in, out]

The size, in characters, of the *pwszDebuggerLaunch* buffer.

### `pbIsDebuggerAutolaunch` [out]

Set to **TRUE** if you want WER to silently launch the debugger; otherwise, **FALSE** if you want WER to ask the user before launching the debugger.

## Return value

Return **S_OK**, even if no customer debugger is to be used. If you return other failure codes, WER reverts to its default crash reporting behavior.

## Remarks

You must implement this function in your exception handler DLL.

WER uses this function to determine which debugger to launch and whether to launch the debugger automatically or ask the user before launching the debugger. Specifying a custom debugger will override the default launch string (the AeDebug registry key contains the default launch string).

WER calls this callback function only if you set the *pbOwnershipClaimed* parameter of your [OutOfProcessExceptionEventCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event) callback function to **TRUE**.

## See also

[WerRegisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterruntimeexceptionmodule), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)