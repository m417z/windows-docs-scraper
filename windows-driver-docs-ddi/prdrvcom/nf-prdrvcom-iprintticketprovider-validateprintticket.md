## Description

The **IPrintTicketProvider::ValidatePrintTicket** method validates a print ticket.

## Parameters

### `pBaseTicket` [in, out]

A pointer to an input print ticket. When **IPrintTicketProvider::ValidatePrintTicket** successfully returns, *pBaseTicket* points to a validated print ticket.

## Return value

**IPrintTicketProvider::ValidatePrintTicket** should return **S_NO_CONFLICT** or **S_CONFLICT_RESOLVED** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

If necessary, the **IPrintTicketProvider::ValidatePrintTicket** method should perform any conflict resolution, by inspecting the settings made in the public and Unidrv-private parts of the print ticket, to ensure that the resulting print ticket is valid, and that all of the constraints are resolved. If any required nodes are not present in the original print ticket, **IPrintTicketProvider::ValidatePrintTicket** can add them to the returned print ticket.