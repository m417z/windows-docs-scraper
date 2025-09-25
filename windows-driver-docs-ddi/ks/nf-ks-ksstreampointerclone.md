# KsStreamPointerClone function

## Description

The **KsStreamPointerClone** function creates a clone of a given stream pointer.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer that is to be cloned.

### `CancelCallback` [in, optional]

Optional. A pointer to a minidriver-supplied [AVStrMiniCancelCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksstreampointer) routine. AVStream calls this routine if the IRP associated with *CloneStreamPointer* is canceled.

### `ContextSize` [in]

This parameter indicates how many bytes of minidriver context information the resulting clone stream pointer should have. If nonzero, the requested number of bytes are allocated immediately after the returned stream pointer, and the *Context* field of *CloneStreamPointer* points to the allocated memory.

### `CloneStreamPointer` [out]

A pointer to a pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure. Upon successful completion of the cloning operation, *CloneStreamPointer* contains a pointer to the address of the cloned stream pointer.

## Return value

**KsStreamPointerClone** returns either STATUS_SUCCESS, indicating that the cloning operation completed normally, or an appropriate error code.

## Remarks

The resulting clone initially refers to the same data frame as the original stream pointer and is in the same state (locked or unlocked). Adding a clone stream pointer referencing a data frame increments the reference count on that particular frame. Note that the frame in question, and therefore the IRP to which the frame belongs, is not completed until the reference count drops to zero.

You can use the *ContextSize* parameter of this call to minimize allocation calls.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsets)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)