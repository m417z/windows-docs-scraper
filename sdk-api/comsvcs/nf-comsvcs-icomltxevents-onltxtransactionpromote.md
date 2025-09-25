# IComLTxEvents::OnLtxTransactionPromote

## Description

Generated when a transaction is promoted.

The event ID for this event is EID_LTXPROMOTE.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidLtx` [in]

A GUID that identifies the original transaction.

### `txnId` [in]

A GUID that identifies the promoted transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)