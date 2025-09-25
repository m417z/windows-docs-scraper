# GetTransactionId function

## Description

Obtains the identifier (ID) for the specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to the transaction.

### `TransactionId` [out]

A pointer to a variable that receives the ID of the transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)