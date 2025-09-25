# QUERY_SERVICE_LOCK_STATUSW structure

## Description

Contains information about the lock status of a service control manager database. It is used by the
[QueryServiceLockStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicelockstatusa) function.

## Members

### `fIsLocked`

The lock status of the database. If this member is nonzero, the database is locked. If it is zero, the database is unlocked.

### `lpLockOwner`

The name of the user who acquired the lock.

### `dwLockDuration`

The time since the lock was first acquired, in seconds.

## See also

[QueryServiceLockStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicelockstatusa)

## Remarks

> [!NOTE]
> The winsvc.h header defines QUERY_SERVICE_LOCK_STATUS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).