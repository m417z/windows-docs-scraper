# PSYMBOL_FUNCENTRY_CALLBACK callback function

## Description

An application-defined callback function used with the
[SymRegisterFunctionEntryCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregisterfunctionentrycallback) function. It is called by the stack walking procedure.

The **PSYMBOL_FUNCENTRY_CALLBACK64** type defines a pointer to this callback function.
**SymRegisterFunctionEntryCallbackProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function.

### `AddrBase` [in]

The address of an instruction for which the callback function should return a function table entry.

### `UserContext` [in, optional]

The user-defined value specified in
[SymRegisterFunctionEntryCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregisterfunctionentrycallback), or **NULL**. Typically, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some context.

## Return value

Return the value **NULL** if no function table entry is available.

On success, return a pointer to an **IMAGE_RUNTIME_FUNCTION_ENTRY** structure. Refer to the header file WinNT.h for the definition of this function.

## Remarks

The structure must be returned in exactly the form it exists in the process being debugged. Some members may be pointers to other locations in the process address space. The
[ReadProcessMemoryProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pread_process_memory_routine) callback function may be called to retrieve the information at these locations.

The calling application gets called through the registered callback function as a result of a call to the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function. The calling application must be prepared for the possible side effects that this can cause. If the application has only one callback function that is being used by multiple threads, then it may be necessary to synchronize some types of data access while in the context of the callback function.

This function is similar to the
[FunctionTableAccessProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfunction_table_access_routine) callback function. The difference is that
**FunctionTableAccessProc64** returns an
[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry) structure, while this function returns an **IMAGE_RUNTIME_FUNCTION_ENTRY** structure.

This callback function supersedes the *PSYMBOL_FUNCENTRY_CALLBACK* callback function. *PSYMBOL_FUNCENTRY_CALLBACK* is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PSYMBOL_FUNCENTRY_CALLBACK PSYMBOL_FUNCENTRY_CALLBACK64
#endif

typedef
PVOID
(CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK)(
    __in HANDLE hProcess,
    __in DWORD AddrBase,
    __in_opt PVOID UserContext
    );
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymRegisterFunctionEntryCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregisterfunctionentrycallback)