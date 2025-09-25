# POWER_PLATFORM_ROLE enumeration

## Description

Indicates the OEM's preferred power management profile. These values are read from the
Preferred_PM_Profile field of the Fixed ACPI Description Table (FADT). These values are returned by the
[PowerDeterminePlatformRole](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdetermineplatformrole) or [PowerDeterminePlatformRoleEx](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerdetermineplatformroleex)  function.

## Constants

### `PlatformRoleUnspecified:0`

The OEM did not specify a specific role.

### `PlatformRoleDesktop`

The OEM specified a desktop role.

### `PlatformRoleMobile`

The OEM specified a mobile role (for example, a laptop).

### `PlatformRoleWorkstation`

The OEM specified a workstation role.

### `PlatformRoleEnterpriseServer`

The OEM specified an enterprise server role.

### `PlatformRoleSOHOServer`

The OEM specified a single office/home office (SOHO) server role.

### `PlatformRoleAppliancePC`

The OEM specified an appliance PC role.

### `PlatformRolePerformanceServer`

The OEM specified a performance server role.

### `PlatformRoleSlate`

The OEM specified a tablet form factor role.

**Windows 7, Windows Server 2008 R2, Windows Vista or Windows Server 2008:** In version 1 of this enumeration, this value is equivalent to **PlatformRoleMaximum**. This value is supported in version 2 of this enumeration starting with Windows 8 and Windows Server 2012.

### `PlatformRoleMaximum`

Values equal to or greater than this value indicate an out of range value.

## See also

[Power Management Enumeration Types](https://learn.microsoft.com/windows/desktop/Power/power-management-enumeration-types)

[PowerDeterminePlatformRole](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdetermineplatformrole)