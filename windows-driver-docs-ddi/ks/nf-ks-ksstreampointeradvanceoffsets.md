# KsStreamPointerAdvanceOffsets function

## Description

The **KsStreamPointerAdvanceOffsets** function advances the offsets of *StreamPointer*.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer for which to advance the offsets. *StreamPointer* should be in the locked state when this function is called.

### `InUsed` [in]

The number of bytes to advance the input pointer of this stream pointer.

(StreamPointer -> OffsetIn)

### `OutUsed` [in]

The number of bytes to advance the output pointer of this stream pointer

(StreamPointer -> OffsetOut)

### `Eject` [in]

This parameter indicates whether the stream pointer should be advanced to the next data frame If this parameter is set to **TRUE**, AVStream advances the stream pointer regardless of whether advancing the offsets causes the stream pointer to point to the end of a frame.

## Return value

**KsStreamPointerAdvanceOffsets** returns STATUS_SUCCESS on success. Returns STATUS_DEVICE_NOT_READY if either *StreamPointer* was not locked at call-time or that the stream pointer could not be locked after advancement.

## Remarks

AVStream updates the in and out data pointers and other related fields by the requested values. If advancing the offsets results in zero bytes remaining in the current frame, AVStream advances the stream pointer to the next data frame and relocks it.

It is the responsibility of the minidriver to verify that *StreamPointer* is locked before calling **KsStreamPointerAdvanceOffsets**. Also, a single advancement cannot advance a stream pointer further than the beginning of the next frame in the queue. Thus, minidrivers should not attempt to advance offsets by a value greater than *StreamPointer -> Offset*.Remaining*.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)