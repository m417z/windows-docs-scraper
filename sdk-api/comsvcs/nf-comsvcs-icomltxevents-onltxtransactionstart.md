# IComLTxEvents::OnLtxTransactionStart

## Description

Generated when a transaction is started.

The event ID for this event is EID_LTXSTART.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidLtx` [in]

A GUID that identifies the transaction.

### `tsid` [in]

A GUID that identifies the COM+ transaction context.

### `fRoot` [in]

Indicates whether the COM+ transaction context is a root transaction context.

### `nIsolationLevel` [in]

The transaction isolation level of the root COM+ transactional context.

## Return value

The user verifies the return values from this method.

## See also

[IComLTxEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomltxevents)