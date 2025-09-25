# OpenSCManagerA function

## Description

Establishes a connection to the service control manager on the specified computer and opens the specified service control manager database.

## Parameters

### `lpMachineName` [in, optional]

The name of the target computer. If the pointer is NULL or points to an empty string, the function connects to the service control manager on the local computer.

### `lpDatabaseName` [in, optional]

The name of the service control manager database. This parameter should be set to SERVICES_ACTIVE_DATABASE. If it is NULL, the SERVICES_ACTIVE_DATABASE database is opened by default.

### `dwDesiredAccess` [in]

The access to the service control manager. For a list of access rights, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

Before granting the requested access rights, the system checks the access token of the calling process against the discretionary access-control list of the security descriptor associated with the service control manager.

The SC_MANAGER_CONNECT access right is implicitly specified by calling this function.

## Return value

If the function succeeds, the return value is a handle to the specified service control manager database.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the SCM. Other error codes can be set by the registry functions that are called by the SCM.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The requested access was denied. |
| **ERROR_DATABASE_DOES_NOT_EXIST** | The specified database does not exist. |

## Remarks

When a process uses the
**OpenSCManager** function to open a handle to a service control manager database, the system performs a security check before granting the requested access. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

If the current user does not have proper access when connecting to a service on another computer, the **OpenSCManager** function call fails. To connect to a service remotely, call the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function with LOGON32_LOGON_NEW_CREDENTIALS and then call [ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) before calling **OpenSCManager**. For more information about connecting to services remotely, see [Services and RPC/TCP](https://learn.microsoft.com/windows/desktop/Services/services-and-rpc-tcp).

Only processes with Administrator privileges are able to open a database handle that can be used by the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function.

The returned handle is only valid for the process that called the
**OpenSCManager** function. It can be closed by calling the
[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle) function.

#### Examples

For an example, see
[Changing a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/changing-a-service-configuration).

> [!NOTE]
> The winsvc.h header defines OpenSCManager as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[EnumServicesStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusexa)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[SCM Handles](https://learn.microsoft.com/windows/desktop/Services/scm-handles)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)