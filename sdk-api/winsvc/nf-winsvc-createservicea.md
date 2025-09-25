# CreateServiceA function

## Description

Creates a service object and adds it to the specified service control manager database.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database. This handle is returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function and must have the **SC_MANAGER_CREATE_SERVICE** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `lpServiceName` [in]

The name of the service to install. The maximum string length is 256 characters. The service control manager database preserves the case of the characters, but service name comparisons are always case insensitive. Forward-slash (/) and backslash (\\) are not valid service name characters.

### `lpDisplayName` [in, optional]

The display name to be used by user interface programs to identify the service. This string has a maximum length of 256 characters. The name is case-preserved in the service control manager. Display name comparisons are always case-insensitive.

### `dwDesiredAccess` [in]

The access to the service. Before granting the requested access, the system checks the access token of the calling process. For a list of values, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwServiceType` [in]

The service type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ADAPTER**<br><br>0x00000004 | Reserved. |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | File system driver service. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | Driver service. |
| **SERVICE_RECOGNIZER_DRIVER**<br><br>0x00000008 | Reserved. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | Service that runs in its own process. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | Service that shares a process with one or more other services. For more information, see [Service Programs](https://learn.microsoft.com/windows/desktop/Services/service-programs). |

If you specify either **SERVICE_WIN32_OWN_PROCESS** or **SERVICE_WIN32_SHARE_PROCESS**, and the service is running in the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), you can also specify the following value.

| Value | Meaning |
| --- | --- |
| **SERVICE_INTERACTIVE_PROCESS**<br><br>0x00000100 | The service can interact with the desktop. <br><br>For more information, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services). |

### `dwStartType` [in]

The service start options. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_AUTO_START**<br><br>0x00000002 | A service started automatically by the service control manager during system startup. For more information, see [Automatically Starting Services](https://learn.microsoft.com/windows/desktop/Services/automatically-starting-services). |
| **SERVICE_BOOT_START**<br><br>0x00000000 | A device driver started by the system loader. This value is valid only for driver services. |
| **SERVICE_DEMAND_START**<br><br>0x00000003 | A service started by the service control manager when a process calls the [StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function. For more information, see [Starting Services on Demand](https://learn.microsoft.com/windows/desktop/Services/starting-services-on-demand). |
| **SERVICE_DISABLED**<br><br>0x00000004 | A service that cannot be started. Attempts to start the service result in the error code **ERROR_SERVICE_DISABLED**. |
| **SERVICE_SYSTEM_START**<br><br>0x00000001 | A device driver started by the **IoInitSystem** function. This value is valid only for driver services. |

### `dwErrorControl` [in]

The severity of the error, and action taken, if this service fails to start. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ERROR_CRITICAL**<br><br>0x00000003 | The startup program logs the error in the event log, if possible. If the last-known-good configuration is being started, the startup operation fails. Otherwise, the system is restarted with the last-known good configuration. |
| **SERVICE_ERROR_IGNORE**<br><br>0x00000000 | The startup program ignores the error and continues the startup operation. |
| **SERVICE_ERROR_NORMAL**<br><br>0x00000001 | The startup program logs the error in the event log but continues the startup operation. |
| **SERVICE_ERROR_SEVERE**<br><br>0x00000002 | The startup program logs the error in the event log. If the last-known-good configuration is being started, the startup operation continues. Otherwise, the system is restarted with the last-known-good configuration. |

### `lpBinaryPathName` [in, optional]

The fully qualified path to the service binary file. If the path contains a space, it must be quoted so that it is correctly interpreted. For example, "d:\\my share\\myservice.exe" should be specified as "\"d:\\my share\\myservice.exe\"".

The path can also include arguments for an auto-start service. For example, "d:\\myshare\\myservice.exe arg1 arg2". These arguments are passed to the service entry point (typically the **main** function).

If you specify a path on another computer, the share must be accessible by the computer account of the local computer because this is the security context used in the remote call. However, this requirement allows any potential vulnerabilities in the remote computer to affect the local computer. Therefore, it is best to use a local file.

### `lpLoadOrderGroup` [in, optional]

The names of the load ordering group of which this service is a member. Specify NULL or an empty string if the service does not belong to a group.

The startup program uses load ordering groups to load groups of services in a specified order with respect to the other groups. The list of load ordering groups is contained in the following registry value: **HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\ServiceGroupOrder**

### `lpdwTagId` [out, optional]

A pointer to a variable that receives a tag value that is unique in the group specified in the *lpLoadOrderGroup* parameter. Specify NULL if you are not changing the existing tag.

You can use a tag for ordering service startup within a load ordering group by specifying a tag order vector in the following registry value:**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\GroupOrderList**

Tags are only evaluated for driver services that have **SERVICE_BOOT_START** or **SERVICE_SYSTEM_START** start types.

### `lpDependencies` [in, optional]

A pointer to a double null-terminated array of null-separated names of services or load ordering groups that the system must start before this service. Specify NULL or an empty string if the service has no dependencies. Dependency on a group means that this service can run if at least one member of the group is running after an attempt to start all members of the group.

You must prefix group names with **SC_GROUP_IDENTIFIER** so that they can be distinguished from a service name, because services and service groups share the same name space.

### `lpServiceStartName` [in, optional]

The name of the account under which the service should run. If the service type is SERVICE_WIN32_OWN_PROCESS, use an account name in the form *DomainName*\*UserName*. The service process will be logged on as this user. If the account belongs to the built-in domain, you can specify .\*UserName*.

If this parameter is NULL,
**CreateService** uses the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account). If the service type specifies **SERVICE_INTERACTIVE_PROCESS**, the service must run in the LocalSystem account.

If this parameter is NT AUTHORITY\LocalService,
**CreateService** uses the
[LocalService account](https://learn.microsoft.com/windows/desktop/Services/localservice-account). If the parameter is NT AUTHORITY\NetworkService,
**CreateService** uses the
[NetworkService account](https://learn.microsoft.com/windows/desktop/Services/networkservice-account).

A shared process can run as any user.

If the service type is **SERVICE_KERNEL_DRIVER** or **SERVICE_FILE_SYSTEM_DRIVER**, the name is the driver object name that the system uses to load the device driver. Specify NULL if the driver is to use a default object name created by the I/O system.

A service can be configured to use a managed account or a virtual account. If the service is configured to use a managed service account, the name is the managed service account name. If the service is configured to use a virtual account, specify the name as NT SERVICE\*ServiceName*. For more information about managed service accounts and virtual accounts, see the [Service Accounts Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd548356(v=ws.10)).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Managed service accounts and virtual accounts are not supported until Windows 7 and Windows Server 2008 R2.

### `lpPassword` [in, optional]

The password to the account name specified by the *lpServiceStartName* parameter. Specify an empty string if the account has no password or if the service runs in the LocalService, NetworkService, or LocalSystem account. For more information, see
[Service Record List](https://learn.microsoft.com/windows/desktop/Services/service-record-list).

If the account name specified by the *lpServiceStartName* parameter is the name of a managed service account or virtual account name, the *lpPassword* parameter must be NULL.

Passwords are ignored for driver services.

## Return value

If the function succeeds, the return value is a handle to the service.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle to the SCM database does not have the **SC_MANAGER_CREATE_SERVICE** access right. |
| **ERROR_CIRCULAR_DEPENDENCY** | A circular service dependency was specified. |
| **ERROR_DUPLICATE_SERVICE_NAME** | The display name already exists in the service control manager database either as a service name or as another display name. |
| **ERROR_INVALID_HANDLE** | The handle to the specified service control manager database is invalid. |
| **ERROR_INVALID_NAME** | The specified service name is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter that was specified is invalid. |
| **ERROR_INVALID_SERVICE_ACCOUNT** | The user account name specified in the *lpServiceStartName* parameter does not exist. |
| **ERROR_SERVICE_EXISTS** | The specified service already exists in this database. |
| **ERROR_SERVICE_MARKED_FOR_DELETE** | The specified service already exists in this database and has been marked for deletion. |

## Remarks

The
**CreateService** function creates a service object and installs it in the service control manager database by creating a key with the same name as the service under the following registry key:**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services**

Information specified by
**CreateService**,
[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga), and
[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) is saved as values under this key. The following are examples of values stored for a service.

| Value | Description |
| --- | --- |
| **DependOnGroup** | Load-ordering groups on which this service depends, as specified by *lpDependencies*. |
| **DependOnService** | Services on which this service depends, as specified by *lpDependencies*. |
| **Description** | Description specified by [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a). |
| **DisplayName** | Display name specified by *lpDisplayName*. |
| **ErrorControl** | Error control specified by *dwErrorControl*. |
| **FailureActions** | Failure actions specified by [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a). |
| **Group** | Load ordering group specified by *lpLoadOrderGroup*. Note that setting this value can override the setting of the **DependOnService** value. |
| **ImagePath** | Name of binary file, as specified by *lpBinaryPathName*. |
| **ObjectName** | Account name specified by *lpServiceStartName*. |
| **Start** | When to start service, as specified by *dwStartType*. |
| **Tag** | Tag identifier specified by *lpdwTagId*. |
| **Type** | Service type specified by *dwServiceType*. |

Setup programs and the service itself can create additional subkeys for service-specific information.

The returned handle is only valid for the process that called
**CreateService**. It can be closed by calling the
[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle) function.

If you are creating services that share a process, avoid calling functions with process-wide effects, such as
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess). In addition, do not unload your service DLL.

#### Examples

For an example, see
[Installing a Service](https://learn.microsoft.com/windows/desktop/Services/installing-a-service).

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle)

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice)

[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex)

[Service Accounts Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd548356(v=ws.10))

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Installation, Removal, and Enumeration](https://learn.microsoft.com/windows/desktop/Services/service-installation-removal-and-enumeration)

[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)

[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea)