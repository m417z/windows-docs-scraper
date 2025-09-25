# LoadModule function

## Description

Loads and executes an application or creates a new instance of an existing application.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function.

## Parameters

### `lpModuleName` [in]

The file name of the application to be run. When specifying a path, be sure to use backslashes (\\), not forward slashes (/). If the *lpModuleName* parameter does not contain a directory path, the system searches for the executable file in this order:

1. The directory from which the application loaded.
2. The current directory.
3. The system directory. Use the
   [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory.
4. The 16-bit system directory. There is no function that obtains the path of this directory, but it is searched. The name of this directory is System.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable.

### `lpParameterBlock` [in]

A pointer to an application-defined **LOADPARMS32** structure that defines the new application's parameter block.

Set all unused members to NULL, except for **lpCmdLine**, which must point to a null-terminated string if it is not used. For more information, see Remarks.

## Return value

If the function succeeds, the return value is greater than 31.

If the function fails, the return value is an error value, which may be one of the following values.

| Return code/value | Description |
| --- | --- |
| 0 | The system is out of memory or resources. |
| **ERROR_BAD_FORMAT**<br><br>11L | The .exe file is invalid. |
| **ERROR_FILE_NOT_FOUND**<br><br>2L | The specified file was not found. |
| **ERROR_PATH_NOT_FOUND**<br><br>3L | The specified path was not found. |

## Remarks

The **LOADPARMS32** structure has the following form:

``` syntax
typedef struct tagLOADPARMS32 {
  LPSTR lpEnvAddress;  // address of environment strings
  LPSTR lpCmdLine;     // address of command line
  LPSTR lpCmdShow;     // how to show new program
  DWORD dwReserved;    // must be zero
} LOADPARMS32;
```

| Member | Meaning |
| --- | --- |
| **lpEnvAddress** | Pointer to an array of null-terminated strings that supply the environment strings for the new process. The array has a value of NULL as its last entry. A value of NULL for this parameter causes the new process to start with the same environment as the calling process. |
| **lpCmdLine** | Pointer to a Pascal-style string that contains a correctly formed command line. The first byte of the string contains the number of bytes in the string. The remainder of the string contains the command line arguments, excluding the name of the child process. If there are no command line arguments, this parameter must point to a zero length string; it cannot be NULL. |
| **lpCmdShow** | Pointer to a structure containing two **WORD** values. The first value must always be set to two. The second value specifies how the application window is to be shown and is used to supply the **wShowWindow** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure to the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function. See the description of the *nCmdShow* parameter of the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function for a list of acceptable values. |
| **dwReserved** | This parameter is reserved; it must be zero. |

Applications should use the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function instead of
**LoadModule**. The
**LoadModule** function calls
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) by forming the parameters as follows.

| CreateProcess parameter | Argument used |
| --- | --- |
| *lpszApplicationName* | *lpModuleName* |
| *lpszCommandLine* | *lpParameterBlock*.**lpCmdLine** |
| *lpProcessAttributes* | NULL |
| *lpThreadAttributes* | NULL |
| *bInheritHandles* | FALSE |
| *dwCreationFlags* | 0 |
| *lpEnvironment* | *lpParameterBlock*.**lpEnvAddress** |
| *lpCurrentDirectory* | NULL |
| *lpStartupInfo* | The structure is initialized to zero. The **cb** member is set to the size of the structure. The **wShowWindow** member is set to the value of the second word of *lpParameterBlock*.**lpCmdShow**. |
| *lpProcessInformation***.hProcess** | The handle is immediately closed. |
| *lpProcessInformation***.hThread** | The handle is immediately closed. |

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-functions)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)