# GetModuleInformation function

## Description

Retrieves information about the specified module in the
[MODULEINFO](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-moduleinfo) structure.

## Parameters

### `hProcess` [in]

A handle to the process that contains the module.

The handle must have the **PROCESS_QUERY_INFORMATION** and **PROCESS_VM_READ** access rights. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `hModule` [in]

A handle to the module.

### `lpmodinfo` [out]

A pointer to the
[MODULEINFO](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-moduleinfo) structure that receives information about the module.

### `cb` [in]

The size of the
[MODULEINFO](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-moduleinfo) structure, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To get information for the calling process, pass the handle returned by [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess).

The **GetModuleInformation** function does not retrieve information for modules that were loaded with the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetModuleInformation** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as K32GetModuleInformation in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetModuleInformation**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
K32GetModuleInformation. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[MODULEINFO](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-moduleinfo)

[Module Information](https://learn.microsoft.com/windows/desktop/psapi/module-information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)