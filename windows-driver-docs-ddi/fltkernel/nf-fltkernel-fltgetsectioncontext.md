# FltGetSectionContext function

## Description

The **FltGetSectionContext** routine retrieves a section context that was created for a file stream by a specified minifilter driver instance.

## Parameters

### `Instance` [in]

An opaque instance pointer for the minifilter driver instance whose context is to be retrieved.

### `FileObject` [in]

A pointer to a file object for the stream.

### `Context` [out]

A pointer to a caller-allocated variable that receives the address of the context. This parameter is required and can't be set to NULL.

## Return value

**FltGetSectionContext** returns STATUS_SUCCESS when it successfully returns the requested section context. Otherwise, it returns an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_FOUND | No matching context was found on this file at this time, so *FltMgr* set **Context** to NULL_CONTEXT. This is an error code. |
| STATUS_NOT_SUPPORTED | The volume attached to this instance does not support section contexts. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

**FltGetSectionContext** retrieves a section context that was created for a file stream by a specified minifilter driver instance. A section context is created by calling [**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan).

**FltGetSectionContext** increments the reference count on the context that the *Context* parameter points to. When this context pointer is no longer needed, the caller must decrement its reference count by calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext). Thus every successful call to **FltGetSectionContext** must be matched by a subsequent call to **FltReleaseContext**.

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

Minifilters must not explicitly delete a section context passed to [**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan). A section context is deallocated and removed from a stream by calling [**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan) in this case.

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan)

[**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)