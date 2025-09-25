## Description

The callback routine performs actions, after an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) returns, of a threaded DPC,

The *CustomDpc* routine finishes the servicing of an I/O operation, after an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine returns.

The *CustomThreadedDpc* routine performs the action of a threaded DPC. The system executes this routine when the threaded DPC runs.

The *CustomTimerDpc* routine executes after a timer object's time interval expires.

## Parameters

### `Dpc` [in]

Caller-supplied pointer to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which represents the DPC object that is associated with this callback routine.

### `DeferredContext` [in, optional]

For *CustomDpc*, a caller-supplied pointer to driver-defined context information that was specified in a previous call to [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc).

For *CustomThreadedDpc*, specifies driver-defined context information. When it initialized the DPC object, the driver supplied this value as the *DeferredContext* parameter to [KeInitializeThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializethreadeddpc).

Caller-supplied pointer to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which represents the DPC object associated with this *CustomTimerDpc* routine.

### `SystemArgument1` [in, optional]

Caller-supplied pointer to driver-supplied information that was specified in a previous call to [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc). When it added the DPC to the DPC queue, the driver supplied this value as the *SystemArgument1* parameter to **KeInsertQueueDpc**.

For *CustomTimerDpc*, this value is not used.

### `SystemArgument2` [in, optional]

Specifies driver-defined context information. When it added the DPC to the DPC queue, the driver supplied this value as the *SystemArgument2* parameter to **KeInsertQueueDpc**.

For *CustomTimerDpc*, this value is not used.

## Remarks

To create a DPC object and register a *CustomDpc* routine for that object, a driver must call [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc). (If you need only one DPC routine, you can use a [DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) routine and the system-allocated DPC object.)

To queue a *CustomDpc* routine for execution, a driver's [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine must call **KeInsertQueueDpc**.

One or more *CustomDpc* routines can be used instead of, or in conjunction with, a *DpcForIsr* routine. A driver that maintains several internal IRP queues typically supplies a *CustomDpc* routine for each queue. Each *CustomDpc* routine is typically responsible for at least the following tasks:

- Completing the I/O operation that is described by the current IRP.

- Dequeuing the next IRP from one of the driver's IRP queues. (Drivers that use the system-supplied IRP queue together with a [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine call [IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket).)

- Setting the I/O status block in the current IRP and calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) for the completed request.

A *CustomDpc* routine might also retry a failed operation or set up the next transfer for a large I/O request that has been broken into smaller pieces.

For more information about *CustomDpc* routines, see [DPC Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpc-objects-and-dpcs).

A driver registers a *CustomThreadedDpc* for a DPC object by calling [KeInitializeThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializethreadeddpc). To actually add the DPC to the DPC queue so that the *CustomThreadedDpc* routine will be executed, call [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc).

For more information about using *CustomThreadedDpc* routines, see [Introduction to Threaded DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs).

A *CustomThreadedDpc* routine can run at IRQL = DISPATCH_LEVEL, or it can run at IRQL = PASSIVE_LEVEL in a real-time thread.

To create a DPC object and register a *CustomTimerDpc* routine for that object, a driver must call [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc).

To queue a *CustomTimerDpc* routine for execution, a driver routine must call [KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer) or [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex), supplying a DPC object pointer returned by **KeInitializeDpc**. The system calls the *CustomTimerDpc* routine when the timer interval expires.

For more information about *CustomTimerDpc* routines, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

### Examples

To define a callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CustomDpc* callback routine that is named `MyCustomDpc`, use the KDEFERRED_ROUTINE type as shown in this code example:

```cpp
KDEFERRED_ROUTINE MyCustomDpc;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyCustomDpc(
    struct _KDPC  *Dpc,
    PVOID  DeferredContext,
    PVOID  SystemArgument1,
    PVOID  SystemArgument2
    )
  {
      // Function body
  }
```

## See also

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)