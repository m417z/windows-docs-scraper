# FltSetInstanceContext function

## Description

**FltSetInstanceContext** sets a context for a minifilter driver instance.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance.

### `Operation` [in]

Flag specifying details of the operation to be performed. This parameter must be one of the following:

| Flag | Meaning |
| ---- | ------- |
| FLT_SET_CONTEXT_REPLACE_IF_EXISTS | If a context is already set for the instance that the *Instance* parameter points to, **FltSetInstanceContext** will replace that context with the context specified in *NewContext*. Otherwise, it will set *NewContext* as the context for *Instance*. |
| FLT_SET_CONTEXT_KEEP_IF_EXISTS | If a context is already set for this *Instance*, **FltSetInstanceContext** returns STATUS_FLT_CONTEXT_ALREADY_DEFINED, and does not replace the existing context or increment the reference count. If a context is not already set, the routine will set *NewContext* as the context for *Instance* and increment the reference count. |

### `NewContext` [in]

Pointer to the new context to be set for the instance. This parameter is required and cannot be **NULL**.

### `OldContext` [out]

Pointer to a caller-allocated variable that receives the address of the existing instance context, if one is already set. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

**FltSetInstanceContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CONTEXT_ALREADY_DEFINED | If FLT_SET_CONTEXT_KEEP_IF_EXISTS was specified for the *Operation* parameter, this error code indicates that a context is already attached to the instance. Only one context can be attached to an instance. |
| STATUS_FLT_CONTEXT_ALREADY_LINKED | The context pointed to by the *NewContext* parameter is already linked to an object. In other words, this error code indicates that *NewContext* is already in use due to a successful prior call of a **FltSet***Xxx***Context** routine. |
| STATUS_FLT_DELETING_OBJECT | The instance specified in the *Instance* parameter is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid parameter was passed. For example, the *NewContext* parameter does not point to a valid file context, or an invalid value was specified for the *Operation* parameter. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltSetInstanceContext** to attach an instance context to a caller-owned minifilter driver instance or to remove or replace an existing instance context. A minifilter driver can attach only one context to an instance.

### Reference Counting

If **FltSetInstanceContext** succeeds:

- The reference count on *NewContext* is incremented. When the context pointed to by *NewContext* is no longer needed, the minifilter must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement its reference count.

Else if **FltSetInstanceContext** fails:

- The reference count on *NewContext* remains unchanged.
- If *OldContext* is not **NULL** and does not point to NULL_CONTEXT then *OldContext* is a referenced pointer to the context currently associated with the instance. The filter calling **FltSetInstanceContext** must eventually call **FltReleaseContext** for *OldContext* as well when the context pointer is no longer needed.

Regardless of success:

- The filter calling **FltSetInstanceContext** must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement the reference count on the *NewContext* object that was incremented by [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

For more information, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

### Other context operations

For more information, see [Setting Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/setting-contexts), and [Releasing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/releasing-contexts):

- To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

- To get an instance context, call [**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext).

- To delete an instance context, call [**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext)

[**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)