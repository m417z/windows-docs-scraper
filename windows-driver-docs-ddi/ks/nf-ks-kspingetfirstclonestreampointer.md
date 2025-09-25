# KsPinGetFirstCloneStreamPointer function

## Description

The **KsPinGetFirstCloneStreamPointer** function returns the first cloned stream pointer on *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure on which to return the first clone stream pointer.

## Return value

**KsPinGetFirstCloneStreamPointer** returns a pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure. This pointer points to the first cloned stream pointer on *Pin*. If no clone stream pointers exist for *Pin*, **KsPinGetFirstCloneStreamPointer** returns **NULL**.

## Remarks

**KsPinGetFirstCloneStreamPointer**, along with [KsStreamPointerGetNextClone](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointergetnextclone) can be used to enumerate all clone stream pointers on a given pin in the order in which they were cloned. Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerGetNextClone](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointergetnextclone)