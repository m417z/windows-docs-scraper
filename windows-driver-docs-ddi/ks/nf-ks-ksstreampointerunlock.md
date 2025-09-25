# KsStreamPointerUnlock function

## Description

The **KsStreamPointerUnlock** function unlocks a stream pointer that has previously been locked by an acquisition function **(KsGet***Xxx***EdgeStreamPointer**) or by **KsStreamPointerLock**.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer to unlock.

### `Eject` [in]

This parameter specifies whether to advance *StreamPointer* to the next data frame. A value of **TRUE** advances the stream pointer.

## Remarks

**KsStreamPointerUnlock** can also advance the stream pointer to the next data frame. See the description of *Eject* above.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

**KsPinGetLeadingEdgeStreamPointer**

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsets)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)