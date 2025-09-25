## Description

The **IPrintOemPrintTicketProvider::CompletePrintCapabilities** method fills in the remaining entries of the specified print capabilities document.

## Parameters

### `pPrintTicket` [in]

A pointer to an input print ticket. Any configuration-dependent data in the print capabilities (that is, data that would be represented by a **Switch** / **Case** construct in a GPD file) must be based on the settings in the print ticket. If the application does not provide a print ticket, this parameter can be **NULL**. In such situations, the provider should assume default settings for feature and parameter constructs.

### `pCapabilities` [in, out]

A pointer to a partially-complete print capabilities document. When **IPrintOemPrintTicketProvider::CompletePrintCapabilities** returns, the buffer that is pointed to by *pCapablities* should contain a completed print capabilities document.

## Return value

**IPrintOemPrintTicketProvider::CompletePrintCapabilities** should return **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

A Unidrv or Pscript5 plug-in should fill in only those capabilities that it explicitly supports, over and above the features and options that the driver supports. The plug-in should at least fill in the capabilities that it supports, as listed in its private DEVMODEW structure. If the plug-in provider changes the representation of features provided by the core driver in the print ticket, the provider must make equivalent changes to the representation here.