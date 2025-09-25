# IComLTxEvents::OnLtxTransactionCommit

## Description

Generated when a transaction is committed.

The event ID for this event is EID_LTXCOMMIT.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidLtx` [in]

A GUID that identifies the transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)