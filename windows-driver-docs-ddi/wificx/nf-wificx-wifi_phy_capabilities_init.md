## Description

The **WIFI_PHY_CAPABILITIES_INIT** function initializes a [**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a client driver-allocated **WIFI_PHY_CAPABILITIES** structure.

## Remarks

This function zeroes out the memory of the **WIFI_PHY_CAPABILITIES** structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceSetPhyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetphycapabilities) to report PHY capabilities to WiFiCx.

## See also

[**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_phy_capabilities)

[**WifiDeviceSetPhyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetphycapabilities)