# GetModuleBaseNameW function

## Description

Retrieves the base name of the specified module.

## Parameters

### `hProcess` [in]

A handle to the process that contains the module.

The handle must have the **PROCESS_QUERY_INFORMATION** and **PROCESS_VM_READ** access rights. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `hModule` [in, optional]

A handle to the module. If this parameter is NULL, this function returns the name of the file used to create the calling process.

### `lpBaseName` [out]

A pointer to the buffer that receives the base name of the module. If the base name is longer than maximum number of characters specified by the *nSize* parameter, the base name is truncated.

### `nSize` [in]

The size of the *lpBaseName* buffer, in characters.

## Return value

If the function succeeds, the return value specifies the length of the string copied to the buffer, in characters.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetModuleBaseName** function is primarily designed for use by debuggers and similar applications that must extract module information from another process. If the module list in the target process is corrupted or is not yet initialized, or if the module list changes during the function call as a result of DLLs being loaded or unloaded, **GetModuleBaseName** may fail or return incorrect information.

To retrieve the base name of a module in the current process, use the [GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) function to retrieve the full module name and then use a function call such as `strrchr(szmodulename, '\\')` to scan to the beginning of the base name within the module name string. This is more efficient and more reliable than calling **GetModuleBaseName** with a handle to the current process.

To retrieve the base name of the main executable module for a remote process, use the [GetProcessImageFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessimagefilenamew) or [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamew) function to retrieve the module name and then use the `strrchr` function as described in the previous paragraph. This is more efficient and more reliable than calling **GetModuleBaseName** with a NULL module handle.

The **GetModuleBaseName** function does not retrieve the base name for modules that were loaded with the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetModuleBaseName** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetModuleBaseName** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetModuleBaseName**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**GetModuleBaseName**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see
[Enumerating All Processes](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-processes).

> [!NOTE]
> The psapi.h header defines GetModuleBaseName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexw)

[Module Information](https://learn.microsoft.com/windows/desktop/psapi/module-information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](https://learn.microsoft.com/cpp/c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l)