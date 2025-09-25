# KsStreamPointerGetMdl function

## Description

The **KsStreamPointerGetMdl** function returns the MDL associated with the frame referenced by *StreamPointer*.

## Parameters

### `StreamPointer` [in]

A pointer to the [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure that references the frame for which to return the associated MDL.

## Return value

Returns either a pointer to the [memory descriptor list (MDL)](https://learn.microsoft.com/windows-hardware/drivers/) describing the frame referenced by *StreamPointer* or returns **NULL**. A **NULL** return value usually indicates that the given stream pointer was not locked at call-time.

## Remarks

The stream pointer **must** be locked in order for **KsStreamPointerGetMdl** to execute successfully.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsStreamPointerGetIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointergetirp)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)