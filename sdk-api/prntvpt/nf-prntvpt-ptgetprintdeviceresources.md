# PTGetPrintDeviceResources function

## Description

It retrieves the print devices resources for a printer formatted in compliance with the XML [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema).

## Parameters

### `hProvider` [in]

A handle to an open device provider whose print device resources are to be retrieved. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `pszLocaleName` [in]

Optional pointer to the locale name. This parameter can be **NULL**.

### `pPrintTicket` [in]

A pointer to a stream with its seek position at the beginning of the print ticket content. This parameter can be **NULL**.

### `pDeviceResources`

A pointer to the stream where the device print resources will be written, starting at the current seek position.

### `pbstrErrorMessage` [out, optional]

A pointer to a PDC file or string that specifies what, if anything, is invalid about *pPrintTicket*. If it is valid, this value is **NULL**.

## Return value

If the operation succeeds, the return value is S_OK. Otherwise, returns an error message.

## See also

[PTGetPrintCapabilities](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptgetprintcapabilities)

[PTGetPrintDeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptgetprintdevicecapabilities)