# IComTransaction2Events::OnTransactionPrepare2

## Description

Generated when the transaction is in the prepare phase of the commit protocol.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidTx` [in]

The transaction identifier.

### `fVoteYes` [in]

The resource manager's result concerning the outcome of the prepare phase.

## Return value

The user verifies the return values from this method.

## See also

[IComTransaction2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransaction2events)