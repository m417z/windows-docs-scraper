# WLAN_ASSOCIATION_ATTRIBUTES structure

## Description

The **WLAN_ASSOCIATION_ATTRIBUTES** structure contains association attributes for a connection.

## Members

### `dot11Ssid`

A [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that contains the SSID of the association.

### `dot11BssType`

A [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) value that specifies whether the network is infrastructure or ad hoc.

### `dot11Bssid`

A [DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-mac-address-type) that contains the BSSID of the association.

### `dot11PhyType`

A [DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type) value that indicates the physical type of the association.

### `uDot11PhyIndex`

The position of the [DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type) value in the structure containing the list of PHY types.

### `wlanSignalQuality`

A percentage value that represents the signal quality of the network. **WLAN_SIGNAL_QUALITY** is of type **ULONG**. This member contains a value between 0 and 100. A value of 0 implies an actual RSSI signal strength of -100 dbm. A value of 100 implies an actual RSSI signal strength of -50 dbm. You can calculate the RSSI signal strength value for **wlanSignalQuality** values between 1 and 99 using linear interpolation.

### `ulRxRate`

Contains the receiving rate of the association.

### `ulTxRate`

Contains the transmission rate of the association.

## See also

[WLAN_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_attributes)