# FltGetStreamContext function

## Description

The **FltGetStreamContext** routine retrieves a context that was set for a file stream by a given minifilter driver instance.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance whose context is to be retrieved.

### `FileObject` [in]

Pointer to a file object for the stream.

### `Context` [out]

Pointer to a caller-allocated variable that receives the address of the context. This parameter is required and can't be set to NULL.

## Return value

**FltGetStreamContext** returns STATUS_SUCCESS when it successfully returns the requested context. Otherwise, it returns an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_FOUND | No matching context was found on this file at this time, so *FltMgr* set **Context** to NULL_CONTEXT. This is an error code. |
| STATUS_NOT_SUPPORTED | The file system does not support per-stream contexts for this file stream. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

**FltGetStreamContext** retrieves a context that was set for a file stream by a given minifilter driver instance.

**FltGetStreamContext** increments the reference count on the context that the *Context* parameter points to. When this context pointer is no longer needed, the caller must decrement its reference count by calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext). Thus every successful call to **FltGetStreamContext** must be matched by a subsequent call to **FltReleaseContext**.

To set a context for a file stream, call [**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To delete a stream context, call [**FltDeleteStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext)