# EnumProcesses function

## Description

Retrieves the process identifier for each process object in the system.

## Parameters

### `lpidProcess` [out]

A pointer to an array that receives the list of process identifiers.

### `cb` [in]

The size of the *pProcessIds* array, in bytes.

### `lpcbNeeded` [out]

The number of bytes returned in the *pProcessIds* array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is a good idea to use a large array, because it is hard to predict how many processes there will be at the time you call
**EnumProcesses**.

To determine how many processes were enumerated, divide the *lpcbNeeded* value by sizeof(DWORD). There is no indication given when the buffer is too small to store all process identifiers. Therefore, if *lpcbNeeded* equals *cb*, consider retrying the call with a larger array.

To obtain process handles for the processes whose identifiers you have just obtained, call the [OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a program must load.

If PSAPI_VERSION is 2 or greater, this function is defined as **K32EnumProcesses** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If PSAPI_VERSION is 1, this function is defined as **EnumProcesses** in Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls **K32EnumProcesses**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions should always call this function as **EnumProcesses**. To ensure correct resolution of symbols, add Psapi.lib to the TARGETLIBS macro and compile the program with –DPSAPI_VERSION=1. To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see
[Enumerating All Processes](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-processes) or
[Enumerating All Modules for a Process](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-modules-for-a-process).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[Process Information](https://learn.microsoft.com/windows/desktop/psapi/process-information)