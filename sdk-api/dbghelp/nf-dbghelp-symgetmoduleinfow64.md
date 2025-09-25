# SymGetModuleInfoW64 function

## Description

Retrieves the module information of the specified module.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `qwAddr` [in]

The virtual address that is contained in one of the modules loaded by the
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule) function.

### `ModuleInfo` [out]

A pointer to an
[IMAGEHLP_MODULEW64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_modulew64) structure. The **SizeOfStruct** member must be set to the size of the
**IMAGEHLP_MODULEW64** structure. An invalid value will result in an error.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The module table is searched for a module that contains the *dwAddr*. The module is located based on the load address and size of each module. If a valid module is found, the *ModuleInfo* parameter is filled with the information about the module.

The size of the [IMAGEHLP_MODULEW64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_modulew64) structure used by this function has changed over the years. If a version of DbgHelp.dll is called that is older than the DbgHelp.h used to compile the calling code, then this function may fail with an error code of **ERROR_INVALID_PARAMETER**. This most commonly occurs when the system version (%WinDir%\System32\DbgHelp.dll) is called. Code that calls the system version of DbgHelp.dll must be compiled using the appropriate SDK for that Windows release or the SDK for a previous release.

The recommended model is to redistribute the required version of DbgHelp.dll along with the calling software. This allows the caller to use the most robust versions of DbgHelp.dll as well as a simplifying upgrades. The most recent version of DbgHelp.dll can always be found in the [Debugging Tools for Windows](https://learn.microsoft.com/windows-hardware/drivers/debugger/) package. As a general rule, code that is compiled to work with older versions will always work with newer versions.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define **DBGHELP_TRANSLATE_TCHAR**. **SymGetModuleInfoW64** is defined as follows in DbgHelp.h.

```cpp

BOOL
IMAGEAPI
SymGetModuleInfoW64(
    __in HANDLE hProcess,
    __in DWORD64 qwAddr,
    __out PIMAGEHLP_MODULEW64 ModuleInfo
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymGetModuleInfo64   SymGetModuleInfoW64
#endif
```

This function supersedes the **SymGetModuleInfo** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymGetModuleInfo** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetModuleInfo   SymGetModuleInfo64
#define SymGetModuleInfoW  SymGetModuleInfoW64
#else
BOOL
IMAGEAPI
SymGetModuleInfo(
    __in HANDLE hProcess,
    __in DWORD dwAddr,
    __out PIMAGEHLP_MODULE ModuleInfo
    );

BOOL
IMAGEAPI
SymGetModuleInfoW(
    __in HANDLE hProcess,
    __in DWORD dwAddr,
    __out PIMAGEHLP_MODULEW ModuleInfo
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_MODULEW64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_modulew64)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule)