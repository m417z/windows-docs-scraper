# RollbackTransaction function

## Description

 Requests that the specified transaction be rolled back. This function is synchronous.

## Parameters

### `TransactionHandle` [in]

A handle to the transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. The following list identifies the possible error codes:

## See also

[CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction)

[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-opentransaction)