## Description

The **IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode** method converts a print ticket to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

## Parameters

### `pPrintTicket` [in]

A pointer to the input print ticket.

### `cbDevmode` [in]

The size, in bytes, of the input [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. This size includes both the public and private sections of the DEVMODEW structure.

### `pDevmode` [in, out]

A pointer to the input DEVMODEW structure. When **IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode** returns, the plug-in's private DEVMODEW structure will contain information that was obtained from the print ticket.

### `cbDrvPrivateSize` [in]

The size, in bytes, of the plug-in's private DEVMODEW structure.

### `pPrivateDevmode` [in]

A pointer to the plug-in's private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

## Return value

**IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode** should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

The core driver calls the **IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode** method before it performs its part of the conversion of a print ticket to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. In the call to this method, the core driver passes an input print ticket that is fully populated and a DEVMODEW structure that is set to default values. In the conversion, the plug-in must undo any changes that it made to the print ticket during the previous conversion from a DEVMODEW structure to a print ticket. If, during this previous conversion, the plug-in moved a feature from a private namespace to the public namespace, the plug-in must restore the feature to the private namespace in a format that is suitable for the core driver, that is, the format in which the core driver had previously placed the feature in the print ticket that was provided to the plug-in in the [IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-convertdevmodetoprintticket) method. This restoration is necessary so that the core driver can recognize the feature in the print ticket and reflect its settings in private portion of the core driver's DEVMODEW structure while the core driver performs its part of the print ticket-to-DEVMODEW conversion .

Before the system converts a print ticket back to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, it first loads the default DEVMODEW structure. The system then calls the provider's [IPrintOemPrintTicketProvider::BindPrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-bindprinter) method. This method should then read all of the settings that it supported from the print ticket and populate those settings in the DEVMODEW structure. Note that not all of the features necessarily will be represented, and that often Option instances that are present might not contain all of the Scored Property instances that the provider would normally populate. If the provider makes any changes to the settings that are populated by the system during conversion from print ticket to DEVMODEW, the provider should perform the reverse of that change in the **IPrintOemPrintTicketProvider::ConvertPrintTicketToDevMode** method. After the provider returns, the system then overwrites any public DEVMODEW settings that are represented in the print ticket but that are not explicitly disabled by the provider.

## See also

[IPrintOemPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemprintticketprovider)

[IPrintOemPrintTicketProvider::ConvertDevModeToPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemprintticketprovider-convertdevmodetoprintticket)