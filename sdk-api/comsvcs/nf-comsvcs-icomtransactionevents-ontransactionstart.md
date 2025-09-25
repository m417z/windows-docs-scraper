# IComTransactionEvents::OnTransactionStart

## Description

Generated when a Microsoft Distributed Transaction Coordinator (DTC) transaction starts.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidTx` [in]

The transaction identifier.

### `tsid` [in]

The transaction stream identifier; a unique identifier for correlation to objects.

### `fRoot` [in]

Indicates whether this is a root transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComTransactionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransactionevents)