# KsStreamPointerAdvanceOffsetsAndUnlock function

## Description

The **KsStreamPointerAdvanceOffsetsAndUnlock** function advances *StreamPointer* the specified number of bytes into the stream (adjusting the *OffsetIn* and *OffsetOut* fields of *StreamPointer* as requested) and unlocks it.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer to advance and unlock.

### `InUsed` [in]

This parameter contains the number of input bytes used. AVStream advances the input offset by this number of bytes. This must be less than the total number of remaining unused bytes in the frame referenced by *StreamPointer*. If *InUsed* is equal to the remaining number of bytes in the frame referenced by *StreamPointer*, AVStream advances *StreamPointer* to the next available data frame.

### `OutUsed` [in]

This parameter contains the number of output bytes used. AVStream advances the output offset by this number of bytes. This must be less than the total number of remaining unused bytes in the frame referenced by *StreamPointer*. If *OutUsed* is equal to the remaining number of bytes in the frame referenced by *StreamPointer*, AVStream advances *StreamPointer* to the next available data frame.

### `Eject` [in]

This parameter indicates whether *StreamPointer* should be advanced. If this parameter is set to **TRUE**, AVStream advances the stream pointer to the next available data frame regardless of the values in *InUsed* and *OutUsed*.

## Remarks

If using the specified number of bytes in the stream pointer results in zero remaining bytes to process in the current frame, AVStream advances the stream pointer to the next available frame. Minidrivers can force advancement to the next frame regardless of the number of bytes used by setting *Eject*.

## See also

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)