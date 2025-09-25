# RecoverTransactionManager function

## Description

Recovers a transaction manager's state from its log file.

## Parameters

### `TransactionManagerHandle` [in]

A handle to the transaction manager.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## Remarks

This function must be called after you call [CreateTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransactionmanager).

## See also

[CreateTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)