# WLAN_OPCODE_VALUE_TYPE enumeration

## Description

The **WLAN_OPCODE_VALUE_TYPE** enumeration specifies the origin of automatic configuration (auto config) settings.

## Constants

### `wlan_opcode_value_type_query_only:0`

The auto config settings were queried, but the origin of the settings was not determined.

### `wlan_opcode_value_type_set_by_group_policy`

The auto config settings were set by group policy.

### `wlan_opcode_value_type_set_by_user`

The auto config settings were set by the user.

### `wlan_opcode_value_type_invalid`

The auto config settings are invalid.

## Remarks

## See also

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter)