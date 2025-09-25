# PowerSettingAccessCheck function

## Description

Queries for a group policy override for specified power settings.

## Parameters

### `AccessFlags` [in]

The type of access to check for group policy overrides.

| Value | Meaning |
| --- | --- |
| **ACCESS_AC_POWER_SETTING_INDEX**<br><br>0 (0x0) | Check for overrides on AC power settings. |
| **ACCESS_DC_POWER_SETTING_INDEX**<br><br>1 (0x1) | Check for overrides on DC power settings. |
| **ACCESS_SCHEME**<br><br>16 (0x10) | Check for restrictions on specific power schemes. |
| **ACCESS_ACTIVE_SCHEME**<br><br>19 (0x13) | Check for restrictions on active power schemes. |
| **ACCESS_CREATE_SCHEME**<br><br>20 (0x14) | Check for restrictions on creating or restoring power schemes. |

### `PowerGuid` [in, optional]

The identifier of the power setting.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 (0x0) | The specified power setting is not currently overridden by a group policy. |
| **ERROR_ACCESS_DISABLED_BY_POLICY**<br><br>1260 (0x4EC) | This program is blocked by group policy. For more information, contact your system administrator. |
| **ERROR_INSTALL_REMOTE_DISALLOWED**<br><br>1640 (0x668) | Only Administrators can remotely access power settings. |

## See also

[POWER_DATA_ACCESSOR](https://learn.microsoft.com/windows/desktop/api/powrprof/ne-powrprof-power_data_accessor)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)