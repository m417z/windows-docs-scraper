# GetErrorMode function

## Description

Retrieves the error mode for the current process.

## Return value

The process error mode. This function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| 0 | Uses the system default, which displays all error dialog boxes. |
| **SEM_FAILCRITICALERRORS**<br><br>0x0001 | The system does not display the critical-error-handler message box. Instead, the system sends the error to the calling process. |
| **SEM_NOALIGNMENTFAULTEXCEPT**<br><br>0x0004 | The system automatically fixes memory alignment faults and makes them invisible to the application. It does this for the calling process and any descendant processes. This feature is only supported by certain processor architectures. For more information, see [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode). |
| **SEM_NOGPFAULTERRORBOX**<br><br>0x0002 | The system does not display the Windows Error Reporting dialog. |
| **SEM_NOOPENFILEERRORBOX**<br><br>0x8000 | The system does not display a message box when it fails to find a file. Instead, the error is returned to the calling process. |

## Remarks

Each process has an associated error mode that indicates to the system how the application is going to respond
to serious errors. A child process inherits the error mode of its parent process.

To change the error mode for the process, use the
[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function.

**Windows 7:** Callers should favor [SetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode) over
[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) since it is less disruptive to the normal
behavior of the system. [GetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getthreaderrormode) is the
call function that corresponds to **GetErrorMode**.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[Error Mode](https://learn.microsoft.com/windows/desktop/Debug/error-mode)

[GetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getthreaderrormode)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)