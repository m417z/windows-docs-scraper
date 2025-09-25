# QueryWorkingSet function

## Description

Retrieves information about the pages currently added to the working set of the specified
process.

To retrieve working set information for a subset of virtual addresses, or to retrieve information about pages
that are not part of the working set (such as AWE or large pages), use the
[QueryWorkingSetEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingsetex) function.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** and
**PROCESS_VM_READ** access rights. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `pv` [out]

A pointer to the buffer that receives the information. For more information, see
[PSAPI_WORKING_SET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_information).

If the buffer pointed to by the *pv* parameter is not large enough to contain all
working set entries for the target process, the function fails with **ERROR_BAD_LENGTH**.
In this case, the **NumberOfEntries** member of the
[PSAPI_WORKING_SET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_information)
structure is set to the required number of entries, but the function does not return information about the
working set entries.

### `cb` [in]

The size of the *pv* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32QueryWorkingSet** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **QueryWorkingSet** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32QueryWorkingSet**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions
should always call this function as **QueryWorkingSet**.
To ensure correct resolution of symbols, add Psapi.lib to the
**TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load
Psapi.dll.

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[PSAPI_WORKING_SET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_information)

[QueryWorkingSetEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingsetex)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)