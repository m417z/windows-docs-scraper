# QueryServiceLockStatusA function

## Description

[This function has no effect as of Windows Vista.]

Retrieves the lock status of the specified service control manager database.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database. The
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function returns this handle, which must have the SC_MANAGER_QUERY_LOCK_STATUS access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `lpLockStatus` [out, optional]

A pointer to a
[QUERY_SERVICE_LOCK_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-query_service_lock_statusa) structure that receives the lock status of the specified database is returned, plus the strings to which its members point.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpLockStatus* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to return all the lock status information, if the function fails.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the SC_MANAGER_QUERY_LOCK_STATUS access right. |
| **ERROR_INSUFFICIENT_BUFFER** | There is more lock status information than would fit into the *lpLockStatus* buffer. The number of bytes required to get all the information is returned in the *pcbBytesNeeded* parameter. Nothing is written to *lpLockStatus*. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

## Remarks

The
**QueryServiceLockStatus** function returns a
[QUERY_SERVICE_LOCK_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-query_service_lock_statusa) structure that indicates whether the specified database is locked. If the database is locked, the structure provides the account name of the user that owns the lock and the length of time that the lock has been held.

A process calls the
[LockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-lockservicedatabase) function to acquire ownership of a service control manager database lock and the
[UnlockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-unlockservicedatabase) function to release the lock.

> [!NOTE]
> The winsvc.h header defines QueryServiceLockStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-lockservicedatabase)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[QUERY_SERVICE_LOCK_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-query_service_lock_statusa)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[UnlockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-unlockservicedatabase)