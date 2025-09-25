# FltGetFileContext function

## Description

The **FltGetFileContext** routine retrieves a context that was set for a file by a given minifilter driver instance.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file. This parameter is required and cannot be **NULL**.

### `Context` [out]

Pointer to a caller-allocated variable that receives the address of the context. This parameter is required and cannot be set to NULL.

## Return value

**FltGetFileContext** returns STATUS_SUCCESS when it successfully returns the requested file context. Otherwise, it returns an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_FOUND | No matching context was found on this file at this time, so *FltMgr* set **Context** to NULL_CONTEXT. This is an error code. |
| STATUS_NOT_SUPPORTED | File contexts are not supported for this file. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltGetFileContext** to retrieve the file context that it has set for a given file.

**FltGetFileContext** increments the reference count on the context that the *Context* parameter points to. When this context pointer is no longer needed, the caller must decrement its reference count by calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext). Thus, every successful call to **FltGetFileContext** must be matched by a subsequent call to **FltReleaseContext**.

To set a file context, call [**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To delete a file context, call [**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

To determine whether file contexts are supported for a given file, call [**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts) or [**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex).

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts)

[**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex)