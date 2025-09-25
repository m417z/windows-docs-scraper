# NetDeviceInitSetPowerPolicyEventCallbacks function

## Description

The **NetDeviceInitSetPowerPolicyEventCallbacks** function sets optional power policy event callbacks during device initialization for a client driver.

## Parameters

### `DeviceInit` [_Inout_]

A pointer to a WDFDEVICE_INIT object that the client driver received in its [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

### `Callbacks` [_In_]

A pointer to a client driver allocated and initialized [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks) structure.

## Remarks

Initialize the WDFDEVICE_INIT object by calling [**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig) before calling this function. Initialize the [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks) structure by calling [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_power_policy_event_callbacks_init), then fill in pointers to the callbacks that your client driver implements.

## See also

[Configuring Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks)