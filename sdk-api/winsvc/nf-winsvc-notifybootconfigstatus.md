# NotifyBootConfigStatus function

## Description

Reports the boot status to the service control manager. It is used by boot verification programs. This function can be called only by a process running in the LocalSystem or Administrator's account.

## Parameters

### `BootAcceptable` [in]

If the value is TRUE, the system saves the configuration as the last-known good configuration. If the value is FALSE, the system immediately reboots, using the previously saved last-known good configuration.

## Return value

If the *BootAcceptable* parameter is FALSE, the function does not return.

If the last-known good configuration was successfully saved, the return value is nonzero.

If an error occurs, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes may be set by the service control manager. Other error codes may be set by the registry functions that are called by the service control manager to set parameters in the configuration registry.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have permission to perform this operation. Only the system and members of the Administrator's group can do so. |

## Remarks

Saving the configuration of a running system with this function is an acceptable method for saving the last-known good configuration. If the boot configuration is unacceptable, use this function to reboot the system using the existing last-known good configuration.

This function call requires the caller's token to have permission to acquire the SC_MANAGER_MODIFY_BOOT_CONFIG access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

## See also

[Automatically Starting Services](https://learn.microsoft.com/windows/desktop/Services/automatically-starting-services)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)