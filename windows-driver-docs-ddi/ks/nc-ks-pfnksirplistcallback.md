# PFNKSIRPLISTCALLBACK callback function

## Description

A streaming minidriver's *KStrIrpListCallback* routine is called to determine whether the passed in IRP should be moved from the source list to the destination list, or if IRP enumeration should be terminated.

## Parameters

### `Irp` [in]

Pointer to the IRP to possibly move to the destination list from the source list.

### `Context` [in]

Passed from [KsMoveIrpsOnCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmoveirpsoncancelablequeue).

## Return value

Returns STATUS_SUCCESS to indicate the passed in IRP should be moved from the source list to the destination list. Returns STATUS_NO_MATCH if the passed in IRP should not be moved. Returns any other value to terminate enumeration.

## Remarks

*KStrIrpListCallback* is called at DISPATCH_LEVEL.

*KStrIrpListCallback* is always called at least once at the end of list processing with a **NULL** IRP value in order to complete list processing.

## See also

[KsMoveIrpsOnCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmoveirpsoncancelablequeue)