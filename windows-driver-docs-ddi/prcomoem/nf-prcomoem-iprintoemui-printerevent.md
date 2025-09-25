# IPrintOemUI::PrinterEvent

## Description

The `IPrintOemUI::PrinterEvent` method allows a user interface plug-in to process printer events.

## Parameters

### `pPrinterName`

Caller-supplied pointer to a NULL-terminated printer name string. The string can identify a local printer ("*PrinterName*") or remote printer ("\\*Machine*\\*PrinterName*").

### `iDriverEvent`

Caller-supplied value identifying the event that has occurred. For a list of valid values, see [DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent).

### `dwFlags`

Caller-supplied flags. For a list of valid flags, see **DrvPrinterEvent**.

### `lParam`

Caller-supplied event-specific parameter. For more information, see **DrvPrinterEvent**.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in's `IPrintOemUI::PrinterEvent` method performs the same types of operations as the **DrvPrinterEvent** function that is exported by user-mode printer interface DLLs. For information about printer events and how they should be processed, see the description of the [DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent) function.

If you provide a user interface plug-in, the printer driver's **DrvPrinterEvent** function calls the `IPrintOemUI::PrinterEvent` method. The **DrvPrinterEvent** function performs its own processing for the specified event, and then calls the `IPrintOemUI::PrinterEvent` method to handle additional processing of the event.

If `IPrintOemUI::PrinterEvent` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)