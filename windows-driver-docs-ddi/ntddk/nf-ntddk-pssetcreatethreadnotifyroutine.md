## Description

The **PsSetCreateThreadNotifyRoutine** routine registers a driver-supplied callback that is subsequently notified when a new thread is created and when such a thread is deleted.

## Parameters

### `NotifyRoutine` [in]

A pointer to the driver's implementation of [PCREATE_THREAD_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_thread_notify_routine) routine.

## Return value

**PsSetCreateThreadNotifyRoutine** either returns STATUS_SUCCESS or it returns STATUS_INSUFFICIENT_RESOURCES if it failed the callback registration.

## Remarks

Highest-level drivers can call **PsSetCreateThreadNotifyRoutine** to set up their thread-creation notify routines, declared as follows:

```cpp
VOID
(*PCREATE_THREAD_NOTIFY_ROUTINE) (
    IN HANDLE  ProcessId,
    IN HANDLE  ThreadId,
    IN BOOLEAN  Create
    );
```

For example, an IFS or highest-level system-profiling driver might register such a thread-creation callback to track the system-wide creation and deletion of threads against the driver's internal state.

A driver must remove any callbacks it registers before it unloads. You can remove the callback by calling the [PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine) routine.

## See also

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsGetCurrentThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthreadid)

[PsIsSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psissystemthread)

[PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)