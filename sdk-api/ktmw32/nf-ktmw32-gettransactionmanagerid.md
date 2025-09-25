# GetTransactionManagerId function

## Description

Obtains an identifier for the specified transaction manager.

## Parameters

### `TransactionManagerHandle` [in]

A handle to the transaction manager.

### `TransactionManagerId` [out]

A pointer to a variable that receives the identifier for the transaction manager.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-opentransactionmanager)