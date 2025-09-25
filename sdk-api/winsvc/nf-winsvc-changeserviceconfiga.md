# ChangeServiceConfigA function

## Description

Changes the configuration parameters of a service.

To change the optional configuration parameters, use the
[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) function.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function and must have the **SERVICE_CHANGE_CONFIG** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwServiceType` [in]

The type of service. Specify **SERVICE_NO_CHANGE** if you are not changing the existing service type; otherwise, specify one of the following service types.

| Value | Meaning |
| --- | --- |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | File system driver service. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | Driver service. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | Service that runs in its own process. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | Service that shares a process with other services. |

If you specify either **SERVICE_WIN32_OWN_PROCESS** or **SERVICE_WIN32_SHARE_PROCESS**, and the service is running in the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), you can also specify the following type.

| Value | Meaning |
| --- | --- |
| **SERVICE_INTERACTIVE_PROCESS**<br><br>0x00000100 | The service can interact with the desktop. <br><br>For more information, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services). |

### `dwStartType` [in]

The service start options. Specify **SERVICE_NO_CHANGE** if you are not changing the existing start type; otherwise, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_AUTO_START**<br><br>0x00000002 | A service started automatically by the service control manager during system startup. |
| **SERVICE_BOOT_START**<br><br>0x00000000 | A device driver started by the system loader. This value is valid only for driver services. |
| **SERVICE_DEMAND_START**<br><br>0x00000003 | A service started by the service control manager when a process calls the [StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function. |
| **SERVICE_DISABLED**<br><br>0x00000004 | A service that cannot be started. Attempts to start the service result in the error code **ERROR_SERVICE_DISABLED**. |
| **SERVICE_SYSTEM_START**<br><br>0x00000001 | A device driver started by the **IoInitSystem** function. This value is valid only for driver services. |

### `dwErrorControl` [in]

The severity of the error, and action taken, if this service fails to start. Specify **SERVICE_NO_CHANGE** if you are not changing the existing error control; otherwise, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ERROR_CRITICAL**<br><br>0x00000003 | The startup program logs the error in the event log, if possible. If the last-known-good configuration is being started, the startup operation fails. Otherwise, the system is restarted with the last-known good configuration. |
| **SERVICE_ERROR_IGNORE**<br><br>0x00000000 | The startup program ignores the error and continues the startup operation. |
| **SERVICE_ERROR_NORMAL**<br><br>0x00000001 | The startup program logs the error in the event log but continues the startup operation. |
| **SERVICE_ERROR_SEVERE**<br><br>0x00000002 | The startup program logs the error in the event log. If the last-known-good configuration is being started, the startup operation continues. Otherwise, the system is restarted with the last-known-good configuration. |

### `lpBinaryPathName` [in, optional]

The fully qualified path to the service binary file. Specify NULL if you are not changing the existing path. If the path contains a space, it must be quoted so that it is correctly interpreted. For example, "d:\\my share\\myservice.exe" should be specified as "\"d:\\my share\\myservice.exe\"".

The path can also include arguments for an auto-start service. For example, "d:\\myshare\\myservice.exe arg1 arg2". These arguments are passed to the service entry point (typically the **main** function).

If you specify a path on another computer, the share must be accessible by the computer account of the local computer because this is the security context used in the remote call. However, this requirement allows any potential vulnerabilities in the remote computer to affect the local computer. Therefore, it is best to use a local file.

### `lpLoadOrderGroup` [in, optional]

The name of the load ordering group of which this service is a member. Specify NULL if you are not changing the existing group. Specify an empty string if the service does not belong to a group.

The startup program uses load ordering groups to load groups of services in a specified order with respect to the other groups. The list of load ordering groups is contained in the **ServiceGroupOrder** value of the following registry key:

**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control**

### `lpdwTagId` [out, optional]

A pointer to a variable that receives a tag value that is unique in the group specified in the *lpLoadOrderGroup* parameter. Specify NULL if you are not changing the existing tag.

You can use a tag for ordering service startup within a load ordering group by specifying a tag order vector in the **GroupOrderList** value of the following registry key:

**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control**

Tags are only evaluated for driver services that have **SERVICE_BOOT_START** or **SERVICE_SYSTEM_START** start types.

### `lpDependencies` [in, optional]

A pointer to a double null-terminated array of null-separated names of services or load ordering groups that the system must start before this service can be started. (Dependency on a group means that this service can run if at least one member of the group is running after an attempt to start all members of the group.) Specify NULL if you are not changing the existing dependencies. Specify an empty string if the service has no dependencies.

You must prefix group names with SC_GROUP_IDENTIFIER so that they can be distinguished from a service name, because services and service groups share the same name space.

### `lpServiceStartName` [in, optional]

The name of the account under which the service should run. Specify **NULL** if you are not changing the existing account name. If the service type is **SERVICE_WIN32_OWN_PROCESS**, use an account name in the form *DomainName*\*UserName*. The service process will be logged on as this user. If the account belongs to the built-in domain, you can specify .\*UserName* (note that the corresponding C/C++ string is ".\\*UserName*"). For more information, see
[Service User Accounts](https://learn.microsoft.com/windows/desktop/Services/service-user-accounts) and the warning in the Remarks section.

A shared process can run as any user.

If the service type is **SERVICE_KERNEL_DRIVER** or **SERVICE_FILE_SYSTEM_DRIVER**, the name is the driver object name that the system uses to load the device driver. Specify **NULL** if the driver is to use a default object name created by the I/O system.

A service can be configured to use a managed account or a virtual account. If the service is configured to use a managed service account, the name is the managed service account name. If the service is configured to use a virtual account, specify the name as NT SERVICE\*ServiceName*. For more information about managed service accounts and virtual accounts, see the [Service Accounts Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd548356(v=ws.10)).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Managed service accounts and virtual accounts are not supported until Windows 7 and Windows Server 2008 R2.

### `lpPassword` [in, optional]

The password to the account name specified by the *lpServiceStartName* parameter. Specify **NULL** if you are not changing the existing password. Specify an empty string if the account has no password or if the service runs in the LocalService, NetworkService, or LocalSystem account. For more information, see
[Service Record List](https://learn.microsoft.com/windows/desktop/Services/service-record-list).

If the account name specified by the *lpServiceStartName* parameter is the name of a managed service account or virtual account name, the *lpPassword* parameter must be **NULL**.

Passwords are ignored for driver services.

### `lpDisplayName` [in, optional]

The display name to be used by applications to identify the service for its users. Specify **NULL** if you are not changing the existing display name; otherwise, this string has a maximum length of 256 characters. The name is case-preserved in the service control manager. Display name comparisons are always case-insensitive.

This parameter can specify a localized string using the following format:

@[*path*\]*dllname*,-*strID*

The string with identifier *strID* is loaded from *dllname*; the *path* is optional. For more information, see [RegLoadMUIString](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadmuistringa).

**Windows Server 2003 and Windows XP:** Localized strings are not supported until Windows Vista.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes may be set by the service control manager. Other error codes may be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the **SERVICE_CHANGE_CONFIG** access right. |
| **ERROR_CIRCULAR_DEPENDENCY** | A circular service dependency was specified. |
| **ERROR_DUPLICATE_SERVICE_NAME** | The display name already exists in the service controller manager database, either as a service name or as another display name. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter that was specified is invalid. |
| **ERROR_INVALID_SERVICE_ACCOUNT** | The account name does not exist, or a service is specified to share the same binary file as an already installed service but with an account name that is not the same as the installed service. |
| **ERROR_SERVICE_MARKED_FOR_DELETE** | The service has been marked for deletion. |

## Remarks

The
**ChangeServiceConfig** function changes the configuration information for the specified service in the service control manager database. You can obtain the current configuration information by using the
[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga) function.

If the configuration is changed for a service that is running, with the exception of *lpDisplayName*, the changes do not take effect until the service is stopped. To update the credentials without having to restart the service, use the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function.

### Security Remarks

Setting the *lpServiceStartName* parameter changes the logon account of the service. This can cause problems. If you have registered a service principal name (SPN), it would now be registered on the wrong account. Similarly, if you have used an ACE to grant access to a service, it would now grant access to the wrong account.

#### Examples

For an example, see
[Changing a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/changing-a-service-configuration).

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[Service Accounts Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd548356(v=ws.10))

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea)