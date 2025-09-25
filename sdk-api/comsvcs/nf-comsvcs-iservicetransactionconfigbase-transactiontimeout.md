# IServiceTransactionConfigBase::TransactionTimeout

## Description

Sets the transaction time-out for a new transaction.

## Parameters

### `ulTimeoutSec` [in]

The transaction time-out, in seconds.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

If the transaction does not either commit or abort within the transaction time-out period, the transaction must automatically abort. This method is ignored if the new context enlists as a nonroot transaction or does not use transactions.

## See also

[IServiceTransactionConfigBase](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfigbase)