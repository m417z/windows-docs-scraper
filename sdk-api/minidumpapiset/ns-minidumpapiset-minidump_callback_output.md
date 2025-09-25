# MINIDUMP_CALLBACK_OUTPUT structure

## Description

Contains information returned by the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function.

## Members

### `ModuleWriteFlags`

The module write operation flags. This member can be one or more of the values in the
[MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-module_write_flags) enumeration. The flags are set to their default values on entry to the callback.

This member is ignored unless the callback type is **IncludeModuleCallback** or **ModuleCallback**.

### `ThreadWriteFlags`

The thread write operation flags. This member can be one or more of the values in the
[THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-thread_write_flags) enumeration. The flags are set to their default values on entry to the callback.

This member is ignored unless the callback type is **IncludeThreadCallback**, **ThreadCallback**, or **ThreadExCallback**.

### `SecondaryFlags`

Contains a value from the [MINIDUMP_SECONDARY_FLAGS](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_secondary_flags) enumeration type.

**DbgHelp 6.5 and earlier:** This member is not available.

### `MemoryBase`

The base address of the memory region to be included in the dump.

This member is ignored unless the callback type is **MemoryCallback** or **RemoveMemoryCallback**.

### `MemorySize`

The size of the memory region to be included in the dump, in bytes.

This member is ignored unless the callback type is **MemoryCallback** or **RemoveMemoryCallback**.

### `CheckCancel`

Controls whether the callback function should receive cancel callbacks. If this member is **TRUE**, the cancel callbacks will continue. Otherwise, they will not.

This member is ignored unless the callback type is **CancelCallback**.

### `Cancel`

Controls whether the dump should be canceled. If the callback function returns **TRUE** and **Cancel** is **TRUE**, the dump will be canceled. In this case, the [MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function fails and the dump is not valid.

This member is ignored unless the callback type is **CancelCallback**.

### `Handle`

A handle to the file to which a kernel minidump will be written.

This member is ignored unless the callback type is **WriteKernelMinidumpCallback**.

### `VmRegion`

A [MINIDUMP_MEMORY_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_memory_info) structure that describes the virtual memory region. The region base and size must be aligned on a page boundary. The region size can be set to 0 to filter out the region.

This member is ignored unless the callback type is **IncludeVmRegionCallback**.

### `Continue`

Controls whether the dump should be continued. If the callback function returns **TRUE** and **Continue** is **TRUE**, the dump will be continued. Otherwise, the [MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function fails and the dump is not valid.

This member is ignored unless the callback type is **IncludeVmRegionCallback**.

### `VmQueryStatus`

### `VmQueryResult`

### `VmReadStatus`

### `VmReadBytesCompleted`

### `Status`

The status of the operation.

This member is ignored unless the callback type is **ReadMemoryFailureCallback**, **IoStartCallback**, **IoWriteAllCallback**, or **IoFinishCallback**.

## See also

[MODULE_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-module_write_flags)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)

[THREAD_WRITE_FLAGS](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-thread_write_flags)