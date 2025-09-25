# RollforwardTransactionManager function

## Description

Recovers information only to the specified virtual clock value.

## Parameters

### `TransactionManagerHandle` [in]

A handle to the transaction manager.

### `TmVirtualClock` [in]

A pointer to the latest virtual clock value received for this transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)