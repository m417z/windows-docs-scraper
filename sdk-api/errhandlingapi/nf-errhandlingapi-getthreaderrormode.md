# GetThreadErrorMode function

## Description

Retrieves the error mode for the calling thread.

## Return value

The process error mode. This function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| 0 | Uses the system default, which is to display all error dialog boxes. |
| **SEM_FAILCRITICALERRORS**<br><br>0x0001 | The system does not display the critical-error-handler message box. Instead, the system sends the error to the calling thread. |
| **SEM_NOGPFAULTERRORBOX**<br><br>0x0002 | The system does not display the Windows Error Reporting dialog. |
| **SEM_NOOPENFILEERRORBOX**<br><br>0x8000 | The system does not display a message box when it fails to find a file. Instead, the error is returned to the calling thread. |

## Remarks

A thread inherits the error mode of the process in which it is running. To change the error mode for the thread, use the [SetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode) function.

## See also

[GetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-geterrormode)

[SetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode)