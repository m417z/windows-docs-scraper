# ChangeServiceConfig2W function

## Description

Changes the optional configuration parameters of a service.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenServiceW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicew) or
[CreateServiceW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicew) function and must have the **SERVICE_CHANGE_CONFIG** access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

If the service controller handles the **SC_ACTION_RESTART** action, *hService* must have the **SERVICE_START** access right.

### `dwInfoLevel` [in]

The configuration information to be changed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_CONFIG_DELAYED_AUTO_START_INFO**<br><br>3 | The *lpInfo* parameter is a pointer to a [SERVICE_DELAYED_AUTO_START_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_delayed_auto_start_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_DESCRIPTION**<br><br>1 | The *lpInfo* parameter is a pointer to a [SERVICE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_descriptionw) structure. |
| **SERVICE_CONFIG_FAILURE_ACTIONS**<br><br>2 | The *lpInfo* parameter is a pointer to a [SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsw) structure.<br><br>If the service controller handles the **SC_ACTION_REBOOT** action, the caller must have the **SE_SHUTDOWN_NAME** [privilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges). For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges). |
| **SERVICE_CONFIG_FAILURE_ACTIONS_FLAG**<br><br>4 | The *lpInfo* parameter is a pointer to a [SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_PREFERRED_NODE**<br><br>9 | The *lpInfo* parameter is a pointer to a [SERVICE_PREFERRED_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preferred_node_info) structure.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_PRESHUTDOWN_INFO**<br><br>7 | The *lpInfo* parameter is a pointer to a [SERVICE_PRESHUTDOWN_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preshutdown_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO**<br><br>6 | The *lpInfo* parameter is a pointer to a [SERVICE_REQUIRED_PRIVILEGES_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_required_privileges_infow) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONFIG_SERVICE_SID_INFO**<br><br>5 | The *lpInfo* parameter is a pointer to a [SERVICE_SID_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_sid_info) structure. |
| **SERVICE_CONFIG_TRIGGER_INFO**<br><br>8 | The *lpInfo* parameter is a pointer to a [SERVICE_TRIGGER_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger_info) structure. This value is not supported by the ANSI version of **ChangeServiceConfig2**. <br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2. |
| **SERVICE_CONFIG_LAUNCH_PROTECTED**<br><br>12 | The *lpInfo* parameter is a pointer a [SERVICE_LAUNCH_PROTECTED_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_launch_protected_info) structure.<br><br>**Note** This value is supported starting with Windows 8.1. |

### `lpInfo` [in, optional]

A pointer to the new value to be set for the configuration information. The format of this data depends on the value of the *dwInfoLevel* parameter. If this value is **NULL**, the information remains unchanged.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ChangeServiceConfig2** function changes the optional configuration information for the specified service in the service control manager database. You can obtain the current optional configuration information by using the
[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2w) function.

You cannot set the **SERVICE_CONFIG_FAILURE_ACTIONS** value for a service that shares the service control manager's process. This includes all services whose executable image is "Services.exe".

You can change and query additional configuration information using the
[ChangeServiceConfigW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfigw) and
[QueryServiceConfigW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfigw) functions, respectively.

If a service is configured to restart after it finishes with an error, the service control manager queues the restart action to occur after the specified time delay. A queued restart action cannot be canceled. If the service is manually restarted and then stopped before the queued restart action occurs, the service will restart unexpectedly when the time delay elapses. The service must be explicitly disabled to prevent it from restarting.

The **SERVICE_CONFIG_LAUNCH_PROTECTED** value can be used to launch the service as protected. In order to launch the service as protected, the service must be signed with a special certificate.

SERVICE_CONFIG_LAUNCH_PROTECTED example:

```cpp
SERVICE_LAUNCH_PROTECTED_INFO Info;
SC_HANDLE hService;

Info.dwLaunchProtected = SERVICE_LAUNCH_PROTECTED_ANTIMALWARE_LIGHT;

hService = CreateService (...);

if (ChangeServiceConfig2(hService,
                        SERVICE_CONFIG_LAUNCH_PROTECTED,
                        &Info) == FALSE)
{
    Result = GetLastError();
}

```

#### Examples

For an example, see
[Changing a Service's Configuration](https://learn.microsoft.com/windows/desktop/Services/changing-a-service-configuration).

> [!NOTE]
> The winsvc.h header defines ChangeServiceConfig2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfigW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfigw)

[CreateServiceW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicew)

[OpenServiceW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicew)

[QueryServiceConfigW](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfigw)

[QueryServiceConfig2W](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2w)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[SERVICE_DELAYED_AUTO_START_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_delayed_auto_start_info)

[SERVICE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_descriptionw)

[SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsw)

[SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag)

[SERVICE_PRESHUTDOWN_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preshutdown_info)

[SERVICE_REQUIRED_PRIVILEGES_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_required_privileges_infow)

[SERVICE_SID_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_sid_info)

[Service Configuration](https://learn.microsoft.com/windows/desktop/Services/service-configuration)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)