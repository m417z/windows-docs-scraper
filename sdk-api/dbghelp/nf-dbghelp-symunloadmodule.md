# SymUnloadModule function

## Description

Unloads the symbol table.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module that is to be unloaded.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

The [SymUnloadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symunloadmodule64) function supersedes this function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymUnloadedModule** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymUnloadModule SymUnloadModule64
#else
BOOL
IMAGEAPI
SymUnloadModule(
    __in HANDLE hProcess,
    __in DWORD BaseOfDll
    );
#endif
```

#### Examples

For an example, see
[Unloading a Symbol Module](https://learn.microsoft.com/windows/desktop/Debug/unloading-a-symbol-module).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)