## Description

The **WifiDeviceSetDeviceCapabilities** function sets the device capabilities for a WiFiCx device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `DeviceCapabilities`

A pointer to a client driver-allocated and initialized [**WIFI_DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Client drivers typically call **WifiDeviceSetDeviceCapabilities** within [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

Call [**WIFI_DEVICE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_capabilities_init) to initialize the **WIFI_DEVICE_CAPABILITIES** structure and fill in its **Size** field. Then call **WifiDeviceSetDeviceCapabilities** to report device capabilities to WiFiCx.

For more information see [Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow).

## See also

[**WIFI_DEVICE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_capabilities_init)

[**WIFI_DEVICE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities)

[Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow)