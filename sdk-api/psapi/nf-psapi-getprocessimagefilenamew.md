# GetProcessImageFileNameW function

## Description

Retrieves the name of the executable file for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpImageFileName` [out]

A pointer to a buffer that receives the full path to the executable file.

### `nSize` [in]

The size of the *lpImageFileName* buffer, in characters.

## Return value

If the function succeeds, the return value specifies the length of the string copied to the buffer.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The file Psapi.dll is installed in the %windir%\System32 directory. If there is another copy of this DLL on your computer, it can lead to the following error when running applications on your system: "The procedure entry point GetProcessImageFileName could not be located in the dynamic link library PSAPI.DLL." To work around this problem, locate any versions that are not in the %windir%\System32 directory and delete or rename them, then restart.

The **GetProcessImageFileName** function returns the path in device form, rather than drive letters. For example, the file name C:\Windows\System32\Ctype.nls would look as follows in device form:

\Device\Harddisk0\Partition1\Windows\System32\Ctype.nls

To retrieve the module name of the current process, use the [GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) function with a NULL module handle. This is more efficient than calling the **GetProcessImageFileName** function with a handle to the current process.

To retrieve the name of the main executable module for a remote process in win32 path format, use the [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamew) function.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetProcessImageFileName** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetProcessImageFileName** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetProcessImageFileName**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**GetProcessImageFileName**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

> [!NOTE]
> The psapi.h header defines GetProcessImageFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[Process Information](https://learn.microsoft.com/windows/desktop/psapi/process-information)

[QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamew)