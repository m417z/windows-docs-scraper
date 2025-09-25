# WerRegisterRuntimeExceptionModule function

## Description

Registers a custom runtime exception handler that is used to provide custom [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) for crashes.

## Parameters

### `pwszOutOfProcessCallbackDll` [in]

The name of the exception handler DLL to register.

### `pContext` [in, optional]

A pointer to arbitrary context information that is passed to the handler's callback functions.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|The number of registered runtime exception modules exceeds the limit. A process can register up to WER_MAX_REGISTERED_RUNTIME_EXCEPTION_MODULES handlers.|

## Remarks

The exception handler is an out-of-process DLL that the WER service loads when a crash or unhandled exception occurs. The DLL must implement and export the following functions:

- [OutOfProcessExceptionEventCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event)
- [OutOfProcessExceptionEventSignatureCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event_signature)
- [OutOfProcessExceptionEventDebuggerLaunchCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_debugger_launch)

(The DLL must also include the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) entry point.)

Using an exception handler is more secure and reliable for reporting crash information than the current, in-process event reporting feature. Also, the current generic event reporting feature is suited only for reporting non-fatal errors.

This function requires that the *pwszOutOfProcessCallbackDll* DLL be included in the [WER exception handler module list](https://learn.microsoft.com/windows/desktop/wer/wer-settings) in the registry. After registering an exception handler, if the process crashes or raises an unhandled exception, the WER service loads your exception handler and calls the [OutOfProcessExceptionEventCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event) callback function., which you use to state your claim on the crash and provide the event name and report parameters count. Note that if the process registers more than one exception handler, the service calls each handler until one of the handlers claims the crash. If no handlers claim the crash, WER defaults to native crash reporting.

If an exception handler claims the exception, the WER service calls the [OutOfProcessExceptionEventSignatureCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event_signature) callback function, which provides the reporting parameters that uniquely define the problem. Then, the WER service calls the [OutOfProcessExceptionEventDebuggerLaunchCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_debugger_launch) callback to determine whether to offer the user the option of launching a debugger or launching the debugger automatically. The handler can also specify a custom debugger launch string, which will override the default string (the default is the debugger specified in the AeDebug registry key).

After the handler has provided the event name, reporting parameters and debugger launch settings, the rest of the error reporting flow continues in the usual way.

You must call the [WerUnregisterRuntimeExceptionModule](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregisterruntimeexceptionmodule) function to remove the registration before your process exits. A process can register up to WER_MAX_REGISTERED_RUNTIME_EXCEPTION_MODULES handlers.

## See also

[Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)