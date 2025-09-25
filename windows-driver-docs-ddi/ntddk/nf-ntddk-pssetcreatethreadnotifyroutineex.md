# PsSetCreateThreadNotifyRoutineEx function

## Description

The **PsSetCreateThreadNotifyRoutineEx** routine registers a driver-supplied callback that is subsequently notified when a new thread is created and when such a thread is deleted.

## Parameters

### `NotifyType` [in]

A [PSCREATETHREADNOTIFYTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_pscreatethreadnotifytype) value that indicates the type of thread notification.

### `NotifyInformation` [in]

Provides the address of the notification information for the specified type of thread notification.
If **NotifyType** is **PsCreateThreadNotifyNonSystem** or **PsCreateThreadNotifySubsystems** then **NotifyInformation** should be a pointer to the driver's implementation of [PCREATE_THREAD_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_thread_notify_routine).

## Return value

**PsSetCreateThreadNotifyRoutineEx** either returns STATUS_SUCCESS or it returns STATUS_INSUFFICIENT_RESOURCES if it failed the callback registration.

## Remarks

Highest-level drivers can call **PsSetCreateThreadNotifyRoutineEx** to set up their thread-creation notify routines.

For example, an IFS or highest-level system-profiling driver might register such a thread-creation callback to track the system-wide creation and deletion of threads against the driver's internal state.

If *NotifyType* is **PsCreateThreadNotifyNonSystem**, the **PsSetCreateThreadNotifyRoutineEx** routine differs from [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine) in the context in which the callback is executed. With **PsSetCreateThreadNotifyRoutine**, the callback is executed on the creator thread. With **PsSetCreateThreadNotifyRoutineEx**, the callback is executed on the newly created thread.

A driver must remove any callback function it registers before it unloads. You can remove the callback by calling the [PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine) routine.

## See also

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsGetCurrentThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthreadid)

[PsIsSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psissystemthread)

[PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)