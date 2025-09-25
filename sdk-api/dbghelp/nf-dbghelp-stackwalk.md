# StackWalk function

## Description

Obtains a stack trace.

## Parameters

### `MachineType` [in]

The architecture type of the computer for which the stack trace is generated. This parameter can be one of
the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_FILE_MACHINE_I386**<br><br>0x014c | Intel x86 |
| **IMAGE_FILE_MACHINE_IA64**<br><br>0x0200 | Intel Itanium |
| **IMAGE_FILE_MACHINE_AMD64**<br><br>0x8664 | x64 (AMD64 or EM64T) |

### `hProcess` [in]

A handle to the process for which the stack trace is generated. If the caller supplies a valid callback
pointer for the *ReadMemoryRoutine* parameter, then this value does not have to be a
valid process handle. It can be a token that is unique and consistently the same for all calls to the
**StackWalk64** function. If the symbol handler is used with
**StackWalk64**, use the same process handles for the calls
to each function.

### `hThread` [in]

A handle to the thread for which the stack trace is generated. If the caller supplies a valid callback
pointer for the *ReadMemoryRoutine* parameter, then this value does not have to be a
valid thread handle. It can be a token that is unique and consistently the same for all calls to the
**StackWalk64** function.

### `StackFrame` [in, out]

A pointer to a [STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe) structure. This
structure receives information for the next frame, if the function call succeeds.

### `ContextRecord` [in, out]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure. This parameter is
required only when the *MachineType* parameter is not
**IMAGE_FILE_MACHINE_I386**. However, it is recommended that this parameter contain a
valid context record. This allows **StackWalk64** to handle
a greater variety of situations.

This context may be modified, so do not pass a context record that should not be modified.

### `ReadMemoryRoutine` [in, optional]

A callback routine that provides memory read services. When the
**StackWalk64** function needs to read memory from the
process's address space, the
[ReadProcessMemoryProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pread_process_memory_routine) callback is
used.

If this parameter is **NULL**, then the function uses a default routine. In this case,
the *hProcess* parameter must be a valid process handle.

If this parameter is not
**NULL**, the application should implement and register a symbol handler callback
function that handles **CBA_READ_MEMORY**.

### `FunctionTableAccessRoutine` [in, optional]

A callback routine that provides access to the run-time function table for the process. This parameter is
required because the **StackWalk64** function does not have
access to the process's run-time function table. For more information, see
[FunctionTableAccessProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfunction_table_access_routine).

The symbol handler provides functions that load and access the run-time table. If these functions are used,
then [SymFunctionTableAccess64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfunctiontableaccess) can be
passed as a valid parameter.

### `GetModuleBaseRoutine` [in, optional]

A callback routine that provides a module base for any given virtual address. This parameter is required. For
more information, see [GetModuleBaseProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pget_module_base_routine).

The symbol handler provides functions that load and maintain module information. If these functions are used,
then [SymGetModuleBase64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmodulebase) can be passed as a valid
parameter.

### `TranslateAddress` [in, optional]

A callback routine that provides address translation for 16-bit addresses. For more information, see
[TranslateAddressProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-ptranslate_address_routine).

Most callers of **StackWalk64** can safely pass
**NULL** for this parameter.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. Note that
**StackWalk64** generally does not set the last error
code.

## Remarks

The **StackWalk64** function provides a portable method
for obtaining a stack trace. Using the **StackWalk64**
function is recommended over writing your own function because of all the complexities associated with stack
walking on platforms. In addition, there are compiler options that cause the stack to appear differently,
depending on how the module is compiled. By using this function, your application has a portable stack trace that
continues to work as the compiler and operating system change.

The first call to this function will fail if the **AddrPC**,
**AddrFrame**, and **AddrStack** members of the
[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe) structure passed in the
*StackFrame* parameter are not initialized.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

This function supersedes the **StackWalk** function. For
more information, see [Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support).
**StackWalk** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define StackWalk StackWalk64
#else
BOOL
IMAGEAPI
StackWalk(
    DWORD MachineType,
    __in HANDLE hProcess,
    __in HANDLE hThread,
    __inout LPSTACKFRAME StackFrame,
    __inout PVOID ContextRecord,
    __in_opt PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine,
    __in_opt PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,
    __in_opt PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine,
    __in_opt PTRANSLATE_ADDRESS_ROUTINE TranslateAddress
    );

#endif
```

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FunctionTableAccessProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfunction_table_access_routine)

[GetModuleBaseProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pget_module_base_routine)

[ReadProcessMemoryProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pread_process_memory_routine)

[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe)

[TranslateAddressProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-ptranslate_address_routine)