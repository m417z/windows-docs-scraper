# OpenServiceW function

## Description

Opens an existing service.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database. The
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function returns this handle. For more information, see [Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `lpServiceName` [in]

The name of the service to be opened. This is the name specified by the *lpServiceName* parameter of the [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function when the service object was created, not the service display name that is shown by user interface applications to identify the service.

The maximum string length is 256 characters. The service control manager database preserves the case of the characters, but service name comparisons are always case insensitive. Forward-slash (/) and backslash (\\) are invalid service name characters.

### `dwDesiredAccess` [in]

The access to the service. For a list of access rights, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

Before granting the requested access, the system checks the access token of the calling process against the discretionary access-control list of the security descriptor associated with the service object.

## Return value

If the function succeeds, the return value is a handle to the service.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Others can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have access to the service. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_NAME** | The specified service name is invalid. |
| **ERROR_SERVICE_DOES_NOT_EXIST** | The specified service does not exist. |

## Remarks

The returned handle is only valid for the process that called
**OpenService**. It can be closed by calling the
[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle) function.

To use **OpenService**, no privileges are required aside from **SC_MANAGER_CONNECT**.

#### Examples

For an example, see
[Starting a Service](https://learn.microsoft.com/windows/desktop/Services/starting-a-service).

> [!NOTE]
> The winsvc.h header defines OpenService as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle)

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice)

[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex)

[SCM Handles](https://learn.microsoft.com/windows/desktop/Services/scm-handles)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)

[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea)