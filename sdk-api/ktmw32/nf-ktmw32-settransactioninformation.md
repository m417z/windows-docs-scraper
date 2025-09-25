# SetTransactionInformation function

## Description

Sets the transaction information for the specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to the transaction. The handle must have the TRANSACTION_SET_INFORMATION permission to set the transaction information.

### `IsolationLevel` [in, optional]

Reserved; specify zero.

### `IsolationFlags` [in, optional]

Reserved.

### `Timeout` [in, optional]

The timeout value, in milliseconds, for this transaction.

### `Description` [in, optional]

The user-defined description of this transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction)

[GetTransactionInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-gettransactioninformation)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)