## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_POWER_MODE_REASON_CODE** enumeration defines the reasons for entering the Power Save state.

## Constants

### `WDI_POWER_MODE_REASON_CODE_NO_CHANGE:0`

Device is initially in this state and has not changed since.

### `WDI_POWER_MODE_REASON_CODE_NONCOMPLANT_AP:1`

The connected AP didn't handle PSM correctly.

### `WDI_POWER_MODE_REASON_CODE_LEGACY_P2P_DEVICE:2`

WFD device is legacy.

### `WDI_POWER_MODE_REASON_CODE_COMPLIANT_AP:3`

AP is compliant.

### `WDI_POWER_MODE_REASON_CODE_COMPLIANT_P2P_DEVICE:4`

All connected WFD device can do PSM.

### `WDI_POWER_MODE_REASON_CODE_OTHERS:5`

Other reason.

## Remarks

The **WDI_POWER_MODE_REASON_CODE** enumeration is a value in the [**WDI_TLV_GET_AUTO_POWER_SAVE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-get-auto-power-save) TLV.

## See also

[**WDI_TLV_GET_AUTO_POWER_SAVE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-get-auto-power-save)