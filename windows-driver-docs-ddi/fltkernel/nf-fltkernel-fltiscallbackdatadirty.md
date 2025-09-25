# FltIsCallbackDataDirty function

## Description

The **FltIsCallbackDataDirty** routine tests the FLTFL_CALLBACK_DATA_DIRTY flag in a callback data structure.

## Parameters

### `Data` [in]

Pointer to a callback data structure ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)).

## Return value

If the FLTFL_CALLBACK_DATA_DIRTY flag is set in the callback data structure, the return value is **TRUE**. Otherwise, the return value is **FALSE**.

## Remarks

To set an [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty).

To clear a callback data structure's FLTFL_CALLBACK_DATA_DIRTY flag, call [FltClearCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcallbackdatadirty).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltClearCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcallbackdatadirty)

[FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)