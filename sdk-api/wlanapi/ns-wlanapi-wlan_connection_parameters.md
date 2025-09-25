# WLAN_CONNECTION_PARAMETERS structure

## Description

The **WLAN_CONNECTION_PARAMETERS** structure specifies the parameters used when using the [WlanConnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanconnect) function.

## Members

### `wlanConnectionMode`

A [WLAN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_connection_mode) value that specifies the mode of connection.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_connection_mode_profile** value is supported.

### `strProfile.string`

### `strProfile`

Specifies the profile being used for the connection.

If **wlanConnectionMode** is set to **wlan_connection_mode_profile**, then **strProfile** specifies the name of the profile used for the connection. If **wlanConnectionMode** is set to **wlan_connection_mode_temporary_profile**, then **strProfile** specifies the XML representation of the profile used for the connection. If **wlanConnectionMode** is set to **wlan_connection_mode_discovery_secure** or **wlan_connection_mode_discovery_unsecure**, then **strProfile** should be set to **NULL**.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The profile must meet the compatibility criteria described in [Wireless Profile Compatibility](https://learn.microsoft.com/windows/desktop/NativeWiFi/wireless-profile-compatibility).

### `pDot11Ssid`

Pointer to a [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that specifies the SSID of the network to connect to. This parameter is optional. When set to **NULL**, all SSIDs in the profile will be tried. This parameter must not be **NULL** if [WLAN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_connection_mode) is set to **wlan_connection_mode_discovery_secure** or **wlan_connection_mode_discovery_unsecure**.

### `pDesiredBssidList`

Pointer to a [DOT11_BSSID_LIST](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bssid-list) structure that contains the list of basic service set (BSS) identifiers desired for the connection.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This member must be **NULL**.

### `dot11BssType`

A [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) value that indicates the BSS type of the network. If a profile is provided, this BSS type must be the same as the one in the profile.

### `dwFlags`

The following table shows flags used to specify the connection parameters.

| Constant | Value | Description |
| --- | --- | --- |
| WLAN_CONNECTION_HIDDEN_NETWORK | 0x00000001 | Connect to the destination network even if the destination is a hidden network. A hidden network does not broadcast its SSID. Do not use this flag if the destination network is an ad-hoc network.If the profile specified by **strProfile** is not **NULL**, then this flag is ignored and the [nonBroadcast](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-ssidconfig-wlanprofile-element#nonbroadcast) profile element determines whether to connect to a hidden network. |
| WLAN_CONNECTION_ADHOC_JOIN_ONLY | 0x00000002 | Do not form an ad-hoc network. Only join an ad-hoc network if the network already exists. Do not use this flag if the destination network is an infrastructure network. |
| WLAN_CONNECTION_IGNORE_PRIVACY_BIT | 0x00000004 | Ignore the privacy bit when connecting to the network. Ignoring the privacy bit has the effect of ignoring whether packets are encrypted and ignoring the method of encryption used. Only use this flag when connecting to an infrastructure network using a temporary profile. |
| WLAN_CONNECTION_EAPOL_PASSTHROUGH | 0x00000008 | Exempt EAPOL traffic from encryption and decryption. This flag is used when an application must send EAPOL traffic over an infrastructure network that uses Open authentication and WEP encryption. This flag must not be used to connect to networks that require 802.1X authentication. This flag is only valid when **wlanConnectionMode** is set to **wlan_connection_mode_temporary_profile**. Avoid using this flag whenever possible. |
| WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE | 0x00000010 | Automatically persist discovery profile on successful connection completion. This flag is only valid for wlan_connection_mode_discovery_secure or wlan_connection_mode_discovery_unsecure. The profile will be saved as an all user profile, with the name generated from the SSID using WlanUtf8SsidToDisplayName. If there is already a profile with the same name, a number will be appended to the end of the profile name. The profile will be saved with manual connection mode, unless WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE_CONNECTION_MODE_AUTO is also specified. |
| WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE_CONNECTION_MODE_AUTO | 0x00000020 | To be used in conjunction with WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE. The discovery profile will be persisted with automatic connection mode. |
| WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE_OVERWRITE_EXISTING | 0x00000040 | To be used in conjunction with WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE. The discovery profile will be persisted and attempt to overwrite an existing profile with the same name. |

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This member must be set to 0.

## See also

[WlanConnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanconnect)