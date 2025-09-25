# ITransactionProxy::Promote

## Description

Promotes a non-DTC transaction to a DTC transaction.

## Parameters

### `pTransaction` [out]

An implementation of **ITransaction** that represents the DTC transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

Reasons for promoting a non-DTC transaction to a DTC transaction include exporting the transaction and working with a Queued Moniker Recorder.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)