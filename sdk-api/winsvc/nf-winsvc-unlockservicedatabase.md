# UnlockServiceDatabase function

## Description

[This function has no effect as of Windows Vista.]

Unlocks a service control manager database by releasing the specified lock.

## Parameters

### `ScLock` [in]

The lock, which is obtained from a previous call to the
[LockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-lockservicedatabase) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_SERVICE_LOCK** | The specified lock is invalid. |

## See also

[LockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-lockservicedatabase)

[QueryServiceLockStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicelockstatusa)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)