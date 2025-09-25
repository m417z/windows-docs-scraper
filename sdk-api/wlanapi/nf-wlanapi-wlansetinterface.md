# WlanSetInterface function

## Description

The **WlanSetInterface** function sets user-configurable parameters for a specified interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface to be configured.

### `OpCode` [in]

A [WLAN_INTF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_intf_opcode) value that specifies the parameter to be set. The following table lists the valid constants along with the data type of the parameter in *pData*.

| **WLAN_INTF_OPCODE** value | *pData* data type | Description |
| --- | --- | --- |
| **wlan_intf_opcode_autoconf_enabled** | **BOOL** | Enables or disables auto config for the indicated interface. |
| **wlan_intf_opcode_background_scan_enabled** | **BOOL** | Enables or disables background scan for the indicated interface. |
| **wlan_intf_opcode_radio_state** | [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) | Sets the software radio state of a specific physical layer (PHY) for the interface. |
| **wlan_intf_opcode_bss_type** | [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) | Sets the BSS type. |
| **wlan_intf_opcode_media_streaming_mode** | **BOOL** | Sets media streaming mode for the driver. |
| **wlan_intf_opcode_current_operation_mode** | **ULONG** | Sets the current operation mode for the interface. For more information, see Remarks. |

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_intf_opcode_autoconf_enabled** and **wlan_intf_opcode_bss_type** constants are valid.

### `dwDataSize` [in]

The size of the *pData* parameter, in bytes. If *dwDataSize* is larger than the actual amount of memory allocated to *pData*, then an access violation will occur in the calling program.

### `pData` [in]

The value to be set as specified by the *OpCode* parameter. The type of data pointed to by *pData* must be appropriate for the specified *OpCode*. Use the table above to determine the type of data to use.

**Note** If *OpCode* is set to **wlan_intf_opcode_autoconf_enabled**, **wlan_intf_opcode_background_scan_enabled**, or **wlan_intf_opcode_media_streaming_mode**, then *pData* may point to an integer value. If *pData* points to 0, then the value is converted to **FALSE**. If *pData* points to a nonzero integer, then the value is converted to **TRUE**.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

## Remarks

When *OpCode* is set to **wlan_intf_opcode_current_operation_mode**, the **WlanSetInterface** function sets the current operation mode of the wireless interface. For more information about operation modes, see [Native 802.11 Operation Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes). Two operation modes are supported: **DOT11_OPERATION_MODE_EXTENSIBLE_STATION** and **DOT11_OPERATION_MODE_NETWORK_MONITOR**. The operation mode constants are defined in the header file Windot11.h. If *pData* does not point to one of these values when *OpCode* is set to **wlan_intf_opcode_current_operation_mode**, the **WlanSetInterface** function will fail with an error.

To enable or disable the automatic configuration service at the command line, which is functionally equivalent to calling **WlanSetInterface** with *OpCode* set to **wlan_intf_opcode_autoconf_enabled**, use the **netsh wlan setautoconfig** command. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

The software radio state can be changed by calling the **WlanSetInterface** function. The hardware radio state cannot be changed by calling the **WlanSetInterface** function. When the *OpCode* parameter is set to **wlan_intf_opcode_radio_state**, the **WlanSetInterface** function sets the software radio state of a specific PHY. The *pData* parameter must point to a [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) structure with the new radio state values to use. The **dot11HardwareRadioState** member of the **WLAN_PHY_RADIO_STATE** structure is ignored when the **WlanSetInterface** function is called with the *OpCode* parameter set to **wlan_intf_opcode_radio_state** and the *pData* parameter points to a **WLAN_PHY_RADIO_STATE** structure. The radio state of a PHY is off if either the software radio state (**dot11SoftwareRadioState** member of the **WLAN_PHY_RADIO_STATE** structure) or the hardware radio state (**dot11HardwareRadioState** member of the **WLAN_PHY_RADIO_STATE** structure) is off.

Changing the software radio state of a physical network interface could cause related changes in the state of the wireless Hosted Network or virtual wireless adapter radio states. The PHYs of every virtual wireless adapter are linked. For more information, see the [About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network).

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type)

[WLAN_INTF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_intf_opcode)

[WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)