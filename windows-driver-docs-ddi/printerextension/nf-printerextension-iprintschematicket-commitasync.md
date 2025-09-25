## Description

Gets an asynchronous PrintTicket commit operation context.

## Parameters

### `pPrintTicketCommit` [in]

The print ticket to commit.

### `ppAsyncOperation` [out]

The asynchronous commit operation context.

## Return value

This method returns an **HRESULT** value.

## Remarks

To perform the commit operation, call the [IPrintSchemaAsyncOperation::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperation-start) method to validate the given *pPrintTicketCommit* and then apply the validated PrintTicket settings to the current PrintTicket object. When the commit operation is completed or if an error occurs during the commit operation, the [IPrintSchemaAsyncOperationEvent::Completed](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperationevent-completed) event is fired.

## See also

[IPrintSchemaAsyncOperation::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperation-start)

[IPrintSchemaAsyncOperationEvent::Completed](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperationevent-completed)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)