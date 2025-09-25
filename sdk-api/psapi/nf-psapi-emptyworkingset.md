# EmptyWorkingSet function

## Description

Removes as many pages as possible from the working set of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right and the **PROCESS_SET_QUOTA** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can also empty the working set by calling the [SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize) or [SetProcessWorkingSetSizeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setprocessworkingsetsizeex) function with the *dwMinimumWorkingSetSize* and *dwMaximumWorkingSetSize* parameters set to the value `(SIZE_T)(-1)`.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32EmptyWorkingSet** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as K32EmptyWorkingSet in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32EmptyWorkingSet**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
K32EmptyWorkingSet. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize)

[Working Set](https://learn.microsoft.com/windows/desktop/Memory/working-set)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)