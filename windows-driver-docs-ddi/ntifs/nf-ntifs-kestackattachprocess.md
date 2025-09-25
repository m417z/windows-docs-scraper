# KeStackAttachProcess function

## Description

The **KeStackAttachProcess** routine attaches the current thread to the address space of the target process.

**Caution** Use this routine with extreme caution. (See the note in the Remarks section.)

## Parameters

### `PROCESS`

Pointer to the target process object. This parameter can be a PEPROCESS pointer returned by [IoGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess) or [PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess).

### `ApcState` [out]

An opaque pointer to a KAPC_STATE structure. The caller must allocate storage for this structure either from nonpaged pool or from the caller's own thread stack.

## Remarks

**KeStackAttachProcess** attaches the current thread to the address space of the process pointed to by the *Process* parameter. If the current thread was already attached to another process, the *ApcState* parameter receives the current APC state before **KeStackAttachProcess** attaches to the new process.

Every call to **KeStackAttachProcess** must be matched by a subsequent call to [KeUnstackDetachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keunstackdetachprocess).

**Note**
Attaching a thread to a different process can prevent asynchronous I/O operations from completing and can potentially cause deadlocks. In general, the lines of code between the call to
**KeStackAttachProcess**
and the call to
[KeUnstackDetachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keunstackdetachprocess)
should be very simple and should not call complex routines or send IRPs to other drivers.

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Windows Kernel-Mode Process and Thread Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager).

## See also

[IoGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[IoGetRequestorProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetrequestorprocess)

[IoThreadToProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iothreadtoprocess)

[KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[KeUnstackDetachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keunstackdetachprocess)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)