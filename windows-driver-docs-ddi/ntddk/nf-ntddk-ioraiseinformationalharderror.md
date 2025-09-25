# IoRaiseInformationalHardError function

## Description

The **IoRaiseInformationalHardError** routine sends a dialog box to the user, warning about a device I/O error that indicates why a user I/O request failed.

## Parameters

### `ErrorStatus` [in]

The error status code (IO_ERR_*XXX*).

### `String` [in, optional]

A pointer to a Unicode string, which provides additional information about the error. Some NT status codes require a string parameter, such as a file or directory name. If the specified *ErrorStatus* value does not require a string parameter, set *String* to **NULL**.

### `Thread` [in, optional]

A pointer to the thread whose IRP was failed due to the error specified by the *ErrorStatus* parameter.

## Return value

**IoRaiseInformationalHardError** returns **TRUE** if the dialog box was successfully queued. This routine returns **FALSE** if dialog boxes are disabled for *Thread*, a pool allocation failed, too many dialog boxes are already queued, or an equivalent dialog box is already pending a user response (such as waiting for the user to press RETURN).

## Remarks

**IoRaiseInformationalHardError** takes a system-defined NT error value as a parameter. Driver writers can use the event log APIs to communicate driver-defined event strings to the user.

**IoRaiseInformationalHardError** behaves as follows:

* If the caller-supplied *ErrorStatus* value is not defined in the Ntstatus.h header file, the dialog box always shows the text "Unknown Hard Error", regardless of the *String* parameter value.
* If the caller-supplied *ErrorStatus* value is defined in the Ntstatus.h header file, the dialog box shows the text in the corresponding MessageText string in Ntstatus.h, regardless of the *String* parameter value.
* If the *Thread* parameter specifies a thread that is running in the context of an application, the text shown in the dialog box is "ApplicationName.exe - System Error".
* If the *Thread* parameter is NULL or if it specifies a thread that is running in an arbitrary system context, the text shown in the dialog box is "System Process - System Error". Additionally, if the *ErrorStatus* value is defined in Ntstatus.h, the corresponding MessageText string is written to the event log.

If a previous call to the [IoSetThreadHardErrorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetthreadharderrormode) routine disabled hard errors for the specified thread, **IoRaiseInformationalHardError** returns **FALSE**.

Starting with Windows Vista, if the routine is called from a thread in session 0 (that is, from any system thread), no dialog box appears when the routine succeeds and returns **TRUE**.

## See also

[IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice)

[IoSetThreadHardErrorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetthreadharderrormode)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)