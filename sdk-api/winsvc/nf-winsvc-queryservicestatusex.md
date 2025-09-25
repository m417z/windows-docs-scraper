# QueryServiceStatusEx function

## Description

Retrieves the current status of the specified service based on the specified information level.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) or
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) function, and it must have the SERVICE_QUERY_STATUS access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `InfoLevel` [in]

The service attributes to be returned. Use SC_STATUS_PROCESS_INFO to retrieve the service status information. The *lpBuffer* parameter is a pointer to a
[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure.

Currently, no other information levels are defined.

### `lpBuffer` [out, optional]

A pointer to the buffer that receives the status information. The format of this data depends on the value of the *InfoLevel* parameter.

The maximum size of this array is 8K bytes. To determine the required size, specify NULL for this parameter and 0 for the *cbBufSize* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER. The *pcbBytesNeeded* parameter will receive the required size.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpBuffer* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to store all status information, if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following errors can be returned.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_ACCESS_DENIED** | The handle does not have the SERVICE_QUERY_STATUS access right. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is too small for the [SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure. Nothing was written to the structure. |
| **ERROR_INVALID_PARAMETER** | The **cbSize** member of [SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) is not valid. |
| **ERROR_INVALID_LEVEL** | The *InfoLevel* parameter contains an unsupported value. |
| **ERROR_SHUTDOWN_IN_PROGRESS** | The system is shutting down; this function cannot be called. |

## Remarks

The
**QueryServiceStatusEx** function returns the most recent service status information reported to the service control manager. If the service just changed its status, it may not have updated the service control manager yet.

The process identifier returned in the [SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure is valid provided that the state of the service is one of SERVICE_RUNNING, SERVICE_PAUSE_PENDING, SERVICE_PAUSED, or SERVICE_CONTINUE_PENDING. If the service is in a SERVICE_START_PENDING or SERVICE_STOP_PENDING state, however, the process identifier may not be valid, and if the service is in the SERVICE_STOPPED state, it is never valid.

#### Examples

For an example, see
[Starting a Service](https://learn.microsoft.com/windows/desktop/Services/starting-a-service) or [Stopping a Service](https://learn.microsoft.com/windows/desktop/Services/stopping-a-service).

## See also

[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Startup](https://learn.microsoft.com/windows/desktop/Services/service-startup)