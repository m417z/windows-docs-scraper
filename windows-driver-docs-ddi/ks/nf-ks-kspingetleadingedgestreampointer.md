# KsPinGetLeadingEdgeStreamPointer function

## Description

The **KsPinGetLeadingEdgeStreamPointer** function acquires the leading edge stream pointer for the queue associated with the given pin.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure owning the queue for which the leading edge stream pointer should be acquired.

### `State` [in]

This parameter specifies how to acquire the leading edge stream pointer. Can be one of the following:

#### KSSTREAM_POINTER_STATE_UNLOCKED

Acquire the leading edge stream pointer regardless of whether it references a data frame or not.

No attempts can be made to access any data associated with the pointer until the pointer is locked. Also note that frames associated with an unlocked stream pointer can be canceled.

#### KSSTREAM_POINTER_STATE_LOCKED

Acquire and lock the leading edge stream pointer. If no data frame is associated with the stream pointer, return **NULL**. If a non**null** pointer is returned, it is a locked stream pointer and has a data frame associated with it. Frames associated with a locked stream pointer **cannot** be canceled.

## Return value

**KsPinGetLeadingEdgeStreamPointer** returns a pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure or **NULL**. A return value of **NULL** may occur because there is no queue associated with the pin, indicating that the pin does not use the standard transport mechanism. Alternatively, a return value of **NULL** may occur because an attempt to lock the leading edge failed, indicating that there is no data frame associated with the leading edge.

## Remarks

Filters that implement [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing) often call **KsPinGetLeadingEdgeStreamPointer**.

## See also

[KsPinGetTrailingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingettrailingedgestreampointer)

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)