# CommitEnlistment function

## Description

Commits the transaction associated with this enlistment handle. This function is used by communication
resource managers (sometimes called superior transaction managers).

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment to commit.

### `TmVirtualClock` [in]

A pointer to the latest virtual clock value received for this enlistment. If you specify
**NULL**, the virtual clock value is not changed.

To change the virtual clock value, this value must be greater than the current value returned by a
subordinate TM.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[CommitComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-commitcomplete)

[CreateEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createenlistment)

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)