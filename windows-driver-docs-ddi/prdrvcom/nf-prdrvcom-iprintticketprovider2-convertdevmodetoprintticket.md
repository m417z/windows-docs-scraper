## Description

The **IPrintTicketProvider2::ConvertDevModeToPrintTicket** method converts a **DEVMODEW** structure into a print ticket.

## Parameters

### `cbDevmode` [in]

The size, in bytes, of the input **DEVMODEW** structure. The size includes both the public and private portions of this structure.

### `pDevmode` [in]

A pointer to the input **DEVMODEW** structure, including its public and private portions.

### `pPrintTicket` [in]

A pointer to the partially-completed print ticket. When **IPrintTicketProvider2::ConvertDevModeToPrintTicket** returns, all entries in the print ticket should be filled in.

## Return value

**IPrintTicketProvider2::ConvertDevModeToPrintTicket** should return **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

When the print system converts the contents of a **DEVMODEW** structure into a print ticket, it converts all of the public **DEVMODEW** fields except those that the plug-in provider has indicated should be disabled. For these **DEVMODEW** fields that are disabled and not converted, the plug-in provider is responsible for populating the corresponding print ticket values. If the **DEVMODEW** snapshot was disabled during a call to IPrintTicketProvider2::BindPrinter, the representation from the conversion must provide enough information to reconstruct the original **DEVMODEW** structure from the print ticket without loss of information.

The DEVMODEW snapshot allows support for subtle distinctions in options provided in the **DEVMODEW** structure for which the print ticket might not have representations. For example, **DEVMODEW** might support the LETTER paper size while the print ticket supports the LETTERSMALL paper size.

## See also

[IPrintTicketProvider2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prdrvcom/nn-prdrvcom-iprintticketprovider2)

[IPrintTicketProvider2::ConvertPrintTicketToDevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prdrvcom/nf-prdrvcom-iprintticketprovider2-convertprinttickettodevmode)