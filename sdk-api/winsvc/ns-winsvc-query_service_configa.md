# QUERY_SERVICE_CONFIGA structure

## Description

Contains configuration information for an installed service. It is used by the
[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga) function.

## Members

### `dwServiceType`

The type of service. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | File system driver service. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | Driver service. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | Service that runs in its own process. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | Service that shares a process with other services. |

If the value is **SERVICE_WIN32_OWN_PROCESS** or **SERVICE_WIN32_SHARE_PROCESS**, and the service is running in the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), the following type may also be specified.

| Value | Meaning |
| --- | --- |
| **SERVICE_INTERACTIVE_PROCESS**<br><br>0x00000100 | The service can interact with the desktop. <br><br>For more information, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services). |

### `dwStartType`

When to start the service. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_AUTO_START**<br><br>0x00000002 | A service started automatically by the service control manager during system startup. |
| **SERVICE_BOOT_START**<br><br>0x00000000 | A device driver started by the system loader. This value is valid only for driver services. |
| **SERVICE_DEMAND_START**<br><br>0x00000003 | A service started by the service control manager when a process calls the [StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function. |
| **SERVICE_DISABLED**<br><br>0x00000004 | A service that cannot be started. Attempts to start the service result in the error code **ERROR_SERVICE_DISABLED**. |
| **SERVICE_SYSTEM_START**<br><br>0x00000001 | A device driver started by the **IoInitSystem** function. This value is valid only for driver services. |

### `dwErrorControl`

The severity of the error, and action taken, if this service fails to start. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_ERROR_CRITICAL**<br><br>0x00000003 | The startup program logs the error in the event log, if possible. If the last-known good configuration is being started, the startup operation fails. Otherwise, the system is restarted with the last-known good configuration. |
| **SERVICE_ERROR_IGNORE**<br><br>0x00000000 | The startup program ignores the error and continues the startup operation. |
| **SERVICE_ERROR_NORMAL**<br><br>0x00000001 | The startup program logs the error in the event log and continues the startup operation. |
| **SERVICE_ERROR_SEVERE**<br><br>0x00000002 | The startup program logs the error in the event log. If the last-known good configuration is being started, the startup operation continues. Otherwise, the system is restarted with the last-known-good configuration. |

### `lpBinaryPathName`

The fully qualified path to the service binary file.

The path can also include arguments for an auto-start service. These arguments are passed to the service entry point (typically the **main** function).

### `lpLoadOrderGroup`

The name of the load ordering group to which this service belongs. If the member is NULL or an empty string, the service does not belong to a load ordering group.

The startup program uses load ordering groups to load groups of services in a specified order with respect to the other groups. The list of load ordering groups is contained in the following registry value:

**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\ServiceGroupOrder**

### `dwTagId`

A unique tag value for this service in the group specified by the *lpLoadOrderGroup* parameter. A value of zero indicates that the service has not been assigned a tag. You can use a tag for ordering service startup within a load order group by specifying a tag order vector in the registry located at:

**HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\GroupOrderList**

Tags are only evaluated for **SERVICE_KERNEL_DRIVER** and **SERVICE_FILE_SYSTEM_DRIVER** type services that have **SERVICE_BOOT_START** or **SERVICE_SYSTEM_START** start types.

### `lpDependencies`

A pointer to an array of null-separated names of services or load ordering groups that must start before this service. The array is doubly null-terminated. If the pointer is **NULL** or if it points to an empty string, the service has no dependencies. If a group name is specified, it must be prefixed by the **SC_GROUP_IDENTIFIER** (defined in WinSvc.h) character to differentiate it from a service name, because services and service groups share the same name space. Dependency on a service means that this service can only run if the service it depends on is running. Dependency on a group means that this service can run if at least one member of the group is running after an attempt to start all members of the group.

### `lpServiceStartName`

If the service type is **SERVICE_WIN32_OWN_PROCESS** or **SERVICE_WIN32_SHARE_PROCESS**, this member is the name of the account that the service process will be logged on as when it runs. This name can be of the form *Domain***\\***UserName*. If the account belongs to the built-in domain, the name can be of the form **.\\***UserName*. The name can also be "LocalSystem" if the process is running under the LocalSystem account.

If the service type is **SERVICE_KERNEL_DRIVER** or **SERVICE_FILE_SYSTEM_DRIVER**, this member is the driver object name (that is, \FileSystem\Rdr or \Driver\Xns) which the input and output (I/O) system uses to load the device driver. If this member is NULL, the driver is to be run with a default object name created by the I/O system, based on the service name.

### `lpDisplayName`

The display name to be used by service control programs to identify the service. This string has a maximum length of 256 characters. The name is case-preserved in the service control manager. Display name comparisons are always case-insensitive.

This parameter can specify a localized string using the following format:

@[*Path*\]*DLLName*,-*StrID*

The string with identifier *StrID* is loaded from *DLLName*; the *Path* is optional. For more information, see [RegLoadMUIString](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadmuistringa).

**Windows Server 2003 and Windows XP:** Localized strings are not supported until Windows Vista.

## Remarks

The configuration information for a service is initially specified when the service is created by a call to the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The information can be modified by calling the
[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga) function.

#### Examples

For an example, see
[Querying a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/querying-a-service-s-configuration).

> [!NOTE]
> The winsvc.h header defines QUERY_SERVICE_CONFIG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[QueryServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfiga)

[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea)