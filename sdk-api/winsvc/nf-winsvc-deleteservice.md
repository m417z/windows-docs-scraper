# DeleteService function

## Description

Marks the specified service for deletion from the service control manager database.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function, and it must have the DELETE access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes may be set by the service control manager. Others may be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the DELETE access right. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_SERVICE_MARKED_FOR_DELETE** | The specified service has already been marked for deletion. |

## Remarks

The
**DeleteService** function marks a service for deletion from the service control manager database. The database entry is not removed until all open handles to the service have been closed by calls to the
[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle) function, and the service is not running. A running service is stopped by a call to the
[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice) function with the SERVICE_CONTROL_STOP control code. If the service cannot be stopped, the database entry is removed when the system is restarted.

The service control manager deletes the service by deleting the service key and its subkeys from the registry.

#### Examples

For an example, see
[Deleting a Service](https://learn.microsoft.com/windows/desktop/Services/deleting-a-service).

## See also

[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle)

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Installation, Removal, and Enumeration](https://learn.microsoft.com/windows/desktop/Services/service-installation-removal-and-enumeration)