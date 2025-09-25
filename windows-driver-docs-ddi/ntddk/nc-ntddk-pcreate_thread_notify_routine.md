# PCREATE_THREAD_NOTIFY_ROUTINE callback function

## Description

A callback routine implemented by a driver to notify the caller when a thread is created or deleted.

> [!WARNING]
> The actions that you can perform in this routine are restricted for safe calls. See [Best Practices](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager#best).
## Parameters

### `ProcessId` [in]

The process ID of the process.

### `ThreadId` [in]

The thread ID of the thread.

### `Create` [in]

Indicates whether the thread was created (**TRUE**) or deleted (**FALSE**).

## Remarks

Highest-level drivers can call [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine) or [PsSetCreateThreadNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutineex) to register their thread-creation notify routine.

The driver's thread-notify routine runs at IRQL = PASSIVE_LEVEL or APC_LEVEL. When a thread is created, the thread-notify routine runs in the context of the thread that created the new thread. When a thread is deleted, the thread-notify routine runs in the context of this thread when the thread exits.

## See also

[PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)

[PsSetCreateThreadNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutineex)