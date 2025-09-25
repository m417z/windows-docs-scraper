# EnumDependentServicesA function

## Description

Retrieves the name and status of each service that depends on the specified service; that is, the specified service must be running before the dependent services can run.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function, and it must have the **SERVICE_ENUMERATE_DEPENDENTS** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwServiceState` [in]

The state of the services to be enumerated. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ACTIVE**<br><br>0x00000001 | Enumerates services that are in the following states: **SERVICE_START_PENDING**, **SERVICE_STOP_PENDING**, **SERVICE_RUNNING**, **SERVICE_CONTINUE_PENDING**, **SERVICE_PAUSE_PENDING**, and **SERVICE_PAUSED**. |
| **SERVICE_INACTIVE**<br><br>0x00000002 | Enumerates services that are in the **SERVICE_STOPPED** state. |
| **SERVICE_STATE_ALL**<br><br>0x00000003 | Combines the following states: **SERVICE_ACTIVE** and **SERVICE_INACTIVE**. |

### `lpServices` [out, optional]

A pointer to an array of
[ENUM_SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_statusa) structures that receives the name and service status information for each dependent service in the database. The buffer must be large enough to hold the structures, plus the strings to which their members point.

The order of the services in this array is the reverse of the start order of the services. In other words, the first service in the array is the one that would be started last, and the last service in the array is the one that would be started first.

The maximum size of this array is 64,000 bytes. To determine the required size, specify **NULL** for this parameter and 0 for the *cbBufSize* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_MORE_DATA**. The *pcbBytesNeeded* parameter will receive the required size.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpServices* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to store the array of service entries. The variable only receives this value if the buffer pointed to by *lpServices* is too small, indicated by function failure and the **ERROR_MORE_DATA** error; otherwise, the contents of *pcbBytesNeeded* are undefined.

### `lpServicesReturned` [out]

A pointer to a variable that receives the number of service entries returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes may be set by the service control manager. Other error codes may be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the **SERVICE_ENUMERATE_DEPENDENTS** access right. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter that was specified is invalid. |
| **ERROR_MORE_DATA** | The buffer pointed to by *lpServices* is not large enough. The function sets the variable pointed to by *lpServicesReturned* to the actual number of service entries stored into the buffer. The function sets the variable pointed to by *pcbBytesNeeded* to the number of bytes required to store all of the service entries. |

## Remarks

The returned services entries are ordered in the reverse order of the start order, with group order taken into account. If you need to stop the dependent services, you can use the order of entries written to the *lpServices* buffer to stop the dependent services in the proper order.

#### Examples

For an example, see
[Stopping a Service](https://learn.microsoft.com/windows/desktop/Services/stopping-a-service).

> [!NOTE]
> The winsvc.h header defines EnumDependentServices as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[ENUM_SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-enum_service_statusa)

[EnumServicesStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusexa)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Installation, Removal, and Enumeration](https://learn.microsoft.com/windows/desktop/Services/service-installation-removal-and-enumeration)