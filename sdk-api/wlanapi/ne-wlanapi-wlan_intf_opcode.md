## Description

Defines constants that specify various opcodes used to set and query parameters on a wireless interface. These constants represent the possible opcodes that you can pass in the *OpCode* parameter to the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) and [WlanSetInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetinterface) functions to query or set parameters on a wireless interface.

## Constants

### `wlan_intf_opcode_autoconf_start:0x000000000`

Not used.

### `wlan_intf_opcode_autoconf_enabled`

The opcode used to set or query whether auto config is enabled.

### `wlan_intf_opcode_background_scan_enabled`

The opcode used to set or query whether background scan is enabled.

Background scan can only be disabled when the interface is in the connected state. Background scan is disabled if at least one client disables it.
If the interface gets disconnected, background scan will be enabled automatically.

### `wlan_intf_opcode_media_streaming_mode`

The opcode used to set or query the media streaming mode of the driver.

The media streaming mode can only be set when the interface is in the connected state. The media streaming mode is enabled if at least one client enables it. If the interface gets disconnected, the media streaming mode is disabled automatically

### `wlan_intf_opcode_radio_state`

The opcode used to set or query the radio state.

### `wlan_intf_opcode_bss_type`

The opcode used to set or query the BSS type of the interface.

### `wlan_intf_opcode_interface_state`

The opcode used to query the state of the interface. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_current_connection`

The opcode used to query information about the current connection of the interface.

This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function. If the interface is in disconnected or disconnecting state, **WlanQueryInterface** function returns **ERROR_INVALID_STATE**.

### `wlan_intf_opcode_channel_number`

The opcode used to query the current channel on which the wireless interface is operating. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs`

The opcode used to query the supported auth/cipher pairs for infrastructure mode. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_supported_adhoc_auth_cipher_pairs`

The opcode used to query the supported auth/cipher pairs for ad hoc mode. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_supported_country_or_region_string_list`

The opcode used to query the list of supported country or region strings. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_current_operation_mode`

The opcode used to set or query the current operation mode of the wireless interface. For more information about operation modes, see [Native 802.11 Operation Modes](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/native-802-11-operation-modes).

### `wlan_intf_opcode_supported_safe_mode`

The opcode used to query whether the miniport/NIC combination supports Federal Information Processing Standards (FIPS) mode. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function. FIPS mode is also known as safe mode. This wireless safe mode is different than the operating system safe mode.

### `wlan_intf_opcode_certified_safe_mode`

The opcode used to query whether the miniport/NIC combination is FIPS certified. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_hosted_network_capable`

The opcode used to query for Hosted Network support in the device driver associated with the Wireless interface. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

The data type returned for this opcode by a query is a Boolean. A value returned of **TRUE** indicates Hosted Network is supported. A value of **FALSE** indicates Hosted Network is not supported.

This value is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

### `wlan_intf_opcode_management_frame_protection_capable`

The opcode used to query whether Management Frame Protection (MFP) is supported in the device driver associated with the Wireless interface. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

MFP is defined in the IEEE 802.11w-2009 amendment to 802.11 standard.

This value is supported on Windows 8 and on Windows Server 2012.

### `wlan_intf_opcode_secondary_sta_interfaces`

Allows clients to query information about the Secondary STA of a given interface. Returns a [WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_interface_info_list) of Secondary STAs on the given interface.

### `wlan_intf_opcode_secondary_sta_synchronized_connections`

Opcode used to query whether or not Secondary STA synchronized connections are enabled on the specified interface.

### `wlan_intf_opcode_realtime_connection_quality`

An opcode that allows clients to query attributes that describe the quality of the connection on the given interface. This API combines fields from various other existing WLAN APIs (**wlan_intf_opcode_current_connection** and [WlanGetNetworkBssList](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist)), but it omits location-sensitive information, and for that reason it doesn't require location access privileges.

This opcode retrieves a structure that contains attributes that describe the quality of the connection on the given interface. It will fail if the interface isn't connected. Your app can use this API to get information about the state and quality of its WiFi connection (the API has applications to streaming, video conferencing, and other network-quality-sensitive operations. Apps that currently use **wlan_intf_opcode_current_connection** and [WlanGetNetworkBssList](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) to retrieve connection quality information, but have no desire to request location access, can make use of this API.

For more info, see the code example in [WLAN_REALTIME_CONNECTION_QUALITY](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_realtime_connection_quality).

### `wlan_intf_opcode_qos_info`

An opcode that allows clients to query the state of the quality-of-service (QoS) features outlined by the [Wi-Fi Alliance's Wi-Fi QoS Management Specification](https://www.wi-fi.org/news-events/newsroom/wi-fi-alliance-improves-quality-of-service-for-real-time-wi-fi-applications), and defined in the [802.11 spec](https://standards.ieee.org/ieee/802.11/7028/).

This opcode retrieves a structure that contains information about the four features outlined in the [WFA's Wi-Fi QoS Management Specification](https://www.wi-fi.org/news-events/newsroom/wi-fi-alliance-improves-quality-of-service-for-real-time-wi-fi-applications), and defined in the [802.11 spec](https://standards.ieee.org/ieee/802.11/7028/). Your app can use this API to get information about its device's WFA QoS capabilities and, if connected, the WFA QoS capabilities of its peer and the state of the WFA QoS features configured for its current connection. An app that currently makes use of the QoS2 or other QoS APIs can use this to get additional QoS information for performance telemetry or UI display purposes. Using this API to inform behavior changes isn't its primary purpose.

For more info, see the code example in [WLAN_QOS_INFO](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_qos_info).

### `wlan_intf_opcode_autoconf_end:0x0fffffff`

Not used.

### `wlan_intf_opcode_msm_start:0x10000100`

Not used.

### `wlan_intf_opcode_statistics`

The opcode used to query driver statistics. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_rssi`

Opcode used to query the received signal strength. This opcode can only be used in a query operation with the [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface) function.

### `wlan_intf_opcode_msm_end:0x1fffffff`

Not used.

### `wlan_intf_opcode_security_start:0x20010000`

Not used.

### `wlan_intf_opcode_security_end:0x2fffffff`

Not used.

### `wlan_intf_opcode_ihv_start:0x30000000`

Not used.

### `wlan_intf_opcode_ihv_end:0x3fffffff`

Not used.

## Remarks

## See also

* [WlanQueryInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface)
* [WlanSetInterface](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetinterface)