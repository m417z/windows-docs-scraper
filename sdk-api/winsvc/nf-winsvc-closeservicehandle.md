# CloseServiceHandle function

## Description

Closes a handle to a service control manager or service object.

## Parameters

### `hSCObject` [in]

A handle to the service control manager object or the service object to close. Handles to service control manager objects are returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function, and handles to service objects are returned by either the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error code can be set by the service control manager. Other error codes can be set by registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

## Remarks

The
**CloseServiceHandle** function does not destroy the service control manager object referred to by the handle. A service control manager object cannot be destroyed. A service object can be destroyed by calling the
[DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice) function.

#### Examples

For an example, see
[Deleting a Service](https://learn.microsoft.com/windows/desktop/Services/deleting-a-service).

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[SCM Handles](https://learn.microsoft.com/windows/desktop/Services/scm-handles)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)