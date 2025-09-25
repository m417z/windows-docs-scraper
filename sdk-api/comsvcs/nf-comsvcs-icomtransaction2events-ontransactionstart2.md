# IComTransaction2Events::OnTransactionStart2

## Description

Generated when a Microsoft Distributed Transaction Coordinator (DTC) transaction starts.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidTx` [in]

The transaction identifier.

### `tsid` [in]

The transaction stream identifier for the correlation to objects.

### `fRoot` [in]

Indicates whether the transaction is a root transaction.

### `nIsolationLevel` [in]

The isolation level of the transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComTransaction2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtransaction2events)