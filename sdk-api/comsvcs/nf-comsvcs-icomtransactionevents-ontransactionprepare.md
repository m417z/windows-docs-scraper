# IComTransactionEvents::OnTransactionPrepare

## Description

Generated when the prepare phase of the two-phase commit protocol of the transaction is completed.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidTx` [in]

The transaction identifier.

### `fVoteYes` [in]

The resource managers result concerning the outcome of the prepare phase.

## Return value

The user verifies the return values from this method.

## See also

[IComTransactionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransactionevents)