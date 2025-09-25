# CommitComplete function

## Description

Indicates that a resource manager (RM) has finished committing a transaction that was requested by the transaction manager (TM).

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment for which the commit operation is completed.

### `TmVirtualClock` [in]

The latest virtual clock value received for this transaction. If you specify **NULL**, the virtual clock value is not changed. See [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

To change the virtual clock value, this value must be greater than the current value returned in the COMMIT notification.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## See also

[CreateEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createenlistment)

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)