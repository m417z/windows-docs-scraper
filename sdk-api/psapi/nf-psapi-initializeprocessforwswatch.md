# InitializeProcessForWsWatch function

## Description

Initiates monitoring of the working set of the specified process. You must call this function before calling the
[GetWsChanges](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschanges) function.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32InitializeProcessForWsWatch** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **InitializeProcessForWsWatch** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32InitializeProcessForWsWatch**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**InitializeProcessForWsWatch**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[GetWsChanges](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschanges)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)