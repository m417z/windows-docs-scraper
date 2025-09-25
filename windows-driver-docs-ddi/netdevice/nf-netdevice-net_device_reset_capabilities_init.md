# NET_DEVICE_RESET_CAPABILITIES_INIT function

## Description

The **NET_DEVICE_RESET_CAPABILITIES_INIT** function initializes a [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) structure.

## Parameters

### `ResetCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) structure.

### `ResetDiagnosticsGuid` [_In_]

A client driver specified global unique identifier (GUID). Developers can use this identifier to retrieve reset diagnostics. The client driver collects the reset diagnostics as secondary data in the full kernel dump captured in the process of device reset and recovery.

### `EvtNetDeviceCollectResetDiagnostics` [_In_]

A pointer to the client driver's implementation of the [**EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics) callback that collects device-specific reset diagnostics from a hardware device.

## Remarks

A client driver typically calls **NET_DEVICE_RESET_CAPABILITIES_INIT** in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

This function zeros out the [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) structure and fills in its **Size** member. Then it sets the **ResetDiagnosticsGuid** member and ***EvtNetDeviceCollectResetDiagnostics*** member with the corresponding input parameters.

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities)

[*EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics)