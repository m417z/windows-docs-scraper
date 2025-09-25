# FltDeleteFileContext function

## Description

The **FltDeleteFileContext** routine retrieves and deletes a file context that a given minifilter driver has set for a given file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file. This parameter is required and cannot be **NULL**.

### `OldContext` [out]

Pointer to a caller-allocated variable that receives the address of the deleted context. If no matching context is found, this variable receives NULL_CONTEXT. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

**FltDeleteFileContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_FOUND | No matching context was found. This is an error code. |
| STATUS_NOT_SUPPORTED | File contexts are not supported for this file. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine such as **FltDeleteFileContext** or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext) to explicitly delete a context.

A minifilter driver calls **FltDeleteFileContext** to retrieve and delete a file context that it previously set for a file by calling [**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext).

If the *OldContext* parameter is **NULL** on input and a matching file context is found, **FltDeleteFileContext** releases the reference that was added by the minifilter driver's previous call to [**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext). The deleted context is usually freed immediately unless there is an outstanding reference on it (for example, because the context is still being used by another thread).

If the *OldContext* parameter is not **NULL** and a matching file context is found and returned, the caller is responsible for releasing the reference that was added by [**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext). To release this reference, the minifilter driver must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) on the deleted file context as soon as possible after performing any necessary cleanup.

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To determine whether file contexts are supported for a given file, call [**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts) or [**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex).

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts)

[**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex)