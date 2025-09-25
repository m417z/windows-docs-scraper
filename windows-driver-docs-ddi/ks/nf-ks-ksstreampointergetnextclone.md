# KsStreamPointerGetNextClone function

## Description

The **KsStreamPointerGetNextClone** function returns the clone stream pointer that was cloned immediately after the specified clone.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the clone stream pointer for which the clone stream pointer cloned immediately after it on the same pin is returned.

## Return value

**KsStreamPointerGetNextClone** returns a pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the clone stream pointer that was cloned immediately after *StreamPointer* on the same pin. Alternatively, it returns **NULL** indicating that either *StreamPointer* is the last clone on the pin or that *StreamPointer* is not a clone. If not a clone, *StreamPointer* is either the leading or trailing edge stream pointer.

## Remarks

The returned pointer always refers to the same pin as *StreamPointer*. **KsStreamPointerGetNextClone**, in conjunction with [KsPinGetFirstCloneStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetfirstclonestreampointer),can be used to enumerate all clone stream pointers on a given pin in the order in which they were cloned.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsPinGetFirstCloneStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetfirstclonestreampointer)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)