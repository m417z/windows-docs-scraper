## Description

Gets the setting that indicates whether or not to show the print UI.

This property is read-only.

## Parameters

### `pbShow`

Defines the **BOOL** parameter *pbShow*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

Note that the **DisplayUI** property corresponds to the psk:DisplayUI element. If the XML value is unspecified or set to *Show*, then the Print system sets **DisplayUI** to **TRUE.**

## See also

[IPrintSchemaFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemafeature)