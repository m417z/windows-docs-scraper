# KsPinGetTrailingEdgeStreamPointer function

## Description

The **KsPinGetTrailingEdgeStreamPointer** function acquires the trailing edge stream pointer for the queue associated with the specified pin.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for whose queue to return the trailing edge stream pointer.

### `State` [in]

This parameter specifies the state in which to acquire the trailing edge stream pointer. Can be one of the following:

#### KSSTREAM_POINTER_STATE_UNLOCKED

Acquire the leading edge stream pointer regardless of whether it references a data frame or not.

No attempts can be made to access any data associated with the pointer until the pointer is locked. Also note that frames associated with an unlocked stream pointer can be canceled.

#### KSSTREAM_POINTER_STATE_LOCKED

Acquire and lock the leading edge stream pointer. If no data frame is associated with the stream pointer, return **NULL**. If a non**null** pointer is returned, it is a locked stream pointer and has a data frame associated with it. Frames associated with a locked stream pointer *cannot* be canceled.

## Return value

**KsPinGetTrailingEdgeStreamPointer** returns either a pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the trailing edge stream pointer or **NULL**. A return value of **NULL** can indicate that there is no trailing edge for the queue associated with the pin. In this case, the pin descriptor probably does not specify that the pin should have a distinct trailing edge. Alternatively, **NULL** can indicate that there is no queue associated with the pin. In this case, the pin in question does not use the standard transport mechanism. A return value of **NULL** can also indicate that an attempt to lock the trailing edge failed. In other words, there is no data frame currently associated with the leading edge.

## Remarks

The trailing edge stream pointer is a special pointer into the data stream that exists if and only if the pin descriptor for the pin specifies a distinct trailing edge. If this pointer exists, it points to the oldest data in the queue unless specifically advanced by a **KsStreamPointerAdvance***Xxx* or a [KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock) call. Older data can exist in the queue also if cloned stream pointers exist for frames older than the one pointed to by the trailing edge.

Data frames that reside in the window between the leading edge stream pointer and the trailing edge stream pointer have at least one reference count and thus will not leave the queue and be completed until they exit the window as a result of the advancement of the trailing edge. Note that frames between the leading edge and trailing edge are **not** locked by default and therefore can be canceled.

**KsPinGetTrailingEdgeStreamPointer** is mostly of use in pin-centric filters. For more information, see [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing) and [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

**KsPinGetTrailingEdgeStreamPointer** will not work unless the pin descriptor for the pin specifies that the queue is to have a distinct trailing edge by setting the KSPIN_FLAG_DISTINCT_TRAILING_EDGE flag.

## See also

[KsPinGetLeadingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetleadingedgestreampointer)

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)