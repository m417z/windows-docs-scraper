## Description

The **IPrintOemPrintTicketProvider::ValidatePrintTicket** method validates a print ticket.

## Parameters

### `pPrintTicket` [in, out]

A pointer to an input print ticket. When **IPrintOemPrintTicketProvider::ValidatePrintTicket** successfully returns, *pPrintTicket* points to a validated print ticket.

## Return value

**IPrintOemPrintTicketProvider::ValidatePrintTicket** should return **S_NO_CONFLICT** or **S_CONFLICT_RESOLVED** if the operation succeeds. Otherwise, this method should return a standard COM error code. Note that Unidrv and Pscript do not consider **S_OK** to mean successful completion for this method.

## Remarks

If necessary, the **IPrintOemPrintTicketProvider::ValidatePrintTicket** method should perform any conflict resolution, by inspecting the settings made in the public and Unidrv-private parts of the print ticket, to ensure that the resulting print ticket is valid, and that all of the constraints are resolved. If any required nodes are not present in the original print ticket, **IPrintOemPrintTicketProvider::ValidatePrintTicket** can add them to the returned print ticket.

## See also

[IPrintOemPrintTicketProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemprintticketprovider)