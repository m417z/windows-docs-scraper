# EnumerateLoadedModules function

## Description

Enumerates the loaded modules for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose modules will be enumerated.

### `EnumLoadedModulesCallback` [in]

An application-defined callback function. For more information, see
[EnumerateLoadedModulesProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumloaded_modules_callback).

### `UserContext` [in, optional]

Optional user-defined data. This value is passed to the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, *EnumerateLoadedModulesW64*, define **DBGHELP_TRANSLATE_TCHAR**. *EnumerateLoadedModulesW64* is defined as follows in DbgHelp.h.

```cpp
BOOL
IMAGEAPI
EnumerateLoadedModulesW64(
    __in HANDLE hProcess,
    __in PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback,
    __in PVOID UserContext
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
    #define EnumerateLoadedModules64      EnumerateLoadedModulesW64
#endif
```

This function supersedes the *EnumerateLoadedModules* function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). *EnumerateLoadedModules* is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define EnumerateLoadedModules EnumerateLoadedModules64
#else
BOOL
IMAGEAPI
EnumerateLoadedModules(
    __in HANDLE hProcess,
    __in PENUMLOADED_MODULES_CALLBACK EnumLoadedModulesCallback,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[EnumerateLoadedModulesProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-penumloaded_modules_callback)