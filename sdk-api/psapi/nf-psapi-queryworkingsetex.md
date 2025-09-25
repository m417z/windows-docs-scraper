# QueryWorkingSetEx function

## Description

Retrieves extended information about the pages at specific virtual addresses in the address space of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `pv` [in, out]

A pointer to an array of [PSAPI_WORKING_SET_EX_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_ex_information) structures. On input, each item in the array specifies a virtual address of interest. On output, each item in the array receives information about the corresponding virtual page.

### `cb` [in]

The size of the *pv* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Unlike the [QueryWorkingSet](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingset) function, which is limited to the working set of the target process, the **QueryWorkingSetEx** function can be used to query addresses that are not in the process working set but are still part of the process, such as AWE and large pages.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as **K32QueryWorkingSetEx** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this function is defined as **QueryWorkingSetEx** in Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls **K32QueryWorkingSetEx**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions should always call this function as **QueryWorkingSetEx**. To ensure correct resolution of symbols, add Psapi.lib to the **TARGETLIBS** macro and compile the program with "–DPSAPI_VERSION=1". To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see [Allocating Memory from a NUMA Node](https://learn.microsoft.com/windows/desktop/Memory/allocating-memory-from-a-numa-node).

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[PSAPI_WORKING_SET_EX_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_ex_information)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)