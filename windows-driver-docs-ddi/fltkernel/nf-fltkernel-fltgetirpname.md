# FltGetIrpName function

## Description

The **FltGetIrpName** routine returns the name for a major function code as a printable string.

## Parameters

### `IrpMajorCode` [in]

The IRP major function code whose name is to be returned.

## Return value

If **IrpMajorCode** is a valid major function code value, **FltGetIrpName** returns its name as a null-terminated string of ANSI characters (such as "IRP_MJ_CREATE"). Otherwise, **FltGetIrpName** returns "\<Invalid IRP code\>".

## Remarks

**FltGetIrpName** is a debugging support routine.

The value of the **IrpMajorCode** parameter can equal to the value of the **MajorFunction** field for an IRP or the **MajorFunction** field for the **Iopb** field of a [callback data structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data).

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)