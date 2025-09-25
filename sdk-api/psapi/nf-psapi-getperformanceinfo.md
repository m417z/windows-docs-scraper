# GetPerformanceInfo function

## Description

Retrieves the performance values contained in the
[PERFORMANCE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-performance_information)
structure.

## Parameters

### `pPerformanceInformation` [out]

A pointer to a
[PERFORMANCE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-performance_information)
structure that receives the performance information.

### `cb` [in]

The size of the
[PERFORMANCE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-performance_information) structure, in
bytes.

## Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE. To get
extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for
the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a
program must load.

If PSAPI_VERSION is 2 or greater, this function is defined as
**K32GetPerformanceInfo** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If
PSAPI_VERSION is 1, this function is defined as
**GetPerformanceInfo** in Psapi.h and exported in
Psapi.lib and Psapi.dll as a wrapper that calls **K32GetPerformanceInfo**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions
should always call this function as
**GetPerformanceInfo**. To ensure correct resolution
of symbols, add Psapi.lib to the TARGETLIBS macro and compile the program with
–DPSAPI_VERSION=1. To use run-time dynamic linking, load Psapi.dll.

## See also

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))

[PERFORMANCE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-performance_information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)