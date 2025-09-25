# FltReleaseContexts function

## Description

**FltReleaseContexts** releases each context in a given [**FLT_RELATED_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts) structure.

## Parameters

### `Contexts` [in]

Pointer to the [**FLT_RELATED_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts) structure.

## Return value

None

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

**FltReleaseContexts** decrements the reference count on all contexts in the [**FLT_RELATED_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts) structure and sets all members of the structure to NULL_CONTEXT.

To get the **FLT_RELATED_CONTEXTS** structure for a given minifilter driver for a given I/O request, call [**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts).

For more information about context reference counting, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

Callers of **FltReleaseContexts** must be running at IRQL <= DISPATCH_LEVEL if all contexts were allocated from nonpaged pool. If any contexts were allocated from paged pool, callers must be running at IRQL <= APC_LEVEL.

When each context's reference count reaches zero, the context is freed immediately if the caller is running at IRQL <= APC_LEVEL. If the caller is running at IRQL DISPATCH_LEVEL, a work item is scheduled to free the context.

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FLT_RELATED_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltReleaseContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontextsex)