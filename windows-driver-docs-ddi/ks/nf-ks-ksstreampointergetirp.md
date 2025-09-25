# KsStreamPointerGetIrp function

## Description

The **KsStreamPointerGetIrp** function returns the IRP associated with the frame that is referenced by the given stream pointer.

## Parameters

### `StreamPointer` [in]

A pointer to the [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure that references the frame for which the associated IRP is returned.

### `FirstFrameInIrp` [out, optional]

A pointer to a caller-supplied BOOLEAN value set to **TRUE** on return if the frame referenced by *StreamPointer* is the first frame in the returned IRP and **FALSE** if not. If **NULL**, AVStream does not test this condition.

### `LastFrameInIrp` [out, optional]

A pointer to a caller-supplied BOOLEAN value set to **TRUE** if the frame referenced by the stream pointer is the last frame in the returned IRP and **FALSE** if not. If **NULL**, AVStream does not test this condition.

## Return value

**KsStreamPointerGetIrp** returns either a pointer to the IRP associated with the frame that is referenced by the given stream pointer, or returns **NULL**. A return value of **NULL** indicates that the stream pointer is not locked.

## Remarks

**KsStreamPointerGetIrp** can also be used to determine if *StreamPointer* references the first and/or last frame contained in the returned IRP.

*StreamPointer* must be locked in order for **KsStreamPointerGetIrp** to execute successfully. Any attempt to call this function with an unlocked stream pointer results in a **NULL** return value.

*FirstFrameInIrp* and*/*or *LastFrameInIrp* must be non-**NULL** at call-time in order for AVStream to fill in these values.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsStreamPointerGetMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointergetmdl)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)