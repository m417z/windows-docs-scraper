## Description

The **IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket** method converts a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure into a print ticket.

## Parameters

### `cbDevmode` [in]

The size, in bytes, of the input [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. The size includes both the public and private portions of this structure.

### `pDevmode` [in]

A pointer to the input DEVMODEW structure.

### `cbDrvPrivateSize` [in]

The size, in bytes, of the plug-in's private DEVMODEW structure.

### `pPrivateDevmode` [in]

A pointer to the plug-in's private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `pPrintTicket` [in, out]

A pointer to the partially-completed print ticket. When **IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket** returns, all of the entries in the print ticket should be filled in.

## Return value

**IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket** should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

The core driver calls the **IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket** method with an input print ticket that is populated with public and Unidrv-private or Pscript5-private features. The plug-in is free to set [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) settings in the public part or in the plug-in's private part, based on settings in the input print ticket. In addition to setting new DEVMODEW items, the plug-in can modify existing settings in the public portion of the DEVMODEW structure.

The DEVMODEW structure fields that correlate with the part of the DEVMODEW structure of interest to the client will already have been populated before **IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket** is called, including the public portion of the DEVMODEW structure and excluding the privately-defined values in the public portion of the DEVMODEW structure.

## See also

[IPrintOemPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemprintticketprovider)

[IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-convertprinttickettodevmode)