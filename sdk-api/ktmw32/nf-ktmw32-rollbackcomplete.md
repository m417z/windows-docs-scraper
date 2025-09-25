# RollbackComplete function

## Description

Indicates that the resource manager (RM) has successfully completed rolling back a transaction.

## Parameters

### `EnlistmentHandle` [in]

A handle the enlistment.

### `TmVirtualClock` [in]

The latest virtual clock value received for this transaction. See [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## Remarks

If the RM was not able to successfully roll back a transaction, the RM should request a full rollback by calling the [RollbackTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbacktransaction) function.

## See also

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)