# FltSetFileContext function

## Description

The **FltSetFileContext** routine sets a context for a file.

## Parameters

### `Instance` [in]

An opaque pointer to a minifilter driver instance for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

Pointer to a [file object](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for the file. This parameter is required and cannot be **NULL**.

### `Operation` [in]

A flag that specifies the type of operation for **FltSetFileContext** to perform. This parameter must be one of the following flags:

| Flag | Meaning |
| ---- | ------- |
| FLT_SET_CONTEXT_REPLACE_IF_EXISTS | If a context is already set for the file that the *FileObject* parameter points to, **FltSetFileContext** will replace that context with the context specified in *NewContext*. Otherwise, it will insert *NewContext* into the list of contexts for the file. |
| FLT_SET_CONTEXT_KEEP_IF_EXISTS | If a context is already set for the file that *FileObject* points to, **FltSetFileContext** will return STATUS_FLT_CONTEXT_ALREADY_DEFINED, and will not replace the existing context or increment the reference count. If a context has not already been set, the routine will insert the context specified in *NewContext* into the list of contexts for the file and increment the reference count. |

### `NewContext` [in]

A pointer to the new context to be set for the file. This parameter is required and cannot be **NULL**.

### `OldContext` [out]

A pointer to a caller-allocated variable that receives the address of the existing file context for the instance pointed to by the *Instance* parameter, if one is already set. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

The **FltSetFileContext** routine returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CONTEXT_ALREADY_DEFINED | If FLT_SET_CONTEXT_KEEP_IF_EXISTS was specified for the *Operation* parameter, this error code indicates that a context is already attached to the file. |
| STATUS_FLT_CONTEXT_ALREADY_LINKED | The context pointed to by the *NewContext* parameter is already linked to an object. In other words, this error code indicates that *NewContext* is already in use due to a successful prior call of a **FltSet***Xxx***Context** routine. |
| STATUS_FLT_DELETING_OBJECT | The instance specified in the *Instance* parameter is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid parameter was passed. For example, the *NewContext* parameter does not point to a valid file context, or an invalid value was specified for the *Operation* parameter. This is an error code. |
| STATUS_NOT_SUPPORTED | File contexts are not supported for this file. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltSetFileContext** to set or replace its own file context on a file. A minifilter driver can attach only one context per minifilter driver instance to the file.

**FltSetFileContext** cannot be called on an unopened *FileObject*. Hence **FltSetFileContext** cannot be called from a pre-create callback for a file because the file has not been opened at that point. A minifilter driver can, however, allocate and set up the file context in the pre-create callback, pass it to the post-create callback using the completion context parameter and set the file context on the file corresponding to that stream in the post-create callback.

### Reference Counting

If **FltSetFileContext** succeeds:

- The reference count on *NewContext* is incremented. When *NewContext* is no longer needed, the minifilter must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement its reference count.

Else if **FltSetFileContext** fails:

- The reference count on *NewContext* remains unchanged.
- If *OldContext* is not **NULL** and does not point to NULL_CONTEXT then *OldContext* is a referenced pointer to the context currently associated with the file. The filter calling **FltSetFileContext** must eventually call **FltReleaseContext** for *OldContext* as well when the context pointer is no longer needed.

Regardless of success:

- The filter calling **FltSetFileContext** must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement the reference count on the *NewContext* object that was incremented by [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

For more information, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

### Other context operations

For more information, see [Setting Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/setting-contexts), and [Releasing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/releasing-contexts):

- To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

- To get a file context, call [**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext).

- To delete a file context, call [**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

- To determine whether file contexts are supported for a given file, call [**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts) or [**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex).

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSupportsFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontexts)

[**FltSupportsFileContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsupportsfilecontextsex)