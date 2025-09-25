# SetThreadErrorMode function

## Description

Controls whether the system will handle the specified types of serious errors or whether the calling thread will handle them.

## Parameters

### `dwNewMode` [in]

The thread error mode. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Use the system default, which is to display all error dialog boxes. |
| **SEM_FAILCRITICALERRORS**<br><br>0x0001 | The system does not display the critical-error-handler message box. Instead, the system sends the error to the calling thread.<br><br>Best practice is that all applications call the process-wide [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function with a parameter of **SEM_FAILCRITICALERRORS** at startup. This is to prevent error mode dialogs from hanging the application. |
| **SEM_NOGPFAULTERRORBOX**<br><br>0x0002 | The system does not display the Windows Error Reporting dialog. |
| **SEM_NOOPENFILEERRORBOX**<br><br>0x8000 | The [OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function does not display a message box when it fails to find a file. Instead, the error is returned to the caller. This error mode overrides the **OF_PROMPT** flag. |

### `lpOldMode` [out]

If the function succeeds, this parameter is set to the thread's previous error mode. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each process has an associated error mode that indicates to the system how the application is going to respond to serious errors. A thread inherits the error mode of the process in which it is running. To retrieve the process error mode, use the [GetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-geterrormode) function. To retrieve the error mode of the calling thread, use the [GetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getthreaderrormode) function.

## See also

[GetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getthreaderrormode)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)