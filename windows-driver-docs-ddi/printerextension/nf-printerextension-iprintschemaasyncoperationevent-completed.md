## Description

Is called when asynchronous PrintSchema operation that is represented by an [IPrintSchemaAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaasyncoperation) context is completed.

## Parameters

### `pTicket` [in]

The print ticket.

### `hrOperation` [in]

The result of the completed operation.

## Return value

This method returns an **HRESULT** value.

## Remarks

The print ticket passed to the **Completed** method is the final validated, merged, or committed print ticket.

## See also

[IPrintSchemaAsyncOperationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaasyncoperationevent)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)