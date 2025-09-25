# FltGetSwappedBufferMdlAddress function

## Description

The **FltGetSwappedBufferMdlAddress** routine returns the memory descriptor list (MDL) address for a buffer that was swapped in by a minifilter driver.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure for the operation.

## Return value

**FltGetSwappedBufferMdlAddress** returns the MDL address for the buffer that was swapped in by the caller. **FltGetSwappedBufferMdlAddress** returns **NULL** in the following cases:

* The operation is a fast I/O operation. In a fast I/O operation, the buffer cannot have an MDL.
* The buffer that was swapped in by the caller does not have an MDL.
* The minifilter driver did not swap buffers in the preoperation callback routine.

## Remarks

A minifilter driver that swaps in a new buffer in a preoperation callback routine can get the MDL address for the buffer by calling **FltGetSwappedBufferMdlAddress** from the corresponding postoperation callback routine.

The **FltGetSwappedBufferMdlAddress** routine is necessary because the postoperation callback routine receives a callback data structure that contains the original buffer and MDL address, not the ones that were swapped in by the caller's preoperation callback routine.

It is possible for **FltGetSwappedBufferMdlAddress** to return a non-**NULL** MDL value even if the caller did not create an MDL for the buffer that it swapped in. This happens when an MDL is created for the buffer by a minifilter driver, legacy filter driver, or file system driver that is below the caller in the minifilter driver or file system driver stack.

It is also possible for **FltGetSwappedBufferMdlAddress** to return a non-**NULL** MDL value even if the caller did not swap in a new buffer in its preoperation callback routine. This happens in operations, such as paging I/O, where the buffer is **NULL**, and the caller swaps in a new MDL address.

The MDL for the buffer that was swapped in by the caller is automatically freed by the Filter Manager when the postoperation callback routine returns. To prevent this MDL from being freed, call [FltRetainSwappedBufferMdlAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretainswappedbuffermdladdress).

**FltGetSwappedBufferMdlAddress** can only be called from a postoperation callback routine.

## See also

[FltDecodeParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdecodeparameters)

[FltRetainSwappedBufferMdlAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretainswappedbuffermdladdress)