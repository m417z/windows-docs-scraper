# WLAN_AUTOCONF_OPCODE enumeration

## Description

The **WLAN_AUTOCONF_OPCODE** enumerated type specifies an automatic configuration parameter.

## Constants

### `wlan_autoconf_opcode_start:0`

Not used.

### `wlan_autoconf_opcode_show_denied_networks`

The opcode used to set or query the parameter specifying whether user and group policy denied networks will be included in the available networks list.

### `wlan_autoconf_opcode_power_setting`

The opcode used to query the power settings.

### `wlan_autoconf_opcode_only_use_gp_profiles_for_allowed_networks`

The opcode used to query whether profiles not created by group policy can be used to connect to an allowed network with a matching group policy profile.

### `wlan_autoconf_opcode_allow_explicit_creds`

The opcode used to set or query whether the current wireless interface has shared user credentials allowed.

### `wlan_autoconf_opcode_block_period`

The opcode used to set or query the blocked period setting for the current wireless interface. The blocked period is the amount of time, in seconds, for which automatic connection to a wireless network will not be attempted after a previous failure.

### `wlan_autoconf_opcode_allow_virtual_station_extensibility`

The opcode used to set or query whether extensibility on a virtual station is allowed. By default, extensibility on a virtual station is allowed. The value for this opcode is persisted across reboots.

This enumeration value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

### `wlan_autoconf_opcode_end`

Not used.

## Remarks

The **WLAN_AUTOCONF_OPCODE** enumerated type is used by the Auto Configuration Module (ACM), the wireless configuration component supported on Windows Vista and later.

The **WLAN_AUTOCONF_OPCODE** specifies the possible values for the *OpCode* parameter passed to the [WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter) and [WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter) functions.

## See also

[WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter)

[WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter)