# PFUNCTION_TABLE_ACCESS_ROUTINE callback function

## Description

An application-defined callback function used with the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function. It provides access to the run-time function table for the process.

The **PFUNCTION_TABLE_ACCESS_ROUTINE64** type defines a pointer to this callback function.
**FunctionTableAccessProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process for which the stack trace is generated.

### `AddrBase` [in]

The address of the instruction to be located.

## Return value

The function returns a pointer to the run-time function table. On an x86 computer, this is a pointer to an
[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data) structure. On an Alpha computer, this is a pointer to an
[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry) structure.

## Remarks

This callback function supersedes the *PFUNCTION_TABLE_ACCESS_ROUTINE* callback function. *PFUNCTION_TABLE_ACCESS_ROUTINE* is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PFUNCTION_TABLE_ACCESS_ROUTINE PFUNCTION_TABLE_ACCESS_ROUTINE64
#else
typedef
PVOID
(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE)(
    __in HANDLE hProcess,
    __in DWORD AddrBase
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data)

[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry)

[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk)