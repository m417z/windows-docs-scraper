# RollbackEnlistment function

## Description

Rolls back the specified transaction that is associated with an enlistment. This function cannot be called for read-only enlistments.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `TmVirtualClock` [in]

The latest virtual clock value received for this enlistment. See [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## Remarks

This function is used by an RM to roll back a transaction in which it is enlisted. All work associated with the transaction is rolled back.

Rollbacks are allowed by enlistments at any time before it issues a prepare complete notification.

## See also

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[ReadOnlyEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-readonlyenlistment)