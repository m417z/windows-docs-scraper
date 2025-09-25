## Description

The **WIFI_DEVICE_CAPABILITIES_INIT** function initializes a [**WIFI_DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a client driver-allocated **WIFI_DEVICE_CAPABILITIES** structure.

## Remarks

This function zeroes out the memory of the **WIFI_DEVICE_CAPABILITIES** structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceSetDeviceCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetdevicecapabilities) to report device capabilities to WiFiCx.

## See also

[**WIFI_DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_capabilities)

[**WifiDeviceSetDeviceCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetdevicecapabilities)