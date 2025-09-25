## Description

The **WifiDeviceSetPhyCapabilities** function sets the PHY capabilities for a WiFiCx device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `PhyCapabilities`

A pointer to a client driver-allocated and initialized [**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Client drivers typically call **WifiDeviceSetPhyCapabilities** within [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

Call [**WIFI_PHY_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_phy_capabilities_init) to initialize the **WIFI_PHY_CAPABILITIES** structure and fill in its **Size** field. Then call **WifiDeviceSetPhyCapabilities** to report PHY capabilities to WiFiCx.

For more information see [Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow).

## See also

[**WIFI_PHY_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_phy_capabilities_init)

[**WIFI_PHY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities)

[Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow)