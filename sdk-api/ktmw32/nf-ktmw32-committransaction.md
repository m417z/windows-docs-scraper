# CommitTransaction function

## Description

Requests that the specified transaction be committed.

## Parameters

### `TransactionHandle` [in]

A handle to the transaction to be committed.

This handle must have been opened with the TRANSACTION_COMMIT access right. For more information, see [KTM Security and Access Rights](https://learn.microsoft.com/windows/desktop/Ktm/ktm-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

You can commit any transaction handle that has been opened or created using the TRANSACTION_COMMIT permission; any application can commit a transaction, not just the creator.

This function can only be called if the transaction is still active, not prepared, pre-prepared, or rolled back.

## See also

[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-opentransaction)

[RollbackTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbacktransaction)