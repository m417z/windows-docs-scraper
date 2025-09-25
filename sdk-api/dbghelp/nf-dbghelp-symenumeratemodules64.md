# SymEnumerateModules64 function

## Description

Enumerates all modules that have been loaded for the process by the
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule) or [SymLoadModuleEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmoduleex) function.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `EnumModulesCallback` [in]

The enumeration callback function. This function is called once per module. For more information, see
[SymEnumerateModulesProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enummodules_callback).

### `UserContext` [in, optional]

A user-defined value or **NULL**. This value is simply passed to the callback function. Normally, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some type of context.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymEnumerateModules64** function enumerates all modules that have been loaded for the process by
[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule), even if the symbol loading is deferred. The enumeration callback function is called once for each module and is passed the module information.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymEnumerateModulesW64** is defined as follows in Dbghelp.h.

```cpp

BOOL
IMAGEAPI
SymEnumerateModulesW64(
    __in HANDLE hProcess,
    __in PSYM_ENUMMODULES_CALLBACKW64 EnumModulesCallback,
    __in_opt PVOID UserContext
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymEnumerateModules64  SymEnumerateModulesW64
#endif
```

This function supersedes the **SymEnumerateModules** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymEnumerateModules** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymEnumerateModules SymEnumerateModules64
#else
BOOL
IMAGEAPI
SymEnumerateModules(
    __in HANDLE hProcess,
    __in PSYM_ENUMMODULES_CALLBACK EnumModulesCallback,
    __in_opt PVOID UserContext
    );
#endif
```

#### Examples

For an example, see
[Enumerating Symbol Modules](https://learn.microsoft.com/windows/desktop/Debug/enumerating-symbol-modules).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumerateModulesProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enummodules_callback)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[SymLoadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmodule)