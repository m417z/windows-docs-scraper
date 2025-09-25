# LockServiceDatabase function

## Description

[As of Windows Vista, this function is provided for application compatibility and has no effect on the database.]

Requests ownership of the service control manager (SCM) database lock. Only one process can own the lock at any specified time.

## Parameters

### `hSCManager` [in]

A handle to the SCM database. This handle is returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function, and must have the **SC_MANAGER_LOCK** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

## Return value

If the function succeeds, the return value is a lock to the specified SCM database.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the SCM. Other error codes can be set by registry functions that are called by the SCM.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the **SC_MANAGER_LOCK** access right. |
| **ERROR_INVALID_HANDLE** | The specified handle is not valid. |
| **ERROR_SERVICE_DATABASE_LOCKED** | The database is locked. |

## Remarks

A lock is a protocol used by setup and configuration programs and the SCM to serialize access to the service tree in the registry. The only time the SCM requests ownership of the lock is when it is starting a service.

A program that acquires the SCM database lock and fails to release it prevents the SCM from starting other services. Because of the severity of this issue, processes are no longer allowed to lock the database. For compatibility with older applications, the **LockServiceDatabase** function returns a lock but has no other effect.

**Windows Server 2003 and Windows XP:** Acquiring the SCM database lock prevents the SCM from starting a service until the lock is released. For example, a program that must configure several related services before any of them starts could call
**LockServiceDatabase** before configuring the first service. Alternatively, it could ensure that none of the services are started until the configuration has been completed.

A call to the
[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function to start a service in a locked database fails. No other SCM functions are affected by a lock.

The lock is held until the **SC_LOCK** handle is specified in a subsequent call to the
[UnlockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-unlockservicedatabase) function. If a process that owns a lock terminates, the SCM automatically cleans up and releases ownership of the lock.

Failing to release the lock can cause system problems. A process that acquires the lock should release it as soon as possible.

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[QueryServiceLockStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicelockstatusa)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)

[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea)

[UnlockServiceDatabase](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-unlockservicedatabase)