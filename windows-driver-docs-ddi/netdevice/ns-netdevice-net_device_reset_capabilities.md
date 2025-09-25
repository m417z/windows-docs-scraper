## Description

The **NET_DEVICE_RESET_CAPABILITIES** structure describes a client driver's capabilities for collecting diagnostics during the device reset and recovery process.

## Members

### `Size`

The size of this structure, in bytes.

### `ResetDiagnosticsGuid`

A client driver specified global unique identifier (GUID). Developers can use this identifier to retrieve reset diagnostics. The client driver collects the diagnostics as secondary data in the full kernel dump captured in the device reset and recovery process.

### `EvtNetDeviceCollectResetDiagnostics`

A pointer to the client driver's implementation of the [*EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics) callback that collects device-specific reset diagnostics from a hardware device.

## Remarks

Client drivers initialize and register this structure in their [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

Call [**NET_DEVICE_RESET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_reset_capabilities_init) to initialize this structure.

Call [**NetDeviceInitSetResetCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetresetcapabilities) to register this structure to the NetAdapterCx framework.

For more information, see [Register NET_DEVICE_RESET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/#register-NET_DEVICE_RESET_CAPABILITIES).

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[*EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics)

[**NET_DEVICE_RESET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_reset_capabilities_init)

[**NetDeviceInitSetResetCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetresetcapabilities)