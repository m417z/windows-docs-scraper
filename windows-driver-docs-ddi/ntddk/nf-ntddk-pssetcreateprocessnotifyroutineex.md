# PsSetCreateProcessNotifyRoutineEx function

## Description

The **PsSetCreateProcessNotifyRoutineEx** routine registers or removes a callback routine that notifies the caller when a process is created or exits.

## Parameters

### `NotifyRoutine` [in]

A pointer to the [PCREATE_PROCESS_NOTIFY_ROUTINE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex) routine to register or remove. The operating system calls this routine whenever a new process is created.

### `Remove` [in]

A Boolean value that specifies whether **PsSetCreateProcessNotifyRoutineEx** will add or remove a specified routine from the list of callback routines. If this parameter is **TRUE**, the specified routine is removed from the list of callback routines. If this parameter is **FALSE**, the specified routine is added to the list of callback routines. If *Remove* is **TRUE**, the system also waits for all in-flight callback routines to complete before returning.

## Return value

**PsSetCreateProcessNotifyRoutineEx** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The specified routine is now registered with the operating system. The operating system calls this routine whenever a new process is created. |
| **STATUS_INVALID_PARAMETER** | The specified routine was already registered, or the operating system has reached its limit for registering process-creation callback routines. |
| **STATUS_ACCESS_DENIED** | The image that contains the callback routine pointer did not have IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY set in its image header. |

## Remarks

Highest-level drivers can call **PsSetCreateProcessNotifyRoutineEx** to register a [PCREATE_PROCESS_NOTIFY_ROUTINE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex) routine. An installable file system (IFS) or highest-level system-profiling driver might register a process-creation callback routine to track which processes are created and deleted against the driver's internal state across the system.

A driver must remove any callback routines that it registers before it unloads. You can remove the callback routine by calling **PsSetCreateProcessNotifyRoutineEx** with *Remove* set to **TRUE**. A driver must not make this call from its implementation of the [*PCREATE_PROCESS_NOTIFY_ROUTINE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex) callback routine.

The operating system calls the driver's process-notify routine at PASSIVE_LEVEL inside a critical region with [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) disabled. When a process is created, the process-notify routine runs in the context of the thread that created the new process. When a process is deleted, the process-notify routine runs in the context of the last thread to exit from the process.

## See also

[PCREATE_PROCESS_NOTIFY_ROUTINE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pcreate_process_notify_routine_ex)

[PS_CREATE_NOTIFY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_ps_create_notify_info)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)