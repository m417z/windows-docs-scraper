# WLAN_AVAILABLE_NETWORK structure

## Description

The **WLAN_AVAILABLE_NETWORK** structure contains information about an available wireless network.

## Members

### `strProfileName`

Contains the profile name associated with the network. If the network does not have a profile, this member will be empty. If multiple profiles are associated with the network, there will be multiple entries with the same SSID in the visible network list. Profile names are case-sensitive. This string must be NULL-terminated.

### `dot11Ssid`

A [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that contains the SSID of the visible wireless network.

### `dot11BssType`

A [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) value that specifies whether the network is infrastructure or ad hoc.

### `uNumberOfBssids`

Indicates the number of BSSIDs in the network.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** **uNumberofBssids** is at most 1, regardless of the number of access points broadcasting the SSID.

### `bNetworkConnectable`

Indicates whether the network is connectable or not. If set to **TRUE**, the network is connectable, otherwise the network cannot be connected to.

### `wlanNotConnectableReason`

A WLAN_REASON_CODE value that indicates why a network cannot be connected to. This member is only valid when **bNetworkConnectable** is **FALSE**.

### `uNumberOfPhyTypes`

The number of PHY types supported on available networks. The maximum value of *uNumberOfPhyTypes* is **WLAN_MAX_PHY_TYPE_NUMBER**, which has a value of 8. If more than **WLAN_MAX_PHY_TYPE_NUMBER** PHY types are supported, *bMorePhyTypes* must be set to **TRUE**.

### `dot11PhyTypes`

Contains an array of [DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type) values that represent the PHY types supported by the available networks. When *uNumberOfPhyTypes* is greater than **WLAN_MAX_PHY_TYPE_NUMBER**, this array contains only the first **WLAN_MAX_PHY_TYPE_NUMBER** PHY types.

| Value | Meaning |
| --- | --- |
| **dot11_phy_type_unknown** | Specifies an unknown or uninitialized PHY type. |
| **dot11_phy_type_any** | Specifies any PHY type. |
| **dot11_phy_type_fhss** | Specifies a frequency-hopping spread-spectrum (FHSS) PHY. Bluetooth devices can use FHSS or an adaptation of FHSS. |
| **dot11_phy_type_dsss** | Specifies a direct sequence spread spectrum (DSSS) PHY. |
| **dot11_phy_type_irbaseband** | Specifies an infrared (IR) baseband PHY. |
| **dot11_phy_type_ofdm** | Specifies an orthogonal frequency division multiplexing (OFDM) PHY. 802.11a devices can use OFDM. |
| **dot11_phy_type_hrdsss** | Specifies a high-rate DSSS (HRDSSS) PHY. |
| **dot11_phy_type_erp** | Specifies an extended rate PHY (ERP). 802.11g devices can use ERP. |
| **dot11_phy_type_ht** | Specifies an 802.11n PHY type. |
| **dot11_phy_type_vht** | Specifies the 802.11ac PHY type. This is the very high throughput PHY type specified in IEEE 802.11ac.<br><br>This value is supported on Windows 8.1, Windows Server 2012 R2, and later. |
| **dot11_phy_type_IHV_start** | Specifies the start of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV). |
| **dot11_phy_type_IHV_end** | Specifies the end of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV). |

### `bMorePhyTypes`

Specifies if there are more than **WLAN_MAX_PHY_TYPE_NUMBER** PHY types supported.

When this member is set to **TRUE**, an application must call [WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) to get the complete list of PHY types. The returned [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) structure has an array of [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) structures. The *uPhyId* member of the **WLAN_BSS_ENTRY** structure contains the PHY type for an entry.

### `wlanSignalQuality`

A percentage value that represents the signal quality of the network. **WLAN_SIGNAL_QUALITY** is of type **ULONG**. This member contains a value between 0 and 100. A value of 0 implies an actual RSSI signal strength of -100 dbm. A value of 100 implies an actual RSSI signal strength of -50 dbm. You can calculate the RSSI signal strength value for **wlanSignalQuality** values between 1 and 99 using linear interpolation.

### `bSecurityEnabled`

Indicates whether security is enabled on the network. A value of **TRUE** indicates that security is enabled, otherwise it is not.

### `dot11DefaultAuthAlgorithm`

A [DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-auth-algorithm) value that indicates the default authentication algorithm used to join this network for the first time.

### `dot11DefaultCipherAlgorithm`

A [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-cipher-algorithm) value that indicates the default cipher algorithm to be used when joining this network.

### `dwFlags`

Contains various flags for the network.

| Value | Meaning |
| --- | --- |
| **WLAN_AVAILABLE_NETWORK_CONNECTED** | This network is currently connected. |
| **WLAN_AVAILABLE_NETWORK_HAS_PROFILE** | There is a profile for this network. |

### `dwReserved`

Reserved for future use. Must be set to **NULL**.

## See also

[WLAN_AVAILABLE_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network_list)