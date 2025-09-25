## Description

Called when printer queues are enumerated.

## Parameters

### `pContextCollection` [in]

Pointer to [IPrinterExtensionContextCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioncontextcollection) object.

## Return value

This method returns an **HRESULT** value.

## Remarks

**OnPrinterQueuesEnumerated** is called every time the set of print queues associated with the printer extension is updated. So it is important for printer extensions to be able to handle multiple calls to this method without causing a catastrophic failure of the printer extension.

## See also

[IPrinterExtensionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioncontext)

[IPrinterExtensionContextCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioncontextcollection)

[IPrinterExtensionEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensionevent)