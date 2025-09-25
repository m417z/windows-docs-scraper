## Description

The **IPrintOemPrintTicketProvider::ExpandIntentOptions** method enables the plug-in to expand printer options (such as photo printing) into individual feature settings in the print ticket.

## Parameters

### `pPrintTicket` [in, out]

A pointer to a print ticket.

## Return value

**IPrintOemPrintTicketProvider::ExpandIntentOptions** should return **S_OK** if the operation succeeds or when the plug-in does not support intent features. Otherwise, this method should return a standard COM error code.

## Remarks

The Unidrv or Pscript5 driver calls **IPrintOemPrintTicketProvider::ExpandIntentOptions** to enable the plug-in to expand options that represent intent into their individual settings in other features in the print ticket before print ticket validation. Such option expansion has two important effects: the client receives information about the results of the intent expansion, and the core driver resolves constraints against the individual features that are affected by the intent.

We recommend that the driver preserve the state of the intent option in the driver's private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure when it converts a print ticket to a DEVMODEW, and then from a DEVMODEW back to a print ticket.