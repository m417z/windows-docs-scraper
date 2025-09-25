## Description

The **WIFI_PHY_CAPABILITIES** structure describes the PHY capabilities for a WiFiCx device.

## Members

### `Size`

The sum (in bytes) of the sizes of all contained elements.

### `NumPhyTypes`

The number of PHY types supported.

### `PhyInfoList`

A pointer to a list of [**WIFI_PHY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_info) structures.

## Remarks

Client drivers pass **WIFI_PHY_CAPABILITIES** as a parameter to [**WifiDeviceSetPhyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetphycapabilities) to report PHY capabilities to WiFiCx.

Call [**WIFI_PHY_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_phy_capabilities_init) to initialize this structure and fill in its **Size** field. Then call [**WifiDeviceSetPhyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetphycapabilities) to report PHY capabilities to WiFiCx.

## See also

[**WIFI_PHY_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_phy_capabilities_init)

[**WifiDeviceSetPhyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetphycapabilities)

[**WIFI_PHY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_info)