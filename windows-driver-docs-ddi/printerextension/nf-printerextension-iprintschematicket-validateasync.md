## Description

Gets an asynchronous **PrintTicket** validation operation context.

## Parameters

### `ppAsyncOperation` [out]

The asynchronous validation operation context.

## Return value

This method returns an **HRESULT** value.

## Remarks

 To perform the validation operation, call the [IPrintSchemaAsyncOperation::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperation-start) method to validate the settings of the current PrintTicket object and to pass the resulting **PrintTicket** to the [IPrintSchemaAsyncOperationEvent::Completed](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperationevent-completed) event. When the validation operation is completed, or if an error occurs during the validation operation, the **IPrintSchemaAsyncOperationEvent::Completed** event is fired. This method will not change the settings of the current **PrintTicket** object.

## See also

[IPrintSchemaAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaasyncoperation)

[IPrintSchemaAsyncOperation::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperation-start)

[IPrintSchemaAsyncOperationEvent::Completed](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperationevent-completed)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)