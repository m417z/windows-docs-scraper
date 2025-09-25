# SymFunctionTableAccess64 function

## Description

Retrieves the function table entry for the specified address.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `AddrBase` [in]

The base address for which function table information is required.

## Return value

If the function succeeds, the return value is a pointer to the function table entry.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The type of pointer returned is specific to the image from which symbols are loaded.

**x86:** If the image is for an x86 system, this is a pointer to an
[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data) structure.

**x64:** If the image is for an x64 system, this is a pointer to an [_IMAGE_RUNTIME_FUNCTION_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) structure.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function supersedes the **SymFunctionTableAccess** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymFunctionTableAccess** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymFunctionTableAccess SymFunctionTableAccess64
#else
PVOID
IMAGEAPI
SymFunctionTableAccess(
    __in HANDLE hProcess,
    __in DWORD AddrBase
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data)

[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[_IMAGE_RUNTIME_FUNCTION_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function)