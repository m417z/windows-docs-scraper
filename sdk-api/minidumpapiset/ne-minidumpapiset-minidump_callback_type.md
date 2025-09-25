# MINIDUMP_CALLBACK_TYPE enumeration

## Description

Identifies the type of information returned by the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function. Not all memory
failures will cause a callback; for example if the failure is within a stack then the failure is considered to be
unrecoverable and the minidump will fail.

## Constants

### `ModuleCallback`

The callback function returns module information.

### `ThreadCallback`

The callback function returns thread information.

### `ThreadExCallback`

The callback function returns extended thread information.

### `IncludeThreadCallback`

The callback function indicates which threads are to be included. It is called as the minidump library is
enumerating the threads in a process, rather than after the information gathered, as it is with
**ThreadCallback** or **ThreadExCallback**. It is called for
each thread. If the callback function returns **FALSE**, the current thread is excluded.
This allows the caller to obtain information for a subset of the threads in a process, without suspending
threads that are not of interest. Alternately, you can modify the **ThreadWriteFlags**
member of the [MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output)
structure and return **TRUE** to avoid gathering unnecessary information for the
thread.

### `IncludeModuleCallback`

The callback function indicates which modules are to be included. The callback function is called as the
minidump library is enumerating the modules in a process, rather than after the information is gathered, as it
is with **ModuleCallback**. It is called for each module. If the callback function
returns **FALSE**, the current module is excluded. Alternatively, you can modify the
**ModuleWriteFlags** member of the
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) structure and
return **TRUE** to avoid gathering unnecessary information for the module.

### `MemoryCallback`

The callback function returns a region of memory to be included in the dump. The callback is called only
for dumps generated without the MiniDumpWithFullMemory flag. If the callback function returns
**FALSE** or a region of size 0, the callback will not be called again.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `CancelCallback`

The callback function returns cancellation information.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `WriteKernelMinidumpCallback`

The user-mode minidump has been successfully completed. To initiate a kernel-mode minidump, the callback
should return **TRUE** and set the **Handle** member of the
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) structure.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `KernelMinidumpStatusCallback`

The callback function returns status information for the kernel minidump.

**DbgHelp 6.1 and earlier:** This value is not supported.

### `RemoveMemoryCallback`

The callback function returns a region of memory to be excluded from the dump. The callback is called only
for dumps generated without the **MiniDumpWithFullMemory** flag. If the callback
function returns **FALSE** or a region of size 0, the callback will not be called again.

**DbgHelp 6.3 and earlier:** This value is not supported.

### `IncludeVmRegionCallback`

The callback function returns information about the virtual memory region. It is called twice for each
region during the full-memory writing pass. The **VmRegion** member of the
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) structure
contains the current memory region. You can modify the base address and size of the region, as long as the new
region remains a subset of the original region; changes to other members are ignored. If the callback returns
**TRUE** and sets the **Continue** member of
**MINIDUMP_CALLBACK_OUTPUT** to
**TRUE**, the minidump library will use the region specified by
**VmRegion** as the region to be written. If the callback returns
**FALSE** or if **Continue** is **FALSE**,
the callback will not be called for additional memory regions.

**DbgHelp 6.4 and earlier:** This value is not supported.

### `IoStartCallback`

The callback function indicates that the caller will be providing an alternate I/O routine. If the callback
returns **TRUE** and sets the **Status** member of
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) to
**S_FALSE**, the minidump library will send all I/O through callbacks. The caller will
receive an **IoWriteAllCallback** callback for each piece of data.

**DbgHelp 6.4 and earlier:** This value is not supported.

### `IoWriteAllCallback`

The callback must write all requested bytes or fail. The **Io** member of the
[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input) structure contains
the request. If the write operation fails, the callback should return **FALSE**. If the
write operation succeeds, the callback should return **TRUE** and set the
**Status** member of
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) to
**S_OK**. The caller will receive an **IoFinishCallback** callback
when the I/O has completed.

**DbgHelp 6.4 and earlier:** This value is not supported.

### `IoFinishCallback`

The callback returns I/O completion information. If the callback returns **FALSE** or
does not set the **Status** member of
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) to
**S_OK**, the minidump library assumes the minidump write operation has failed.

**DbgHelp 6.4 and earlier:** This value is not supported.

### `ReadMemoryFailureCallback`

There has been a failure to read memory. If the callback returns **TRUE** and sets
the **Status** member of
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) to
**S_OK**, the memory failure is ignored and the block is omitted from the minidump. Otherwise, this
failure results in a failure to write to the minidump.

**DbgHelp 6.4 and earlier:** This value is not supported.

### `SecondaryFlagsCallback`

The callback returns secondary information.

**DbgHelp 6.5 and earlier:** This value is not supported.

### `IsProcessSnapshotCallback`

The callback function indicates whether the target is a process or a snapshot.

**DbgHelp 6.2 and earlier:** This value is not supported.

### `VmStartCallback`

The callback function indicates whether the callee supports and accepts virtual memory callbacks, such as **VmQueryCallback**, **VmPreReadCallback**, and **VmPostReadCallback**.
A return value of S_FALSE means that virtual memory callbacks are supported. A value of S_OK means that virtual memory callbacks are not supported.

**DbgHelp 6.2 and earlier:** This value is not supported.

### `VmQueryCallback`

The callback function is invoked for snapshot targets to collect virtual address memory information from the target.
The callback is only called if **VmStartCallback** returned a value of S_FALSE.

**DbgHelp 6.2 and earlier:** This value is not supported.

### `VmPreReadCallback`

The callback function is sent for every ReadVirtual operation. These reads are not limited to the memory blocks that are added to the dump. The engine also accesses the Process Environment Block (PEB), the Thread Environment Block (TEB), the loader data, the unloaded module traces, and other blocks. Even if those blocks do not end up in the dump, they are read from the target, and virtual memory callbacks are initiated for each. The callback is only called if **VmStartCallback** returned S_FALSE.

**DbgHelp 6.2 and earlier:** This value is not supported.

### `VmPostReadCallback`

The callback function allows the callee to alter the buffer contents with data from other sources, such as a cache, or perform obfuscation. The buffer at this point is fully or partially filled by **VmPreReadCallback** and by **ReadProcessMemory**. The callback is only called if **VmStartCallback** returned S_FALSE.

**DbgHelp 6.2 and earlier:** This value is not supported.

## See also

[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)