# NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS_INIT function

## Description

The **NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS_INIT** function initializes a [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks) structure.

## Parameters

### `Callbacks` [_Out_]

A pointer to a driver-allocated [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks) structure.

## Remarks

This function zeroes out the **NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS** structure, then fills in the **Size** member. After calling this function, call [**NetDeviceInitSetPowerPolicyEventCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetpowerpolicyeventcallbacks) during device initialization before you call [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## See also

[Configuring Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks)

[**NetDeviceInitSetPowerPolicyEventCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetpowerpolicyeventcallbacks)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)