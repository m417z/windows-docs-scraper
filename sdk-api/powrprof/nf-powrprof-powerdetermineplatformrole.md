# PowerDeterminePlatformRole function

## Description

Determines the computer role for Windows 7, Windows Server 2008 R2, Windows Vista or Windows Server 2008. To specify a different platform, use the [PowerDeterminePlatformRoleEx](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerdetermineplatformroleex) function.

To query additional power platform roles defined after Windows 7 and Windows Server 2008 R2, use [PowerDeterminePlatformRoleEx](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerdetermineplatformroleex).

## Return value

The return value is one of the values from the
[POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role) enumeration.

## Remarks

This function reads the ACPI Fixed ACPI Description Table (FADT) to determine the OEM preferred computer role. If that information is not available, the function looks for a battery. If at least one battery is available, the function returns **PlatformRoleMobile**. If no batteries are available, the function returns **PlatformRoleDesktop**.

**Note** This API has a newer version. To query additional power platform roles defined after Windows 7 and Windows Server 2008 R2, use [PowerDeterminePlatformRoleEx](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerdetermineplatformroleex).

## See also

[POWER_PLATFORM_ROLE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-power_platform_role)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[PowerDeterminePlatformRoleEx](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerdetermineplatformroleex)