# GetModuleFileNameExW function

## Description

Retrieves the fully qualified path for the file containing the specified module.

## Parameters

### `hProcess` [in]

A handle to the process that contains the module.

The handle must have the **PROCESS_QUERY_INFORMATION** and **PROCESS_VM_READ** access rights. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows 10 and later, Windows Server 2016 and later**: If the *hModule* parameter is NULL, then the handle requires only **PROCESS_QUERY_LIMITED_INFORMATION** access rights.

The **GetModuleFileNameEx** function does not retrieve the path for modules that were loaded using the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

### `hModule` [in, optional]

A handle to the module. If this parameter is NULL, **GetModuleFileNameEx** returns the path of the executable file of the process specified in *hProcess*.

### `lpFilename` [out]

A pointer to a buffer that receives the fully qualified path to the module. If the size of the file name is larger than the value of the *nSize* parameter, the function succeeds but the file name is truncated and null-terminated.

### `nSize` [in]

The size of the *lpFilename* buffer, in characters.

## Return value

If the function succeeds, the return value specifies the length of the string copied to the buffer.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetModuleFileNameEx** function is primarily designed for use by debuggers and similar applications that must extract module information from another process. If the module list in the target process is corrupted or is not yet initialized, or if the module list changes during the function call as a result of DLLs being loaded or unloaded, **GetModuleFileNameEx** may fail or return incorrect information.

To retrieve the name of a module in the current process, use the [GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) function. This is more efficient and more reliable than calling **GetModuleFileNameEx** with a handle to the current process.

To retrieve the name of the main executable module for a remote process, use the [GetProcessImageFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessimagefilenamew) or [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamew) function. This is more efficient and more reliable than calling the **GetModuleFileNameEx** function with a NULL module handle.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetModuleFileNameEx** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetModuleFileNameEx** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetModuleFileNameEx**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**GetModuleFileNameEx**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see
[Enumerating All Modules for a Process](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-modules-for-a-process).

> [!NOTE]
> The psapi.h header defines GetModuleFileNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[GetModuleBaseName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulebasenamew)

[GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamew)

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlew)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryw)

[Module Information](https://learn.microsoft.com/windows/desktop/psapi/module-information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)