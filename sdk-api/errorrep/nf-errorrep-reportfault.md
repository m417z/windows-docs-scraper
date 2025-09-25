# ReportFault function

## Description

Enables an application that performs its own exception handling to report faults to Microsoft. Although you can use this function to report application crashes, we recommend that applications not handle fatal errors directly but instead rely on the crash reporting capability provided by the operating system.

## Parameters

### `pep` [in]

 A pointer to an
[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) structure.

### `dwOpt` [in]

This parameter is reserved for system use and should be set to zero.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **frrvErr** | The function failed but the error reporting client was launched. |
| **frrvErrNoDW** | The error reporting client was unable to launch. The system will perform its default actions, such as displaying the standard exception dialog box and launching the debugger. |
| **frrvErrTimeout** | The function timed out. |
| **frrvLaunchDebugger** | The function succeeded and the user launched the debugger. |
| **frrvOk** | The function succeeded. |
| **frrvOkHeadless** | The function succeeded and the error reporting client was launched in silent reporting mode (no UI is used). |
| **frrvOkManifest** | The function succeeded and the error reporting client was launched in manifest reporting mode. |
| **frrvOkQueued** | The function succeeded and the fault report was queued for later reporting. |

These return values indicate whether the reporting application was successfully launched. A successful return value does not necessarily indicate that the fault was successfully reported.

## Remarks

The exact result of calling this function depends on how the user or system administrator has configured the error reporting system.

## See also

[AddERExcludedApplication](https://learn.microsoft.com/windows/desktop/api/errorrep/nf-errorrep-adderexcludedapplicationa)

[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers)

[WER Functions](https://learn.microsoft.com/windows/desktop/wer/wer-functions)

[Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer/windows-error-reporting)