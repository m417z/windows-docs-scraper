# FltDeleteStreamHandleContext function

## Description

**FltDeleteStreamHandleContext** removes a context that a given minifilter driver instance has set for a given stream handle and marks the context for deletion.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance whose context is to be removed from the list of contexts attached to the stream handle.

### `FileObject` [in]

Pointer to a file object for the file stream.

### `OldContext` [out]

Pointer to a caller-allocated variable that receives the address of the deleted context. This parameter is optional and can be **NULL**. If *OldContext* is not **NULL** and does not point to NULL_CONTEXT, the caller is responsible for calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to release this context when it is no longer needed.

## Return value

**FltDeleteStreamHandleContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The specified *Instance* is being torn down. This is an error code. |
| STATUS_NOT_FOUND | No matching context was found. This is an error code. |
| STATUS_NOT_SUPPORTED | The file system does not support per-stream contexts for this file stream handle. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine such as **FltDeleteStreamHandleContext** to explicitly delete a context.

A minifilter driver calls **FltDeleteStreamHandleContext** to remove a context from a stream handle and mark the context for deletion. The context is usually freed immediately unless there is an outstanding reference on it (for example, because the context is still in use by another thread).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To get a stream context, call [**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext).

To set a stream context, call [**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)