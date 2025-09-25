# ReadOnlyEnlistment function

## Description

Requests that the specified enlistment be converted to a read-only enlistment. A read-only enlistment cannot participate in the outcome of the transaction and is not durably recorded for recovery.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `TmVirtualClock` [in]

The latest virtual clock value received for this enlistment. If you specify **NULL**, the virtual clock value is not changed. See [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

To change the virtual clock value, this value must be greater than the current value returned in the COMMIT notification.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## Remarks

If a resource manager no longer needs to participate in a transaction without rolling back the transaction, it should call **ReadOnlyEnlistment** prior to closing the enlistment handle.

## See also

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[ReadOnlyEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-readonlyenlistment)