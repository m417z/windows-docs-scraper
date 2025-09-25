# SymRegisterCallback function

## Description

Registers a callback function for use by the symbol handler.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `CallbackFunction` [in]

A [SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback) callback function.

### `UserContext` [in]

A user-defined value or **NULL**. This value is simply passed to the callback function. Normally, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some context.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SymRegisterCallback64** function lets an application register a callback function for use by the symbol handler. The symbol handler calls the registered callback function when there is status or progress information for the application.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR. **SymRegisterCallbackW64** is defined as follows in Dbghelp.h.

```cpp
BOOL
IMAGEAPI
SymRegisterCallbackW64(
    __in HANDLE hProcess,
    __in PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction,
    __in ULONG64 UserContext
    );

#ifdef DBGHELP_TRANSLATE_TCHAR
#define SymRegisterCallback64   SymRegisterCallbackW64
#endif
```

This function supersedes the **SymRegisterCallback** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymRegisterCallback** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymRegisterCallback SymRegisterCallback64
#else
BOOL
IMAGEAPI
SymRegisterCallback(
    __in HANDLE hProcess,
    __in PSYMBOL_REGISTERED_CALLBACK CallbackFunction,
    __in_opt PVOID UserContext
    );
#endif
```

For a more extensive example, read [Getting Notifications](https://learn.microsoft.com/windows/desktop/Debug/getting-notifications).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[Getting Notifications](https://learn.microsoft.com/windows/desktop/Debug/getting-notifications)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback)