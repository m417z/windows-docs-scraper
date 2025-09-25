# FltClearCallbackDataDirty function

## Description

The **FltClearCallbackDataDirty** routine clears the callback dirty flag in a callback data structure.

## Parameters

### `Data` [in, out]

A pointer to a callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Return value

None

## Remarks

To set an [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty).

To test a callback data structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltIsCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltiscallbackdatadirty).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltIsCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltiscallbackdatadirty)

[FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)