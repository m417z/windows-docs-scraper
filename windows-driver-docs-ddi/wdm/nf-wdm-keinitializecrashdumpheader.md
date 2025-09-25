# KeInitializeCrashDumpHeader function (wdm.h)

## Description

The **KeInitializeCrashDumpHeader** routine supplies the header information the system requires for a crash dump file.

## Parameters

### `DumpType` [in]

Specifies the type of dump file. The only valid value is DUMP_TYPE_FULL.

### `Flags` [in]

Specifies flags for the dump file. The only valid value is 0.

### `Buffer` [out]

Pointer to the buffer that receives the header information.

### `BufferSize` [in]

Specifies the size in bytes of the buffer pointed to by *Buffer*.

### `BufferNeeded` [out, optional]

Optionally, a pointer to a variable that receives the size necessary to hold the complete header information.

## Return value

**KeInitializeCrashDumpHeader** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

Drivers can use this routine to manually create a crash dump file. The file can be created at any time, and used by a debugger to examine the state of the system.

To create a crash-dump file, call **KeInitializeCrashDumpHeader** to create the header, then append the contents of memory to the header. Note that the driver is not required to record the contents of memory immediately after calling the routine: the header can normally be created at any time before the crash-dump file is written.

Because the routine is designed to be called well before the memory contents are recorded, it has the following limitations:

* The routine does not record any information about active exception records.
* If the size of system RAM changes, the header must be recreated.

The routine does not record any secondary dump data.

Starting with Windows 8, **KeInitializeCrashDumpHeader** always writes the base address of the system process page directory to the crash-dump header, regardless of the process context from which **KeInitializeCrashDumpHeader** is called. The debugger can use this directory to access the crash-dump file in the context of the system process.

In earlier versions of Windows, **KeInitializeCrashDumpHeader** writes the base address of the page directory of the caller's current process context to the crash-dump header. Thus, **KeInitializeCrashDumpHeader** must be called from the system process. Otherwise, the debugger will be unable to access the crash-dump file in the process context in which the file was saved.

Starting with Windows 8, **KeInitializeCrashDumpHeader** is declared in the Wdm.h header file in the Windows Driver Kit (WDK). To use this routine with earlier versions of the WDK, include the following function declaration in your driver code:

```cpp
NTSTATUS
  KeInitializeCrashDumpHeader(
    __in ULONG  DumpType,
    __in ULONG  Flags,
    __out PVOID  Buffer,
    __in ULONG  BufferSize,
    __out_opt PULONG  BufferNeeded
    );
```