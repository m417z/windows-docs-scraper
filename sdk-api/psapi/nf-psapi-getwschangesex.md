# GetWsChangesEx function

## Description

Retrieves extended information about the pages that have been added to the working set of the specified process since the
last time this function or the [InitializeProcessForWsWatch](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-initializeprocessforwswatch) function was called.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpWatchInfoEx` [out]

A pointer to a user-allocated buffer that receives an array of
[PSAPI_WS_WATCH_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_ws_watch_information_ex) structures. The array is terminated with a structure whose **FaultingPc** member is NULL.

### `cb` [in, out]

The size of the
*lpWatchInfoEx* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_INSUFFICIENT_BUFFER** if the *lpWatchInfoEx* buffer is not large enough to contain all the working set change records; the buffer is returned empty. Reallocate a larger block of memory for the buffer and call again.

## Remarks

The operating system uses one buffer per process to maintain working set change records. If more than one application (or multiple threads in the same application) calls this function with the same process handle, neither application will have a complete accounting of the working set changes because each call empties the buffer.

The operating system does not record new change records while it is processing the query (and emptying the buffer). This function sets the error code to **NO_MORE_ENTRIES** if a concurrent query is received while it is processing another query.

If the buffer becomes full, no new records are added to the buffer until this function or the [InitializeProcessForWsWatch](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-initializeprocessforwswatch) function is called. You should call **GetWsChangesEx** with enough frequency to prevent possible data loss. If records are lost, the array is terminated with a structure whose **FaultingPc** member is NULL and whose **FaultingVa** member is set to the number of records that were lost.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetWsChangesEx** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetWsChangesEx** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetWsChangesEx**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**GetWsChangesEx**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[InitializeProcessForWsWatch](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-initializeprocessforwswatch)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[PSAPI_WS_WATCH_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_ws_watch_information_ex)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)