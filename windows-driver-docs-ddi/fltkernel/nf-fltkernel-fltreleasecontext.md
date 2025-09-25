# FltReleaseContext function

## Description

**FltReleaseContext** decrements the reference count on a context.

## Parameters

### `Context` [in]

Pointer to the context. Must be a valid pointer to a context object for a volume, instance, stream, or stream handle. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltReleaseContext** to release a context. **FltReleaseContext** decrements the reference count on the given context. When the reference count reaches zero, the context is freed immediately if the caller is running at IRQL <= APC_LEVEL. If the caller is running at IRQL DISPATCH_LEVEL, a work item is scheduled to free the context.

> [!NOTE]
> After **FltReleaseContext** returns, the caller must not use the context, because the context might have already been freed.

Every successful call to [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext), **FltGet***Xxx***Context**, or [**FltReferenceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext) must eventually be matched by a call to **FltReleaseContext**.

Note that the *OldContext* pointer returned by **FltSet***Xxx***Context** and the *Context* parameter that is used to call [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext) must also be released by calling **FltReleaseContext** when they are no longer needed.

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To increment the reference count on a context, call [**FltReferenceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext).

For more information about context reference counting, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

Callers of **FltReleaseContext** must be running at IRQL <= DISPATCH_LEVEL if the context was allocated from nonpaged pool. If the context was allocated from paged pool, callers must be running at IRQL <= APC_LEVEL.

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts)

[**FltGetContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontextsex)

[**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext)

[**FltGetSectionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetsectioncontext)

[**FltGetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamcontext)

[**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)

[**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext)

[**FltReferenceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext)

[**FltReleaseContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontexts)

[**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext)

[**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext)

[**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)

[**FltSetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext)

[**FltSetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumecontext)