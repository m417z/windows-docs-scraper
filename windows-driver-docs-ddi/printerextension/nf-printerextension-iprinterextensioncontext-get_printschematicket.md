## Description

Gets the print ticket that is appropriate for the queue and the activation.

This property is read-only.

## Parameters

### `ppTicket`

The appropriate print ticket.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

Returns **E_ILLEGAL_METHOD_CALL** if called from the [IPrinterExtensionEvent::OnPrinterQueuesEnumerated](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionevent-onprinterqueuesenumerated) context.

## See also

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)

[IPrinterExtensionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioncontext)