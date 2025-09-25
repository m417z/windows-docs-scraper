## Description

The **NetDeviceInitSetResetCapabilities** function registers a client driver's [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) to the NetAdapterCx framework.

## Parameters

### `DeviceInit` [_Inout_]

A pointer to a **WDFDEVICE_INIT** object that the client driver received in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

### `ResetCapabilities` [_In_]

A pointer to a client driver allocated and initialized [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) structure.

## Remarks

A client driver typically calls the **NetDeviceInitSetResetCapabilities** function in its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

Before calling this function, the client driver must initialize [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) by calling the [**NET_DEVICE_RESET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_reset_capabilities_init) function.

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities)

[**NET_DEVICE_RESET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_reset_capabilities_init)