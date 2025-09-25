# WLAN_INTERFACE_CAPABILITY structure

## Description

The **WLAN_INTERFACE_CAPABILITY** structure contains information about the capabilities of an interface.

## Members

### `interfaceType`

A [WLAN_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_interface_type) value that indicates the type of the interface.

### `bDot11DSupported`

Indicates whether 802.11d is supported by the interface. If **TRUE**, 802.11d is supported.

### `dwMaxDesiredSsidListSize`

The maximum size of the SSID list supported by this interface.

### `dwMaxDesiredBssidListSize`

The maximum size of the basic service set (BSS) identifier list supported by this interface.

### `dwNumberOfSupportedPhys`

Contains the number of supported PHY types.

### `dot11PhyTypes`

An array of [DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type) values that specify the supported PHY types. WLAN_MAX_PHY_INDEX is set to 64.

## See also

[WlanGetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetinterfacecapability)