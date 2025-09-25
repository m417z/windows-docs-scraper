## Description

Gets the reason why the printer extension was activated.

This property is read-only.

## Parameters

### `pReasonId`

Defines the **GUID** parameter *pReasonId*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

In this mode, preferences for a print job or default print preferences is expected to be displayed:

- Guid = {EC8F261F-267C-469F-B5D6-3933023C29CC}

- **PRINTER_EXTENSION_REASON_PRINT_PREFERENCES** = { 0xec8f261f, 0x267c, 0x469f, 0xb5, 0xd6, 0x39, 0x33, 0x2, 0x3c, 0x29, 0xcc };

In this mode a status monitor for the print queue is expected to be displayed:

- Guid = {23BB1328-63DE-4293-915B-A6A23D929ACB}

- **PRINTER_EXTENSION_REASON_DRIVER_EVENT** = { 0x23bb1328, 0x63de, 0x4293, 0x91, 0x5b, 0xa6, 0xa2, 0x3d, 0x92, 0x9a, 0xcb };

## See also

[DetailedReasonId](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensioneventargs-get_detailedreasonid)

[IPrinterExtensionEventArgs](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioneventargs)