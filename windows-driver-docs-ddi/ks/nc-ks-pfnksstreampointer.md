# PFNKSSTREAMPOINTER callback function

## Description

AVStream calls a minidriver's *AVStrMiniCancelCallback* routine when the IRP that is associated with a cloned stream pointer is canceled. This routine is optional.

## Parameters

### `StreamPointer` [in]

A pointer to the clone [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) that is associated with the IRP that was canceled. *StreamPointer* was created by a call to [KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone).

## Remarks

The minidriver specifies this routine's address in the *CancelCallback* parameter of [KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone).

In *AVStrMiniCancelCallback*, the minidriver should set all references to the clone pointer to **NULL**.

In addition, the minidriver should remove any context information that is related to the clone pointer, and notify hardware about the cancellation.

Finally, the minidriver must call [KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete) to delete the clone and the context associated with it. If the minidriver does not delete the clone, the IRP will retain a reference count and not complete, possibly causing related applications to crash.

*AVStrMiniCancelCallback* is called with the queue's spin lock held, hence at DISPATCH_LEVEL. Accordingly, the callback routine cannot perform queue manipulation or call functions that acquire a mutex.

## See also

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)