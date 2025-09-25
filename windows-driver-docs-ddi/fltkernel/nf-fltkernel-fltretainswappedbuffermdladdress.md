# FltRetainSwappedBufferMdlAddress function

## Description

**FltRetainSwappedBufferMdlAddress** prevents the Filter Manager from freeing the memory descriptor list (MDL) for a buffer that was swapped in by a minifilter driver.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure for the operation.

## Remarks

When a minifilter driver swaps in a new buffer in a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine, the Filter Manager automatically frees the buffer's MDL when the corresponding postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routine returns.

The minifilter driver can prevent the Filter Manager from freeing the MDL by calling **FltRetainSwappedBufferMdlAddress** from the postoperation callback routine.

After calling **FltRetainSwappedBufferMdlAddress**, the caller is responsible for freeing the MDL by calling a routine such as [IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl).

**FltRetainSwappedBufferMdlAddress** can only be called from a postoperation callback routine.

## See also

[FltDecodeParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdecodeparameters)

[FltGetSwappedBufferMdlAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetswappedbuffermdladdress)

[IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)