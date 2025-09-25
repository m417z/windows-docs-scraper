# KsStreamPointerDelete function

## Description

The **KsStreamPointerDelete** function deletes a clone stream pointer, releasing a reference on the frame to which this stream pointer referred.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the clone stream pointer to delete. Must be a clone stream pointer; cannot be the leading or trailing edge stream pointer.

## Remarks

If the frame to which *StreamPointer* points has no other references on it after deletion, it is completed. When the last frame in a given IRP is completed, the IRP is completed.

The leading edge and trailing edge stream pointers for a given queue and pin are special stream pointers that cannot be deleted.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsPinGetLeadingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetleadingedgestreampointer)

[KsPinGetTrailingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingettrailingedgestreampointer)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)