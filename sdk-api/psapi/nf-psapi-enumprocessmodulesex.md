# EnumProcessModulesEx function

## Description

Retrieves a handle for each module in the specified process that meets the specified filter criteria.

## Parameters

### `hProcess` [in]

A handle to the process.

### `lphModule` [out]

An array that receives the list of module handles.

### `cb` [in]

The size of the *lphModule* array, in bytes.

### `lpcbNeeded` [out]

The number of bytes required to store all module handles in the *lphModule* array.

### `dwFilterFlag` [in]

The filter criteria. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LIST_MODULES_32BIT**<br><br>0x01 | List the 32-bit modules. |
| **LIST_MODULES_64BIT**<br><br>0x02 | List the 64-bit modules. |
| **LIST_MODULES_ALL**<br><br>0x03 | List all modules. |
| **LIST_MODULES_DEFAULT**<br><br>0x0 | Use the default behavior. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **EnumProcessModulesEx** function is primarily designed for use by debuggers and similar applications that must extract module information from another process. If the module list in the target process is corrupted or not yet initialized, or if the module list changes during the function call as a result of DLLs being loaded or unloaded, **EnumProcessModulesEx** may fail or return incorrect information.

This function is intended primarily for 64-bit applications. If the function is called by a 32-bit application running under WOW64, the *dwFilterFlag* option is ignored and the function provides the same results as the [EnumProcessModules](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocessmodules) function.

It is a good idea to specify a large array of **HMODULE** values, because it is hard to predict how many modules there will be in the process at the time you call
**EnumProcessModulesEx**. To determine if the *lphModule* array is too small to hold all module handles for the process, compare the value returned in *lpcbNeeded* with the value specified in *cb*. If *lpcbNeeded* is greater than *cb*, increase the size of the array and call
**EnumProcessModulesEx** again.

To determine how many modules were enumerated by the call to
**EnumProcessModulesEx**, divide the resulting value in the *lpcbNeeded* parameter by `sizeof(HMODULE)`.

The **EnumProcessModulesEx** function does not retrieve handles for modules that were loaded with the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

Do not call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) on any of the handles returned by this function. The information comes from a snapshot, so there are no resources to be freed.

To take a snapshot of specified processes and the heaps, modules, and threads used by these processes, use the [CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a program must load.

If PSAPI_VERSION is 2 or greater, this function is defined as **K32EnumProcessModulesEx** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If PSAPI_VERSION is 1, this function is defined as **EnumProcessModulesEx** in Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls **K32EnumProcessModulesEx**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions should always call this function as **EnumProcessModulesEx**. To ensure correct resolution of symbols, add Psapi.lib to the TARGETLIBS macro and compile the program with –DPSAPI_VERSION=1. To use run-time dynamic linking, load Psapi.dll.

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[Module Information](https://learn.microsoft.com/windows/desktop/psapi/module-information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)