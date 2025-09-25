# GetCurrentClockTransactionManager function

## Description

Obtains a virtual clock value from a transaction manager.

## Parameters

### `TransactionManagerHandle` [in]

A handle to the transaction manager to obtain a virtual clock value for.

### `TmVirtualClock` [out]

The latest virtual clock value for the transaction manager. See [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[CommitComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-commitcomplete)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[PrepareComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-preparecomplete)

[PreprepareComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-prepreparecomplete)

[ReadOnlyEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-readonlyenlistment)

[RollbackComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbackcomplete)

[RollbackEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbackenlistment)

[SinglePhaseReject](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-singlephasereject)