# WLAN_BSS_ENTRY structure

## Description

The **WLAN_BSS_ENTRY** structure contains information about a basic service set (BSS).

## Members

### `dot11Ssid`

The SSID of the access point (AP) or peer station associated with the BSS. The data type for this member is a [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure.

### `uPhyId`

The identifier (ID) of the PHY that the wireless LAN interface used to detect the BSS network.

### `dot11Bssid`

The media access control (MAC) address of the access point for infrastructure BSS networks or the peer station for independent BSS networks (ad hoc networks) that sent the 802.11 Beacon or Probe Response frame received by the wireless LAN interface while scanning. The data type for this member is a [DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-mac-address-type) structure.

### `dot11BssType`

The BSS network type. The data type for this member is a [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) enumeration value.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **dot11_BSS_type_infrastructure**<br><br>1 | Specifies an infrastructure BSS network. |
| **dot11_BSS_type_independent**<br><br>2 | Specifies an independent BSS (IBSS) network (an ad hoc network). |

### `dot11BssPhyType`

The PHY type for this network. The data type for this member is a [DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type) enumeration value.

### `lRssi`

The received signal strength indicator (RSSI) value, in units of decibels referenced to 1.0 milliwatts (dBm), as detected by the wireless LAN interface driver for the AP or peer station.

### `uLinkQuality`

The link quality reported by the wireless LAN interface driver. The link quality value ranges from 0 through 100. A value of 100 specifies the highest link quality.

### `bInRegDomain`

A value that specifies whether the AP or peer station is operating within the regulatory domain as identified by the country/region.

If the wireless LAN interface driver does not support multiple regulatory domains, this member is set to **TRUE**.

If the 802.11 Beacon or Probe Response frame received from the AP or peer station does not include a Country information element (IE), this member is set to **TRUE**.

If the 802.11 Beacon or Probe Response frame received from the AP or peer station does include a Country IE, this member is set to **FALSE** if the value of the Country String subfield does not equal the input country string.

### `usBeaconPeriod`

The value of the Beacon Interval field from the 802.11 Beacon or Probe Response frame received by the wireless LAN interface.

The interval is in 1,024 microsecond time units between target beacon transmission
times. This information is retrieved from the beacon packet sent by an access point in an infrastructure BSS network or a probe response from an access point or peer station in response to a wireless LAN client sending a Probe Request.

The IEEE 802.11 standard defines a unit of time as equal to 1,024 microseconds. This unit was defined so that it could be easily implemented in hardware.

### `ullTimestamp`

The value of the Timestamp field from the 802.11 Beacon or Probe Response frame received by the wireless LAN interface.

### `ullHostTimestamp`

The host timestamp value that records when wireless LAN interface received the Beacon or Probe Response frame. This member is a count of 100-nanosecond intervals since January 1, 1601.

For more information, see the **NdisGetCurrentSystemTime** function documented in the WDK.

### `usCapabilityInformation`

The value of the Capability Information field from the 802.11 Beacon or Probe Response frame received by the wireless LAN interface. This value is a set of bit flags defining the capability.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ESS**<br><br>bit 0 | An extended service set. A set of one or more interconnected basic service sets (BSSs) and integrated local area networks (LANs) that appears as a single BSS to the logical link control layer at any station associated with one of those BSSs.<br><br>An AP set the ESS subfield to 1 and the IBSS subfield to 0 within transmitted Beacon or Probe Response frames. A peer station within an IBSS (ad hoc network) sets the ESS subfield to 0 and the IBSS subfield to 1 in transmitted Beacon or Probe Response frames. |
| **IBSS**<br><br>bit 1 | An independent basic service set. A BSS that forms a self-contained network, and in which no access to a distribution system (DS) is available (an ad hoc network).<br><br>An AP sets the ESS subfield to 1 and the IBSS subfield to 0 within transmitted Beacon or Probe Response frames. A peer station within an IBSS (ad hoc network) sets the ESS subfield to 0 and the IBSS subfield to 1 in transmitted Beacon or Probe Response frames. |
| **CF-Pollable**<br><br>bit 2 | A value that indicates if the AP or peer station is pollable. |
| **CF Poll Request**<br><br>bit 3 | A value that indicates how the AP or peer station handles poll requests. |
| **Privacy**<br><br>bit 4 | A value that indicates if encryption is required for all data frames. <br><br>An AP sets the Privacy subfield to 1 within transmitted Beacon and Probe Response frames if WEP, WPA, or WPA2 encryption is required for all data type frames exchanged within the BSS. If WEP, WPA, or WPA2 encryption is not required, the Privacy subfield is set to 0.<br><br>A peer station within and IBSS sets the Privacy subfield to 1 within transmitted Beacon and Probe Response frames if WEP, WPA, or WPA2 encryption is required for all data type frames exchanged within the IBSS. If WEP, WPA, or WPA2 encryption is not required, the Privacy subfield is set to 0. |

### `ulChCenterFrequency`

The channel center frequency of the band on which the 802.11 Beacon or Probe Response frame was received. The value of **ulChCenterFrequency** is in units of kilohertz (kHz).

**Note** This member is only valid for PHY types that are not frequency-hopping spread spectrum (FHSS).

### `wlanRateSet`

A set of data transfer rates supported by the BSS. The data type for this member is a [WLAN_RATE_SET](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_rate_set) structure.

### `ulIeOffset`

The offset, in bytes, of the information element (IE) data blob from the beginning of the **WLAN_BSS_ENTRY** structure.

This member points to a buffer that contains variable-length information elements (IEs) from the 802.11 Beacon or Probe Response frames. For each BSS, the IEs are from the last Beacon or Probe Response frame received from that BSS network. If an IE is available in only one frame, the wireless LAN interface driver merges the IE with the other IEs from the last received Beacon or Probe Response frame.

Information elements are defined in the IEEE 802.11 specifications to have a common general format consisting of a 1-byte Element ID field, a 1-byte Length field, and a variable-length element-specific information field. Each information element is assigned a unique
Element ID value as defined in this IEEE 802.11 standards. The Length field specifies the number of bytes in the information
field.

### `ulIeSize`

The size, in bytes, of the IE data blob in the **WLAN_BSS_ENTRY** structure.

This is the exact length of the data in the buffer pointed to by **ulIeOffset** member and does not contain any padding for alignment. The maximum value for the size of the IE data blob is 2,324 bytes.

## Remarks

The [WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) function retrieves the BSS list of the wireless network or networks on a given interface and returns this information in a [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) structure that contains an array of .**WLAN_BSS_ENTRY** structures.

When the wireless LAN interface is also operating as a Wireless Hosted Network , the BSS list will contain an entry for the BSS created for the Wireless Hosted Network.

Since the information is returned by the access point for an infrastructure BSS network or by the network peer for an independent BSS network (ad hoc network), the information returned should not be trusted. The **ulIeOffset** and **ulIeSize** members in the **WLAN_BSS_ENTRY** structure should be used to determine the maximum size of the information element data blob in the **WLAN_BSS_ENTRY** structure, not the data in the information element data blob.

## See also

[WLAN_AVAILABLE_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network)

[WLAN_AVAILABLE_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network_list)

[WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list)

[WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist)

[WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist)