# KsAddIrpToCancelableQueue function

## Description

The **KsAddIrpToCancelableQueue** function adds an IRP to a queue of cancelable IRPs, thus allowing the IRP to be canceled. If the IRP had been previously set to a canceled state, the **KsAddIrpToCancelableQueue** function completes the canceling of that IRP.

## Parameters

### `QueueHead` [in, out]

Specifies the driver-allocated storage for the head of the queue on which to add the IRP.

### `SpinLock` [in]

Points to driver's spin lock for queue access to the queue specified at *QueueHead*. A copy of this pointer is kept in the IRP's KSQUEUE_SPINLOCK_IRP_STORAGE(Irp) for use by the cancel routine, if necessary.

### `Irp` [in]

Specifies the IRP to add to the queue specified at *QueueHead*.

### `ListLocation` [in]

Indicates whether this IRP should be placed at the beginning or end of the queue. This value must be KsListEntryTail or KsListEntryHead.

### `DriverCancel` [in, optional]

Optional parameter that specifies a driver-supplied cancel routine to use. If this is **NULL**, the standard [KsCancelRoutine](https://learn.microsoft.com/previous-versions/ff561011(v=vs.85)) is used.

## Return value

None

## Remarks

If the IRP has been put into a cancel state when this routine is called, **KsAddIrpToCancelableQueue** will immediately call the cancel routine specified at *DriverCancel*, or if no routine was specified at *DriverCancel* the default streaming cancel routine is called.

The **KsAddIrpToCancelableQueue** function allows IRPs to be canceled even before being placed on a cancel list, or when being moved from one list to another. This function can be called at IRQ level DISPATCH_LEVEL or lower unless the driver-allocated queue and all entries in the queue are system-resident or allocated from resident storage.

The function does not use the cancel spin lock to add items to the list. Access to the list is synchronized using the provided spin lock and relies on atomic operations on Irp->CancelRoutine.