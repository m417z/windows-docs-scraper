# QueryServiceStatus function

## Description

Retrieves the current status of the specified service.

This function has been superseded by the
[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex) function.
**QueryServiceStatusEx** returns the same information
**QueryServiceStatus** returns, with the addition of the process identifier and additional information for the service.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function, and it must have the SERVICE_QUERY_STATUS access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `lpServiceStatus` [out]

A pointer to a
[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status) structure that receives the status information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the SERVICE_QUERY_STATUS access right. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

The
**QueryServiceStatus** function returns the most recent service status information reported to the service control manager. If the service just changed its status, it may not have updated the service control manager yet.

## See also

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex)

[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Startup](https://learn.microsoft.com/windows/desktop/Services/service-startup)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)