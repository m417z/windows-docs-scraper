# MINIDUMP_CALLBACK_INPUT structure

## Description

Contains information used by the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function.

## Members

### `ProcessId`

The identifier of the process that contains callback function.

This member is not used if **CallbackType** is **IoStartCallback**.

### `ProcessHandle`

A handle to the process that contains the callback function.

This member is not used if **CallbackType** is **IoStartCallback**.

### `CallbackType`

The type of callback function. This member can be one of the values in the
[MINIDUMP_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_callback_type) enumeration.

### `Status`

If **CallbackType** is **KernelMinidumpStatusCallback**, the union is an **HRESULT** value that indicates the status of the kernel minidump write attempt.

### `Thread`

If **CallbackType** is **ThreadCallback**, the union is a
[MINIDUMP_THREAD_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_callback) structure.

### `ThreadEx`

If **CallbackType** is **ThreadExCallback**, the union is a
[MINIDUMP_THREAD_EX_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_ex_callback) structure.

### `Module`

If **CallbackType** is **ModuleCallback**, the union is a
[MINIDUMP_MODULE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_module_callback) structure.

### `IncludeThread`

If **CallbackType** is **IncludeThreadCallback**, the union is a
[MINIDUMP_INCLUDE_THREAD_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_include_thread_callback) structure.

**DbgHelp 6.2 and earlier:** This member is not available.

### `IncludeModule`

If **CallbackType** is **IncludeModuleCallback**, the union is a
[MINIDUMP_INCLUDE_MODULE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_include_module_callback) structure.

**DbgHelp 6.2 and earlier:** This member is not available.

### `Io`

If **CallbackType** is **IoStartCallback**, **IoWriteAllCallback**, or **IoFinishCallback**, the union is a [MINIDUMP_IO_CALLBACK](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_io_callback) structure.

**DbgHelp 6.4 and earlier:** This member is not available.

### `ReadMemoryFailure`

If **CallbackType** is **ReadMemoryFailureCallback**, the union is a [MINIDUMP_READ_MEMORY_FAILURE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_read_memory_failure_callback) structure.

**DbgHelp 6.4 and earlier:** This member is not available.

### `SecondaryFlags`

Contains a value from the [MINIDUMP_SECONDARY_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_secondary_flags) enumeration type.

**DbgHelp 6.5 and earlier:** This member is not available.

### `VmQuery`

### `VmPreRead`

### `VmPostRead`

## Remarks

If **CallbackType** is **CancelCallback** or **MemoryCallback**, the **ProcessId**, **ProcessHandle**, and **CallbackType** members are valid but no other input is specified.

## See also

[MINIDUMP_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_callback_type)

[MINIDUMP_INCLUDE_MODULE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_include_module_callback)

[MINIDUMP_INCLUDE_THREAD_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_include_thread_callback)

[MINIDUMP_IO_CALLBACK](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_io_callback)

[MINIDUMP_MODULE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_module_callback)

[MINIDUMP_READ_MEMORY_FAILURE_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_read_memory_failure_callback)

[MINIDUMP_THREAD_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_callback)

[MINIDUMP_THREAD_EX_CALLBACK](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_thread_ex_callback)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)