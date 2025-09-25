# FltReferenceContext function

## Description

**FltReferenceContext** increments the reference count on a context structure.

## Parameters

### `Context` [in]

Pointer to the context. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls the **FltReferenceContext** routine to increment the reference count on a context structure.

After a successful call to **FltReferenceContext**, the caller is responsible for decrementing the reference count on the context structure by calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext).

For more information about context reference counting, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)