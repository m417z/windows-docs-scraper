# KsStreamPointerCancelTimeout function

## Description

The **KsStreamPointerCancelTimeout** function cancels a previously scheduled time-out callback on the specified stream pointer.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer for which to cancel a registered time-out callback.

## Remarks

Minidrivers should use [KsStreamPointerScheduleTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerscheduletimeout) to schedule a time-out callback on a specified stream pointer.

The **KsStreamPointerCancelTimeout** function does not affect stream pointers that have no currently scheduled time-out callback.

## See also

[KsPinGetFirstCloneStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetfirstclonestreampointer)

[KsStreamPointerScheduleTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerscheduletimeout)