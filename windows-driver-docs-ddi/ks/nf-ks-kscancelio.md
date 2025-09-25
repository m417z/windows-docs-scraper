# KsCancelIo function

## Description

The **KsCancelIo** function cancels all IRPs on the specified cancel list. If an IRP on the list does not have a cancel routine, only the cancel bit is set in the IRP. The function can be called at IRQ level DISPATCH_LEVEL or lower.

## Parameters

### `QueueHead` [in, out]

Specifies the head of a driver-maintained queue containing the IRP's to be canceled.

### `SpinLock` [in]

Points to a caller-allocated spin lock for queue access. A copy of this pointer is kept in the IRP's KSQUEUE_SPINLOCK_IRP_STORAGE(Irp) for use by the cancel routine, if necessary.

## Return value

None

## Remarks

**KsCancelIo** cancels all IRPs in a given driver-maintained queue. If the IRP has a cancel routine, the cancel routine is called. Otherwise, the cancel flag in the IRP is set to **TRUE**. The IRPs are not removed from the queue by this routine. It is the sole responsibility of the driver to ensure that the IRPs are removed either by the cancel routine specified in the IRP or by some other driver-supplied functionality.

If the IRP being canceled has a driver-supplied cancel routine, the cancel spin lock can be obtained from the IRP by calling KSQUEUE_SPINLOCK_IRP_STORAGE.

## See also

[KsAddIrpToCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddirptocancelablequeue)