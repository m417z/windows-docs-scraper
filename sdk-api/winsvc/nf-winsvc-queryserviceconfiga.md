# QueryServiceConfigA function

## Description

Retrieves the configuration parameters of the specified service. Optional configuration parameters are available using the
[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a) function.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function, and it must have the SERVICE_QUERY_CONFIG access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `lpServiceConfig` [out, optional]

A pointer to a buffer that receives the service configuration information. The format of the data is a
[QUERY_SERVICE_CONFIG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-query_service_configa) structure.

The maximum size of this array is 8K bytes. To determine the required size, specify NULL for this parameter and 0 for the *cbBufSize* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER. The *pcbBytesNeeded* parameter will receive the required size.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpServiceConfig* parameter, in bytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to store all the configuration information, if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Others can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the SERVICE_QUERY_CONFIG access right. |
| **ERROR_INSUFFICIENT_BUFFER** | There is more service configuration information than would fit into the *lpServiceConfig* buffer. The number of bytes required to get all the information is returned in the *pcbBytesNeeded* parameter. Nothing is written to *lpServiceConfig*. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

## Remarks

The
**QueryServiceConfig** function returns the service configuration information kept in the registry for a particular service. This configuration information is first set by a service control program using the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. This information may have been updated by a service configuration program using the
[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga) function.

If the service was running when the configuration information was last changed, the information returned by
**QueryServiceConfig** will not reflect the current configuration of the service. Instead, it will reflect the configuration of the service when it is next run. The **DisplayName** key is an exception to this. When the **DisplayName** key is changed, it takes effect immediately, regardless of whether the service is running.

#### Examples

For an example, see
[Querying a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/querying-a-service-s-configuration).

> [!NOTE]
> The winsvc.h header defines QueryServiceConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QUERY_SERVICE_CONFIG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-query_service_configa)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)