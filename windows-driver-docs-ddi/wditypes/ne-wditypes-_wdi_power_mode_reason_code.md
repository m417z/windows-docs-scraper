# _WDI_POWER_MODE_REASON_CODE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_POWER_MODE_REASON_CODE enumeration defines the reasons for entering the Power Save state.

## Constants

### `WDI_POWER_MODE_REASON_CODE_NO_CHANGE`

Device is initially in this state and has not changed since.

### `WDI_POWER_MODE_REASON_CODE_LEGACY_P2P_DEVICE`

WFD device is legacy.

### `WDI_POWER_MODE_REASON_CODE_COMPLIANT_AP`

AP is compliant.

### `WDI_POWER_MODE_REASON_CODE_COMPLIANT_P2P_DEVICE`

All connected WFD device can do PSM.

### `WDI_POWER_MODE_REASON_CODE_OTHERS`

Other reason.

### `WDI_POWER_MODE_REASON_CODE_NONCOMPLIANT_AP`

AP is not compliant. As to be in CAM.