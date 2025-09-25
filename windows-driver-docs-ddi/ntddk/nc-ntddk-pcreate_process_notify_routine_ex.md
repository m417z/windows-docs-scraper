# PCREATE_PROCESS_NOTIFY_ROUTINE_EX callback function

## Description

A callback routine implemented by a driver to notify the caller when a process is created or exits.

> [!WARNING]
> The actions that you can perform in this routine are restricted for safe calls. See [Best Practices](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager#best).

## Parameters

### `Process` [_Inout_]

A pointer to the EPROCESS structure that represents the process. Drivers can use the [**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess) and [**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) routines to obtain a pointer to the EPROCESS structure for a process.

### `ProcessId` [in]

The process ID of the process.

### `CreateInfo` [in, out, optional]

A pointer to a [PS_CREATE_NOTIFY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_ps_create_notify_info) structure that contains information about the new process. If this parameter is NULL, the specified process is exiting.

## Remarks

Highest-level drivers call [PsSetCreateProcessNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex) to register their implementation of *PCREATE_PROCESS_NOTIFY_ROUTINE_EX* routine. An installable file system (IFS) or highest-level system-profiling driver might register a process-creation callback routine to track which processes are created and deleted against the driver's internal state across the system.

## See also

[PsSetCreateProcessNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex)

[PsSetCreateProcessNotifyRoutineEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex2)