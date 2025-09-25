# OpenTransaction function

## Description

Opens an existing transaction.

## Parameters

### `dwDesiredAccess` [in]

The access to the transaction object. You must have read and write access to work with a transaction. See [Transaction Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/transaction-access-masks) for a list of valid values.

### `TransactionId` [in]

The GUID that identifies the transaction to be opened. This is commonly referred to as a unit of work for the transaction.

## Return value

If the function succeeds, the return value is a handle to the transaction.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

Clients close the transaction handle by using the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function. If the last transaction handle is closed without anyone calling the [CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction) function on the transaction, then the KTM implicitly rolls back the transaction.

## See also

[CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction)

[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[RollbackTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbacktransaction)

[Transaction Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/transaction-access-masks)