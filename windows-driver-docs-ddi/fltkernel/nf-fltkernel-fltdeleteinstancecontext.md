# FltDeleteInstanceContext function

## Description

**FltDeleteInstanceContext** removes a context from a given instance and marks the context for deletion.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance.

### `OldContext` [out]

Pointer to a caller-allocated variable that receives the address of the deleted context. This parameter is optional and can be **NULL**. If *OldContext* is not **NULL** and does not point to NULL_CONTEXT, the caller is responsible for calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to release this context when it is no longer needed.

## Return value

**FltDeleteInstanceContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The specified *Instance* is being torn down. This is an error code. |
| STATUS_NOT_FOUND | No matching context was found. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine such as **FltDeleteInstanceContext** to explicitly delete a context.

A minifilter driver calls **FltDeleteInstanceContext** to remove a context from an instance and mark the context for deletion. The context is usually freed immediately unless there is an outstanding reference on it (for example, because the context is still being used by another thread).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To get an instance context, call [**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext).

To set an instance context, call [**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext)