# SetErrorMode function

## Description

Controls whether the system or the process handles the specified serious error types.

## Parameters

### `uMode` [in]

The process error mode. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Use the system default, which displays all error dialog boxes. |
| **SEM_FAILCRITICALERRORS**<br><br>0x0001 | The system does not display the critical-error-handler message box. Instead, the system sends the error to the calling process.<br><br>Best practice is that all applications call the process-wide **SetErrorMode** function with a parameter of **SEM_FAILCRITICALERRORS** at startup. This is to prevent error mode dialogs from hanging the application. |
| **SEM_NOALIGNMENTFAULTEXCEPT**<br><br>0x0004 | The system automatically fixes memory alignment faults and makes them invisible to the application. It does this for the calling process and any descendant processes. This feature is only supported by certain processor architectures. For more information, see the Remarks section.<br><br>After this value is set for a process, subsequent attempts to clear the value are ignored. |
| **SEM_NOGPFAULTERRORBOX**<br><br>0x0002 | The system does not invoke Windows Error Reporting. To disable Windows Error Reporting UI, call WerSetFlags with the WER_FAULT_REPORTING_NO_UI flag. |
| **SEM_NOOPENFILEERRORBOX**<br><br>0x8000 | The [OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function does not display a message box when it fails to find a file. Instead, the error is returned to the caller. This error mode overrides the **OF_PROMPT** flag. |

## Return value

The return value is the previous state of the error-mode bit flags.

## Remarks

Each process has an associated error mode that indicates to the system how the application is going to respond to serious errors. A child process inherits the error mode of its parent process. To retrieve the process error mode, use the [GetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-geterrormode) function.

Because the error mode is set for the entire process, you must ensure that multi-threaded applications do not set different error-mode flags. Doing so can lead to inconsistent error handling.

The system does not make alignment faults visible to an application on all processor architectures. Therefore, specifying SEM_NOALIGNMENTFAULTEXCEPT is not an error on such architectures, but the system is free to silently ignore the request. This means that code sequences such as the following are not always valid on x86 computers:

| C++ |
| --- |
| ``` SetErrorMode(SEM_NOALIGNMENTFAULTEXCEPT);  fuOldErrorMode = SetErrorMode(0);  ASSERT(fuOldErrorMode == SEM_NOALIGNMENTFAULTEXCEPT); ``` |

**Itanium:** An application must explicitly call
**SetErrorMode** with SEM_NOALIGNMENTFAULTEXCEPT to have the system automatically fix alignment faults. The default setting is for the system to make alignment faults visible to an application.

**Visual Studio 2005:** When declaring a pointer to a structure that may not have aligned data, you can use the **__unaligned** keyword to indicate that the type must be read one byte at a time. For more information, see [Windows Data Alignment](https://msdn.microsoft.com/library/Aa290049.aspx).

**Windows 7:** Callers should favor [SetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode) over **SetErrorMode** since it is less disruptive to the normal behavior of the system.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[Error Mode](https://learn.microsoft.com/windows/desktop/Debug/error-mode)

[GetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-geterrormode)

[SetThreadErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode)