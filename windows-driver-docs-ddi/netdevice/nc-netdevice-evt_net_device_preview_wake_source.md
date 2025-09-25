# EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE callback function

## Description

Implement this optional callback to reject wake patterns that are not compatible with your hardware.

## Parameters

### `Device` [_In_]

The WDFDEVICE object that the client driver previously obtained with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `WakeSource` [_In_]

A NETWAKESOURCE object that represents the wake source to examine.

## Return value

To accept the pattern, the callback function must return STATUS_SUCCESS.

To reject the pattern, return STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL.

## Prototype

```
//Declaration

EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE EvtNetDevicePreviewWakeSource;

// Definition

NTSTATUS EvtNetDevicePreviewWakeSource
(
	WDFDEVICE Device
	NETWAKESOURCE WakeSource
)
{...}

```

## Remarks

Drivers are not required to implement *EvtNetDevicePreviewWakeSource*, as NetAdapterCx already blocks wake sources that are not compatible with the driver's [**NET_ADAPTER_WAKE_BITMAP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_bitmap_capabilities). However, if your hardware has additional limitations that cannot be expressed in the bitmap capabilities structure, you can provide *EvtNetDevicePreviewWakeSource* to enforce those additional limitations.

Register your implementation of this callback function by setting the appropriate member of the [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks), then calling [**NetDeviceInitSetPowerPolicyEventCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetpowerpolicyeventcallbacks).

Client drivers typically call **NetDeviceInitSetPowerPolicyEventCallbacks** when creating the device object, before calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

In this callback, client drivers get the chance to reject the wake source. For example, if the number of power filters in the current wake source list for **Device** have already reached or exceeded the number of power filters that the hardware supports, the driver can reject this wake source.

For more info, see [Configuring Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also