# _WDI_OS_POWER_MANAGEMENT_FLAGS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_OS_POWER_MANAGEMENT_FLAGS** enumeration defines supported enablement scenarios of the NIC Auto Power Saver (NAPS) OS power management feature.

## Constants

### `WDI_OS_POWER_MANAGEMENT_NONE`

Enable no OS NAPS power management features.

### `WDI_OS_POWER_MANAGEMENT_ENABLE_STANDBY_NAPS`

Enable NAPS mode for screen off, modern standby (if supported by hardware).

### `WDI_OS_POWER_MANAGEMENT_ENABLE_S0_NAPS`

Enable NAPS mode for screen on *S0* system power state (if supported by hardware).

## Remarks

This enumeration is used as the value type in [WDI_TLV_OS_POWER_MANAGEMENT_FEATURES](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-os-power-management-features).

## See also