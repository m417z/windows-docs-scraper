# IComLTxEvents::OnLtxTransactionAbort

## Description

Generated when a transaction is aborted.

The event ID for this event is EID_LTXABORT.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidLtx` [in]

A GUID that identifies the transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)