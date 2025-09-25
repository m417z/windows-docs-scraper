# EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS callback function

## Description

Implement this optional callback to collect diagnostics from a failed hardware device and report it to the NetAdapterCx framework during the device reset and recovery process.

## Parameters

### `Device` [_In_]

The WDFDEVICE object that the client driver previously obtained with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Remarks

If provided, the NetAdapterCx framework invokes the *EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS* callback to collect reset diagnostics during the reset and recovery process. The framework always invokes this callback at PASSIVE_LEVEL.

The ***EvtNetDeviceCollectResetDiagnostics*** field of the [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) data structure refers to this callback.

To learn how to correctly implement this callback and for more information about the framework's synchronization guarantee, see [Implement *EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/#implement-EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS).

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities)