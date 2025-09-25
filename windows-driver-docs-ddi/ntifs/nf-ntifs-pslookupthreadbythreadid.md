# PsLookupThreadByThreadId function

## Description

The **PsLookupThreadByThreadId** routine accepts the thread ID of a thread and returns a referenced pointer to the ETHREAD structure of the thread.

## Parameters

### `ThreadId` [in]

Specifies the thread ID of the thread.

### `Thread` [out]

Returns a referenced pointer to the ETHREAD structure of thread specified by the *ThreadId*.

## Return value

**PsLookupThreadByThreadId** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The thread ID was not found. |

## Remarks

This routine is available on Windows 2000 and later versions.

If the call to **PsLookupThreadByThreadId** is successful, **PsLookupThreadByThreadId** increases the reference count on the object returned in the *Thread* parameter. Consequently, when a driver has completed using the *Thread* parameter, the driver must call [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) to dereference the *Thread* parameter received from the **PsLookupThreadByThreadId** routine.

The ETHREAD structure is an opaque data structure used internally by the operating system. This structure can be passed to other routines to access specific information in this structure.

A file system filter driver can enumerate active threads by calling **PsLookupThreadByThreadId** to convert a thread ID to an ETHREAD structure. The thread ID is available in the thread create routine. A file system filter driver can set a thread notification callback routine using [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine). In the notification callback routine, the file system filter driver can use the passed in *ThreadId* parameter and call **PsLookupThreadByThreadId** to locate the ETHREAD structure.

The **PsLookupThreadByThreadId** routine contains pageable code.

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[PsGetCurrentThreadId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthreadid)

[PsLookupProcessByProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pslookupprocessbyprocessid)

[PsRemoveCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremovecreatethreadnotifyroutine)

[PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine)

[PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)