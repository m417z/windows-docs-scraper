# PsSetCreateProcessNotifyRoutineEx2 function

## Description

The **PsSetCreateProcessNotifyRoutineEx2** routine registers or removes a callback routine that notifies the caller when a process is created or deleted.

## Parameters

### `NotifyType` [in]

A [PSCREATEPROCESSNOTIFYTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_pscreateprocessnotifytype)-type value that indicates the type of process notification.

### `NotifyInformation` [in]

The address of the notification information for the specified type of process notification. If *NotifyType* is **PsCreateProcessNotifySubsystems**, *NotifyInformation* is a [PCREATE_PROCESS_NOTIFY_ROUTINE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex) that specifies the entry point of the caller-supplied process-creation callback.

### `Remove` [in]

A Boolean value that specifies whether **PsSetCreateProcessNotifyRoutineEx2** will add or remove a specified routine from the list of callback routines. If this parameter is **TRUE**, the specified routine is removed from the list of callback routines. If this parameter is **FALSE**, the specified routine is added to the list of callback routines. If *Remove* is **TRUE**, the system also waits for all in-flight callback routines to complete before returning.

## Return value

**PsSetCreateProcessNotifyRoutineEx2** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The specified routine is now registered with the operating system. The operating system calls this routine whenever a new process is created. |
| **STATUS_INVALID_PARAMETER** | The specified routine was already registered, or the operating system has reached its limit for registering process-creation callback routines.<br><br> *NotifyType* is not **PsCreateProcessNotifySubsystems**. |
| **STATUS_ACCESS_DENIED** | The image that contains the callback routine pointer did not have IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY set in its image header. |

## Remarks

Drivers can call **PsSetCreateProcessNotifyRoutineEx2** to register their process-creation notify routines.

After a driver-supplied routine is registered, it is called with the unique ID (indicated by *ProcessId*)
of the created or deleted process. The *ParentId* identifies the parent process of the new process (this is the parent used for priority, affinity, quota, token, and handle inheritance, among others) if it was
created with the inherit handles option. If it was created without
the inherit handle options, then the parent process ID is NULL.

If the *Create* value is TRUE, the subsystem process
was created; FALSE indicates the process was deleted.

When the process is created, the callback function is invoked just after the first thread in the
process has been created. Conversely, for deletion, the function is invoked after the
last thread in the process has terminated and the address space is about
to be deleted. It is possible that the callback is only invoked for deletion without getting a creation
call in cases where the process was created and deleted
without a thread ever being created.

A driver must remove any callback function that it registers before it unloads. You can remove the callback by calling **PsSetCreateProcessNotifyRoutineEx2** with *Remove* = **TRUE**.

## See also

[PCREATE_PROCESS_NOTIFY_ROUTINE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetCreateProcessNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex)