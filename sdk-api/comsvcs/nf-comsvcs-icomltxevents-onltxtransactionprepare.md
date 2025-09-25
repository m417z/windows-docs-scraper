# IComLTxEvents::OnLtxTransactionPrepare

## Description

Generated when COM+ receives a prepare notification for a transaction.

The event ID for this event is EID_LTXPREPARE.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidLtx` [in]

A GUID that identifies the transaction.

### `fVote` [in]

The COM+ vote for the prepare request.

## Return value

The user verifies the return values from this method.

## See also

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)