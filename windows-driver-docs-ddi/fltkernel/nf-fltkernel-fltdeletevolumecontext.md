# FltDeleteVolumeContext function

## Description

**FltDeleteVolumeContext** removes a context that a given minifilter driver has set for a given volume and marks the context for deletion.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller.

### `Volume` [in]

Opaque volume pointer for the volume.

### `OldContext` [out, optional]

Pointer to a caller-allocated variable that receives the address of the deleted context. This parameter is optional and can be **NULL**. If *OldContext* is not **NULL** and does not point to NULL_CONTEXT, the caller is responsible for calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to release this context when it is no longer needed.

## Return value

**FltDeleteVolumeContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The specified *Volume* is being torn down. This is an error code. |
| STATUS_NOT_FOUND | No matching context was found. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine such as **FltDeleteVolumeContext** to explicitly delete a context.

A minifilter driver calls **FltDeleteVolumeContext** to remove a context from a volume and mark the context for deletion. The context is usually freed immediately unless there is an outstanding reference on it (for example, because the context is still in use by another thread).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To get a volume context, call [**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext).

To set a volume context, call [**FltSetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumecontext)