# KeUnstackDetachProcess function

## Description

The **KeUnstackDetachProcess** routine detaches the current thread from the address space of a process and restores the previous attach state.

**Caution** Use this routine with extreme caution. (See the following Remarks section.)

## Parameters

### `ApcState` [in]

Opaque pointer to a KAPC_STATE structure that was returned from a previous call to [KeStackAttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess).

## Remarks

Every successful call to [KeStackAttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess) must be matched by a subsequent call to **KeUnstackDetachProcess**.

**Note** Attaching a thread to a different process can prevent asynchronous I/O operations from completing and can potentially cause deadlocks. In general, the lines of code between the call to
[KeStackAttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess)
and the call to
**KeUnstackDetachProcess**
should be very simple and should not call complex routines or send IRPs to other drivers.

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[IoGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[IoGetRequestorProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetrequestorprocess)

[IoThreadToProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iothreadtoprocess)

[KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[KeStackAttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)