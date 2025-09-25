# IoGetTransactionParameterBlock function

## Description

The **IoGetTransactionParameterBlock** routine returns the transaction parameter block for a transacted file operation.

## Parameters

### `FileObject` [in]

A pointer to a file object for the file.

## Return value

The **IoGetTransactionParameterBlock** routine returns a pointer to the [TXN_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_txn_parameter_block) structure if the file operation is transacted, otherwise it returns **NULL**.

## See also

[TXN_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_txn_parameter_block)