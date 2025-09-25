# KsStreamPointerAdvance function

## Description

The **KsStreamPointerAdvance** function advances a stream pointer to the next data frame.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer to advance to reference the next available data frame.

## Return value

**KsStreamPointerAdvance** returns STATUS_SUCCESS to indicate a successful advancement. It returns an error code otherwise. STATUS_DEVICE_NOT_READY is the most often returned error code and often indicates that locking the stream pointer after advancement failed. In other words, *StreamPointer* references the last frame in the queue.

## Remarks

If *StreamPointer* is locked at call-time, AVStream unlocks it before advancing it. Once advanced, the stream pointer is placed back into its original state (locked or unlocked) on the new frame.

An attempt to advance a stream pointer that is unlocked always succeeds and returns STATUS_SUCCESS. Since the stream pointer is not locked, there is no way to determine if the stream pointer references actual data. The minidriver must attempt a lock to determine if the newly advanced stream pointer references a data frame or not.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

[KsStreamPointerAdvanceOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsets)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)