# PsLookupProcessByProcessId function

## Description

The **PsLookupProcessByProcessId** routine accepts the process ID of a process and returns a referenced pointer to EPROCESS structure of the process.

## Parameters

### `ProcessId` [in]

Specifies the process ID of the process.

### `Process` [out]

Returns a referenced pointer to the EPROCESS structure of process specified by *ProcessId*.

## Return value

**PsLookupProcessByProcessId** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Specifies in Windows XP and earlier versions of Windows the process ID was not found. |
| **STATUS_INVALID_CID** | Specifies in Windows Vista and later versions of Windows the specified client ID is not valid. |

## Remarks

This routine is available on Windows 2000 and later versions.

If the call to **PsLookupProcessByProcessId** is successful, **PsLookupProcessByProcessID** increases the reference count on the object returned in the *Process* parameter. Consequently, when a driver has completed using the *Process* parameter, the driver must call [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) to dereference the *Process* parameter received from the **PsLookupProcessByProcessID** routine.

The EPROCESS structure is an opaque data structure used internally by the operating system. This structure can be passed to other routines to access specific information in this structure.

A file system filter driver can enumerate active processes and then call **PsLookupProcessByProcessId** to convert a process ID to an EPROCESS structure. The process ID is available in the process create routine. A file system filter driver can set a process notification callback routine using [PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine). In the notification callback routine, the file system filter driver can use the passed in *ProcessId* parameter and call **PsLookupProcessByProcessID** to locate the EPROCESS structure. The [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine) can also be used to set a notification routine that returns the process ID when a thread ID is created.

The **PsLookupProcessByProcessId** routine contains pageable code.

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[PsGetCurrentThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthreadid)

[PsLookupThreadByThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pslookupthreadbythreadid)

[PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine)

[PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)