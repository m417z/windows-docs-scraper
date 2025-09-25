# QueryServiceDynamicInformation function

## Description

Retrieves dynamic information related to the current service start.

## Parameters

### `hServiceStatus` [in]

A service status handle provided by [RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

### `dwInfoLevel` [in]

Indicates the information level.

| Value | Meaning |
| --- | --- |
| **SERVICE_DYNAMIC_INFORMATION_LEVEL_START_REASON** | Indicates a request for dynamic information related to the current service start. |

### `ppDynamicInfo`

A dynamic information buffer. If this parameter is valid, the callback function must free the buffer after use with the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE. When this happens the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function should be called to retrieve the error code.

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)