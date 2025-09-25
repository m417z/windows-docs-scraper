# WLAN_STATISTICS structure

## Description

The **WLAN_STATISTICS** structure contains assorted statistics about an interface.

## Members

### `ullFourWayHandshakeFailures`

Indicates the number of 4-way handshake failures. This member is only valid if IHV Service is being used as the authentication service for the current network.

### `ullTKIPCounterMeasuresInvoked`

Indicates the number of TKIP countermeasures performed by an IHV Miniport driver. This count does not include TKIP countermeasures invoked by the operating system.

### `ullReserved`

Reserved for use by Microsoft.

### `MacUcastCounters`

A [WLAN_MAC_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_mac_frame_statistics) structure that contains MAC layer counters for unicast packets directed to the receiver of the NIC.

### `MacMcastCounters`

A [WLAN_MAC_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_mac_frame_statistics) structure that contains MAC layer counters for multicast packets directed to the current multicast address.

### `dwNumberOfPhys`

Contains the number of **WLAN_PHY_FRAME_STATISTICS** structures in the **PhyCounters** member.

### `PhyCounters.unique`

### `PhyCounters.size_is`

### `PhyCounters.size_is.dwNumberOfPhys`

### `PhyCounters`

An array of [WLAN_PHY_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_frame_statistics) structures that contain PHY layer counters.

## See also

[WLAN_MAC_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_mac_frame_statistics)

[WLAN_PHY_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_frame_statistics)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)