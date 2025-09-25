# ITransactionStatus::SetTransactionStatus

## Description

Sets the transaction status to either committed or aborted. Do not use this method. It is used only internally by COM+.

## Parameters

### `hrStatus` [in]

The status of the transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[ITransactionStatus](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionstatus)