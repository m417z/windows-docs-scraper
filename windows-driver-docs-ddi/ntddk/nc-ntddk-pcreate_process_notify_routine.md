# PCREATE_PROCESS_NOTIFY_ROUTINE callback function

## Description

Process-creation callback implemented by a driver to track the system-wide creation and deletion of processes against the driver's internal state.

> [!WARNING]
> The actions that you can perform in this routine are restricted for safe calls. See [Best Practices](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager#best).

## Parameters

### `ParentId` [in]

The process ID of the parent process.

### `ProcessId` [in]

The process ID of the process.

### `Create` [in]

Indicates whether the process was created (**TRUE**) or deleted (**FALSE**).

## Remarks

Highest-level drivers call **PsSetCreateProcessNotifyRoutine** to register their process-creation notify routines.

A driver's process-notify routine is also called with *Create* set to **FALSE**, typically when the last thread within a process has terminated and the process address space is about to be deleted.

 The operating system calls the driver's process-notify routine at PASSIVE_LEVEL inside a critical region with [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) disabled. When a process is created, the process-notify routine runs in the context of the thread that created the new process. When a process is deleted, the process-notify routine runs in the context of the last thread to exit from the process.

## See also

**PsSetCreateProcessNotifyRoutine**