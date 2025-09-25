# FltGetInstanceContext function

## Description

The **FltGetInstanceContext** routine retrieves a context that was set for an instance by a given minifilter driver.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance.

### `Context` [out]

Pointer to a caller-allocated variable that receives the address of the instance context. This parameter is required and can't be set to NULL.

## Return value

**FltGetInstanceContext** returns STATUS_SUCCESS when it successfully returns the requested instance context. Otherwise, it returns an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_FOUND | No matching context was found on this instance at this time. *FltMgr* sets **Context** to NULL_CONTEXT. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

**FltGetInstanceContext** retrieves a context that was set for an instance by a given minifilter driver.

**FltGetInstanceContext** increments the reference count on the context that the *Context* parameter points to. When this context pointer is no longer needed, the caller must decrement its reference count by calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext). Thus every successful call to **FltGetInstanceContext** must be matched by a subsequent call to **FltReleaseContext**.

To set a context for an instance, call [**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To delete a file context, call [**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext)