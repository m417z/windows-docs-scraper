# FltSetCallbackDataDirty function

## Description

A minifilter driver's preoperation or postoperation callback routine calls **FltSetCallbackDataDirty** to indicate that it has modified the contents of the callback data structure.

## Parameters

### `Data` [in, out]

A pointer to a callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Return value

None

## Remarks

A minifilter driver's preoperation ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) or postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routine can modify the contents of the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the operation. If it does, it must then call **FltSetCallbackDataDirty** unless it has changed the contents of the callback data structure's **IoStatus** field.

**FltSetCallbackDataDirty** sets the FLTFL_CALLBACK_DATA_DIRTY flag in a callback data structure.

To test a callback data structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltIsCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltiscallbackdatadirty).

To clear a callback data structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltClearCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcallbackdatadirty).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltClearCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcallbackdatadirty)

[FltIsCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltiscallbackdatadirty)

[FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)