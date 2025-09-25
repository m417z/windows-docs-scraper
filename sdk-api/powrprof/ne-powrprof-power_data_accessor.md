# POWER_DATA_ACCESSOR enumeration

## Description

Enumeration values used by [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate)
and [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck).

## Constants

### `ACCESS_AC_POWER_SETTING_INDEX:0`

Used with [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) to
check for group policy overrides for AC power settings.

### `ACCESS_DC_POWER_SETTING_INDEX`

Used with [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) to
check for group policy overrides for DC power settings.

### `ACCESS_FRIENDLY_NAME`

### `ACCESS_DESCRIPTION`

### `ACCESS_POSSIBLE_POWER_SETTING`

### `ACCESS_POSSIBLE_POWER_SETTING_FRIENDLY_NAME`

### `ACCESS_POSSIBLE_POWER_SETTING_DESCRIPTION`

### `ACCESS_DEFAULT_AC_POWER_SETTING`

### `ACCESS_DEFAULT_DC_POWER_SETTING`

### `ACCESS_POSSIBLE_VALUE_MIN`

### `ACCESS_POSSIBLE_VALUE_MAX`

### `ACCESS_POSSIBLE_VALUE_INCREMENT`

### `ACCESS_POSSIBLE_VALUE_UNITS`

### `ACCESS_ICON_RESOURCE`

### `ACCESS_DEFAULT_SECURITY_DESCRIPTOR`

### `ACCESS_ATTRIBUTES`

### `ACCESS_SCHEME`

Used to enumerate power schemes with
[PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) and with
[PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) to check for
restricted access to specific power schemes.

### `ACCESS_SUBGROUP`

Used to enumerate subgroups with
[PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate).

### `ACCESS_INDIVIDUAL_SETTING`

Used to enumerate individual power settings with
[PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate).

### `ACCESS_ACTIVE_SCHEME`

Used with [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) to
check for group policy overrides for active power schemes.

### `ACCESS_CREATE_SCHEME`

Used with [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) to
check for restricted access for creating power schemes.

### `ACCESS_AC_POWER_SETTING_MAX`

### `ACCESS_DC_POWER_SETTING_MAX`

### `ACCESS_AC_POWER_SETTING_MIN`

### `ACCESS_DC_POWER_SETTING_MIN`

### `ACCESS_PROFILE`

### `ACCESS_OVERLAY_SCHEME`

### `ACCESS_ACTIVE_OVERLAY_SCHEME`

## See also

[Power Management Enumeration Types](https://learn.microsoft.com/windows/desktop/Power/power-management-enumeration-types)

[PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate)

[PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck)