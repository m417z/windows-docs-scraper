# FltSetVolumeContext function

## Description

**FltSetVolumeContext** sets a context for a volume.

## Parameters

### `Volume` [in]

Opaque volume pointer for the volume.

### `Operation` [in]

Flag specifying details of the operation to be performed. This parameter must be one of the following:

| Flag | Meaning |
| ---- | ------- |
| FLT_SET_CONTEXT_REPLACE_IF_EXISTS | If a context is already set for *Volume*, **FltSetVolumeContext** will replace it with *NewContext*>. Otherwise, it will insert *NewContext* into the list of contexts for the volume. |
| FLT_SET_CONTEXT_KEEP_IF_EXISTS | If a context is already set for this volume, **FltSetVolumeContext** will return STATUS_FLT_CONTEXT_ALREADY_DEFINED, and will not replace the existing context or increment the reference count. If a context has not already been set, the routine will insert *NewContext* into the list of contexts for the volume and increment the reference count. |

### `NewContext` [in]

Pointer to the new context to be set for the volume. This parameter is required and cannot be **NULL**.

### `OldContext` [out, optional]

Pointer to a caller-allocated variable that receives the address of the existing volume context for *Volume*. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

**FltSetVolumeContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CONTEXT_ALREADY_DEFINED | IF FLT_SET_CONTEXT_KEEP_IF_EXISTS was specified for *Operation*, this error code indicates that a context is already attached to the volume. |
| STATUS_FLT_CONTEXT_ALREADY_LINKED | The context pointed to by the *NewContext* parameter is already linked to an object. In other words, this error code indicates that *NewContext* is already in use due to a successful prior call of a **FltSet***Xxx***Context** routine. |
| STATUS_FLT_DELETING_OBJECT | The specified *Volume* is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid parameter was passed. For example, the *NewContext* parameter does not point to a valid volume context, or an invalid value was specified for *Operation*. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltSetVolumeContext** to attach a context to a volume, or to remove or replace an existing volume context. A minifilter driver can attach only one context to a volume.

### Reference Counting

If **FltSetVolumeContext** succeeds:

- The reference count on *NewContext* is incremented. When *NewContext* is no longer needed, the minifilter must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement its reference count.

Else if **FltSetVolumeContext** fails:

- The reference count on *NewContext* remains unchanged.
- If *OldContext* is not **NULL** and does not point to NULL_CONTEXT then *OldContext* is a referenced pointer to the context currently associated with the volume. The filter calling **FltSetVolumeContext** must call **FltReleaseContext** for *OldContext* as well when the context pointer is no longer needed.

Regardless of success:

- The filter calling **FltSetVolumeContext** must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement the reference count on the *NewContext* object that was incremented by [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

For more information, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

### Other context operations

For more information, see [Setting Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/setting-contexts), and [Releasing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/releasing-contexts):

- To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

- To get a volume context, call [**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext).

- To delete a volume context, call [**FltDeleteVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext)

[**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)