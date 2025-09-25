# WLAN_PHY_RADIO_STATE structure

## Description

The **WLAN_PHY_RADIO_STATE** structure specifies the radio state on a specific physical layer (PHY) type.

## Members

### `dwPhyIndex`

The index of the PHY type on which the radio state is being set or queried. The [WlanGetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetinterfacecapability) function returns a list of valid PHY types.

### `dot11SoftwareRadioState`

A [DOT11_RADIO_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-dot11_radio_state-r1) value that indicates the software radio state.

### `dot11HardwareRadioState`

A [DOT11_RADIO_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-dot11_radio_state-r1) value that indicates the hardware radio state.

## Remarks

The **WLAN_PHY_RADIO_STATE** structure is used with the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) function when the *OpCode* parameter is set to **wlan_intf_opcode_radio_state**.

The **WLAN_PHY_RADIO_STATE** structure is also used for notification by the media specific module (MSM) when the radio state changes. An application registers to receive MSM notifications by calling the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function with the *dwNotifSource* parameter set to a value that includes **WLAN_NOTIFICATION_SOURCE_MSM**. For more information on these notifications, see the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure and the [WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1) enumeration reference.

The radio state of a PHY is off if either **dot11SoftwareRadioState** or **dot11HardwareRadioState** member of the **WLAN_PHY_RADIO_STATE** structure is **dot11_radio_state_off**.

The hardware radio state cannot be changed by calling the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) function. The **dot11HardwareRadioState** member of the **WLAN_PHY_RADIO_STATE** structure is ignored when the **WlanSetInterface** function is called with the *OpCode* parameter set to **wlan_intf_opcode_radio_state** and the *pData* parameter points to a **WLAN_PHY_RADIO_STATE** structure.

The software radio state can be changed by calling the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) function.

Changing the software radio state of a physical network interface could cause related changes in the state of the wireless Hosted Network or virtual wireless adapter radio states. The PHYs of every virtual wireless adapter are linked. For more information, see the [About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network).

The radio state of a PHY is off if either the software radio state (**dot11SoftwareRadioState** member) or the hardware radio state (**dot11HardwareRadioState** member) is off.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[DOT11_RADIO_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-dot11_radio_state-r1)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1)

[WLAN_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_radio_state)

[WlanGetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetinterfacecapability)

[WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface)