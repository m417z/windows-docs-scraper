# KsRemoveSpecificIrpFromCancelableQueue function

## Description

The **KsRemoveSpecificIrpFromCancelableQueue** function removes the specified IRP from the specified queue. This is performed on an IRP that was previously acquired using [KsRemoveIrpFromCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveirpfromcancelablequeue), but that was not actually removed from the queue.

## Parameters

### `Irp` [in]

Points to I/O request packet.

## Return value

None