# RaiseFailFastException function

## Description

Raises an exception that bypasses all exception handlers (frame or vector based). Raising this exception terminates the application and invokes Windows Error Reporting, if Windows Error Reporting is enabled.

## Parameters

### `pExceptionRecord` [in, optional]

A pointer to an [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure that contains the exception information. You must specify the **ExceptionAddress** and **ExceptionCode** members.

If this parameter is **NULL**, the function creates an exception record and sets the **ExceptionCode** member to STATUS_FAIL_FAST_EXCEPTION. The function will also set the **ExceptionAddress** member if the *dwFlags* parameter contains the FAIL_FAST_GENERATE_EXCEPTION_ADDRESS flag.

### `pContextRecord` [in, optional]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that contains the context information. If **NULL**, this function generates the context (however, the context will not exactly match the context of the caller).

### `dwFlags` [in]

You can specify zero or the following flag that control this function's behavior:

| Value | Meaning |
| --- | --- |
| **FAIL_FAST_GENERATE_EXCEPTION_ADDRESS**<br><br>0x1 | Causes **RaiseFailFastException** to set the **ExceptionAddress** of [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) to the return address of this function (the next instruction in the caller after the call to **RaiseFailFastException**). This function will set the exception address only if **ExceptionAddress** is not **NULL**. |

## Remarks

Typically, you call this function if your application is in a bad state and you want to terminate the application immediately and have a Windows Error Report created.

If the WER service is disabled or cannot be started or there is no debugger attached to the process, the process will be terminated.

This function raises a second chance exception. If JIT debugging is enabled, a debugger will attach to the process.

## See also

**Environment.FailFast**