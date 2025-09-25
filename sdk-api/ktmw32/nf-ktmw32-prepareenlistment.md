# PrepareEnlistment function

## Description

Prepares the transaction associated with this enlistment handle. This function is used by
communication resource managers (sometimes called superior transaction managers).

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment for which the prepare operation has completed.

### `TmVirtualClock` [in]

A pointer to the latest virtual clock value received for this transaction.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[PrePrepareEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-preprepareenlistment)

[ReadOnlyEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-readonlyenlistment)

[SinglePhaseReject](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-singlephasereject)