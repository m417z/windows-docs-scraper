# EnumPageFilesW function

## Description

Calls the callback routine for each installed pagefile in the system.

## Parameters

### `pCallBackRoutine` [out]

A pointer to the routine called for each pagefile. For more information, see
[EnumPageFilesProc](https://learn.microsoft.com/windows/desktop/api/psapi/nc-psapi-penum_page_file_callbacka).

### `pContext` [in]

The user-defined data passed to the callback routine.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the
return value is **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32EnumPageFiles** in Psapi.h and exported in Kernel32.lib and
Kernel32.dll. If **PSAPI_VERSION** is 1, this function is defined as
**EnumPageFiles** in Psapi.h and exported in
Psapi.lib and Psapi.dll as a wrapper that calls
**K32EnumPageFiles**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions
should always call this function as **EnumPageFiles**. To
ensure correct resolution of symbols, add Psapi.lib to the **TARGETLIBS**
macro and compile the program with –DPSAPI_VERSION=1. To use run-time dynamic linking, load
Psapi.dll.

> [!NOTE]
> The psapi.h header defines EnumPageFiles as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumPageFilesProc](https://learn.microsoft.com/windows/desktop/api/psapi/nc-psapi-penum_page_file_callbacka)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)