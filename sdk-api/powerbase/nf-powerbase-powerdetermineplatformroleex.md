# PowerDeterminePlatformRoleEx function

## Description

Determines the computer role for the specified platform.

## Parameters

### `Version` [in]

The version of the [POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration for the platform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **POWER_PLATFORM_ROLE_VERSION** | The version of the [POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration for the current build target. |
| **POWER_PLATFORM_ROLE_V1** | The version of the [POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration for Windows 7, Windows Server 2008 R2, Windows Vista or Windows Server 2008.<br><br>Calling **PowerDeterminePlatformRoleEx** with this value returns the same result as calling [PowerDeterminePlatformRole](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdetermineplatformrole) on Windows 7, Windows Server 2008 R2, Windows Vista or Windows Server 2008. |
| **POWER_PLATFORM_ROLE_V2** | The version of the [POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration for Windows 8 and Windows Server 2012. |

## Return value

The return value is one of the values from the
specified version of the [POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration.

## Remarks

This function reads the ACPI Fixed ACPI Description Table (FADT) to determine the OEM preferred computer role. If that information is not available, the function looks for a battery. If at least one battery is available, the function returns **PlatformRoleMobile**. If no batteries are available, the function returns **PlatformRoleDesktop**.

If the OEM preferred computer role is not supported on the platform specified by the caller, the function returns the closest supported value. For example, calling the **PowerDeterminePlatformRoleEx** function with a *Version* of **POWER_PLATFORM_ROLE_V1** on a tablet device returns **PlatformRoleMobile**.

## See also

[POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[PowerDeterminePlatformRole](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdetermineplatformrole)