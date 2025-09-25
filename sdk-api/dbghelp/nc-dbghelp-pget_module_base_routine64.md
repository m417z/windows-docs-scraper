# PGET_MODULE_BASE_ROUTINE64 callback function

## Description

An application-defined callback function used with the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function. It is called when
**StackWalk64** needs a module base address for a given virtual address.

The **PGET_MODULE_BASE_ROUTINE64** type defines a pointer to this callback function.
**GetModuleBaseProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process for which the stack trace is generated.

### `Address` [in]

An address within the module image to be located.

## Return value

The function returns the base address of the module.

## Remarks

This callback function supersedes the *PGET_MODULE_BASE_ROUTINE* callback function. *PGET_MODULE_BASE_ROUTINE* is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PGET_MODULE_BASE_ROUTINE PGET_MODULE_BASE_ROUTINE64
#else
typedef
DWORD
(__stdcall *PGET_MODULE_BASE_ROUTINE)(
    __in HANDLE hProcess,
    __in DWORD Address
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk)