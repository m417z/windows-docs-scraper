# WinExec function

## Description

Runs the specified application.

**Note** This function is provided only for compatibility with 16-bit Windows. Applications should use the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function.

## Parameters

### `lpCmdLine` [in]

The command line (file name plus optional parameters) for the application to be executed. If the name of the executable file in the *lpCmdLine* parameter does not contain a directory path, the system searches for the executable file in this sequence:

1. The directory from which the application loaded.
2. The current directory.
3. The Windows system directory. The
   [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function retrieves the path of this directory.
4. The Windows directory. The
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function retrieves the path of this directory.
5. The directories listed in the PATH environment variable.

### `uCmdShow` [in]

The display options. For a list of the acceptable values, see the description of the *nCmdShow* parameter of the
[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

## Return value

If the function succeeds, the return value is greater than 31.

If the function fails, the return value is one of the following error values.

| Return code/value | Description |
| --- | --- |
| 0 | The system is out of memory or resources. |
| **ERROR_BAD_FORMAT** | The .exe file is invalid. |
| **ERROR_FILE_NOT_FOUND** | The specified file was not found. |
| **ERROR_PATH_NOT_FOUND** | The specified path was not found. |

## Remarks

The
**WinExec** function returns when the started process calls the [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) function or a time-out limit is reached. To avoid waiting for the time out delay, call the **GetMessage** function as soon as possible in any process started by a call to
**WinExec**.

### Security Remarks

The executable name is treated as the first white space-delimited string in *lpCmdLine*. If the executable or path name has a space in it, there is a risk that a different executable could be run because of the way the function parses spaces. The following example is dangerous because the function will attempt to run "Program.exe", if it exists, instead of "MyApp.exe".

``` syntax
WinExec("C:\\Program Files\\MyApp", ...)
```

If a malicious user were to create an application called "Program.exe" on a system, any program that incorrectly calls
**WinExec** using the Program Files directory will run this application instead of the intended application.

To avoid this problem, use
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) rather than
**WinExec**. However, if you must use
**WinExec** for legacy reasons, make sure the application name is enclosed in quotation marks as shown in the example below.

``` syntax
WinExec("\"C:\\Program Files\\MyApp.exe\" -L -S", ...)
```

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)