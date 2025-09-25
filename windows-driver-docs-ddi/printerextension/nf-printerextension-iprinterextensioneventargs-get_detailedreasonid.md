## Description

Gets a more detailed activation reason than what can be retrieved from [ReasonId](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensioneventargs-get_reasonid).

This property is read-only.

## Parameters

### `pDetailedReasonId`

Defines the **GUID** parameter *pDetailedReasonId*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The value of **DetailedReasonId** is always {5D5A1704-DFD1-4181-8EEE-815C86EDAD31}, which indicates that the printer extension was activated as a result of a Bidi event.

## See also

[IPrinterExtensionEventArgs](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioneventargs)

[ReasonId](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensioneventargs-get_reasonid)