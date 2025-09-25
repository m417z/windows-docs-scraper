# SymRegisterFunctionEntryCallback function

## Description

Registers a callback function for use by the stack walking procedure on Alpha computers.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function.

### `CallbackFunction` [in]

A [SymRegisterFunctionEntryCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_funcentry_callback) callback function.

### `UserContext` [in]

A user-defined value or **NULL**. This value is simply passed to the callback function. Normally, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some context.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymRegisterFunctionEntryCallback64** function lets an application register a callback function for use by the stack walking procedure. The stack walking procedure calls the registered callback function when it is unable to locate a function table entry for an address. In most cases, the stack walking procedure locates the function table entries in the function table of the image containing the address. However, in situations where the function table entries are not in the image, this callback allows the debugger to provide the function table entry from another source. For example, run-time generated code on Alpha computers can define dynamic function tables to support exception handling and stack tracing.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function supersedes the **SymRegisterFunctionEntryCallback** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymRegisterFunctionEntryCallback** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymRegisterFunctionEntryCallback SymRegisterFunctionEntryCallback64
#else
BOOL
IMAGEAPI
SymRegisterFunctionEntryCallback(
    __in HANDLE hProcess,
    __in PSYMBOL_FUNCENTRY_CALLBACK CallbackFunction,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk)

[SymRegisterFunctionEntryCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_funcentry_callback)