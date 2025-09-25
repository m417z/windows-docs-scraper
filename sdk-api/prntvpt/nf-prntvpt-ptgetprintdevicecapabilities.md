# PTGetPrintDeviceCapabilities function

## Description

Retrieves the device printer's capabilities formatted in compliance with the XML [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema).

## Parameters

### `hProvider` [in]

A handle to an open device provider whose print capabilities are to be retrieved. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `pPrintTicket` [in, optional]

An optional pointer to a stream with its seek position at the beginning of the print ticket content. This parameter can be **NULL**.

### `pDeviceCapabilities`

A pointer to the stream where the device print capabilities will be written, starting at the current seek position.

### `pbstrErrorMessage` [out, optional]

A pointer to a PDC file or string that specifies what, if anything, is invalid about *pPrintTicket*. If it is valid, this value is **NULL**.The function uses this parameter only used if *pPrintTicket* is used.

## Return value

If the operation succeeds, the return value is S_OK. Otherwise, returns an error message.

## See also

[PTGetPrintCapabilities](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptgetprintcapabilities)