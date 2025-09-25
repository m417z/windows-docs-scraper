# GetProcessMemoryInfo function

## Description

Retrieves information about the memory usage of the specified process.

## Parameters

### `Process` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** and **PROCESS_VM_READ** access rights.

### `ppsmemCounters` [out]

A pointer to the
[PROCESS_MEMORY_COUNTERS](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-process_memory_counters), [PROCESS_MEMORY_COUNTERS_EX](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-process_memory_counters_ex), or [PROCESS_MEMORY_COUNTERS_EX2](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-process_memory_counters_ex2) structure that receives information about the memory usage of the process.

### `cb` [in]

The size of the
*ppsmemCounters* structure, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
    **K32GetProcessMemoryInfo** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetProcessMemoryInfo** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
    **K32GetProcessMemoryInfo**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
    **GetProcessMemoryInfo**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
    **-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see
[Collecting Memory Usage Information for a Process](https://learn.microsoft.com/windows/desktop/psapi/collecting-memory-usage-information-for-a-process).

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))

[PROCESS_MEMORY_COUNTERS](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-process_memory_counters)

[PROCESS_MEMORY_COUNTERS_EX](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-process_memory_counters_ex)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[Process Memory Usage Information](https://learn.microsoft.com/windows/desktop/psapi/process-memory-usage-information)