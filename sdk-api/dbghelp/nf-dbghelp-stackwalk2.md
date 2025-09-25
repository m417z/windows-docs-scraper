# StackWalk2 function

## Description

Obtains a stack trace.

## Parameters

### `MachineType` [in]

The architecture type of the computer for which the stack trace is generated. This parameter can be one of the following values.

| Value | Meaning |
|----------------------------|------------------|
| **IMAGE_FILE_MACHINE_I386**<br>0x014c | Intel x86 |
| **IMAGE_FILE_MACHINE_IA64**<br>0x0200 | Intel Itanium |
| **IMAGE_FILE_MACHINE_AMD64**<br>0x8664 | x64 (AMD64 or EM64T) |
| **IMAGE_FILE_MACHINE_ARM64**<br>0xaa64 | ARM64 |

### `hProcess` [in]

A handle to the process for which the stack trace is generated. If the caller supplies a valid callback pointer for the *ReadMemoryRoutine* parameter, then this value does not have to be a valid process handle. It can be a token that is unique and consistently the same for all calls to the **StackWalk2** function. If the symbol handler is used with **StackWalk2**, use the same process handles for the calls to each function.

### `hThread` [in]

A handle to the thread for which the stack trace is generated. If the caller supplies a valid callback pointer for the *ReadMemoryRoutine* parameter, then this value does not have to be a valid thread handle. It can be a token that is unique and consistently the same for all calls to the **StackWalk2** function.

### `StackFrame` [in, out]

A pointer to a [STACKFRAME_EX structure](https://learn.microsoft.com/windows/win32/api/dbghelp/ns-dbghelp-stackframe_ex). This structure receives information for the next frame, if the function call succeeds.

### `ContextRecord` [in, out]

A pointer to an [ARM64_NT_CONTEXT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context). This parameter is required only when the *MachineType* parameter is not **IMAGE_FILE_MACHINE_I386**. However, it is recommended that this parameter contain a valid context record. This allows **StackWalk2** to handle a greater variety of situations.

This context may be modified, so do not pass a context record that should not be modified.

### `ReadMemoryRoutine` [in, optional]

A callback routine that provides memory read services. When the **StackWalk2** function needs to read memory from the process's address space, the [ReadProcessMemoryProc64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pread_process_memory_routine64) is used.

If this parameter is **NULL**, then the function uses a default routine. In this case, the *hProcess* parameter must be a valid process handle.

If this parameter is not **NULL**, the application should implement and register a symbol handler callback function that handles **CBA_READ_MEMORY**.

### `FunctionTableAccessRoutine` [in, optional]

A callback routine that provides access to the run-time function table for the process. This parameter is required because the **StackWalk2** function does not have access to the process's run-time function table. For more information, see [FunctionTableAccessProc64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pfunction_table_access_routine64).

The symbol handler provides functions that load and access the run-time table. If these functions are used, then the [SymFunctionTableAccess64 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-symfunctiontableaccess64) can be passed as a valid parameter.

### `GetModuleBaseRoutine` [in, optional]

A callback routine that provides a module base for any given virtual address. This parameter is required. For more information, see [PGET_MODULE_BASE_ROUTINE64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pget_module_base_routine64).

The symbol handler provides functions that load and maintain module information. If these functions are used, then the [SymGetModuleBase64 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-symgetmodulebase64) can be passed as a valid parameter.

### `TranslateAddress` [in, optional]

A callback routine that provides address translation for 16-bit addresses. For more information, see [PTRANSLATE_ADDRESS_ROUTINE64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-ptranslate_address_routine64).

Most callers of **StackWalk2** can safely pass **NULL** for this parameter.

### `GetTargetAttributeValue` [in, optional]

A callback routine that provides the values of target attributes required to walk the stack. For more information, see [PGET_TARGET_ATTRIBUTE_VALUE64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pget_target_attribute_value64).

Many callers of **StackWalk2** can safely pass **NULL** for this parameter. Callers on ARM64 platforms which may utilize pointer authentication should provide a callback.

### `Flags` [in]

A combination of zero or more flags.

#### SYM_STKWALK_DEFAULT (0)

#### SYM_STKWALK_FORCE_FRAMEPTR (1)

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. Note that **StackWalk2** generally does not set the last error code.

## Remarks

The **StackWalk2** function provides a portable method for obtaining a stack trace. Using the **StackWalk2** function is recommended over writing your own function because of all the complexities associated with stack walking on platforms. In addition, there are compiler options that cause the stack to appear differently, depending on how the module is compiled. By using this function, your application has a portable stack trace that continues to work as the compiler and operating system change.

The first call to this function will fail if the **AddrPC**, **AddrFrame**, and **AddrStack** members of the [STACKFRAME64 structure](https://learn.microsoft.com/windows/win32/api/dbghelp/ns-dbghelp-stackframe64) passed in the *StackFrame* parameter are not initialized.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ARM64_NT_CONTEXT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context)

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FunctionTableAccessProc64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pfunction_table_access_routine64)

[ReadProcessMemoryProc64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pread_process_memory_routine64)

[STACKFRAME_EX structure](https://learn.microsoft.com/windows/win32/api/dbghelp/ns-dbghelp-stackframe_ex)

[SymFunctionTableAccess64 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-symfunctiontableaccess64)

[SymGetModuleBase64 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-symgetmodulebase64)

[PTRANSLATE_ADDRESS_ROUTINE64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-ptranslate_address_routine64)

[PGET_TARGET_ATTRIBUTE_VALUE64 callback function](https://learn.microsoft.com/windows/win32/api/dbghelp/nc-dbghelp-pget_target_attribute_value64)