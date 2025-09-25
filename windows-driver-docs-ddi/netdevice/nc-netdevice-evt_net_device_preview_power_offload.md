# EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD callback function

## Description

Implement this optional callback to reject protocol offloads that are not compatible with your hardware.

## Parameters

### `Device` [_In_]

The WDFDEVICE object that the client driver previously obtained with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `PowerOffload` [_In_]

A NETPOWEROFFLOAD object that represents the low power protocol offload to examine.

## Return value

To accept the protocol offload, the callback function must return STATUS_SUCCESS.

To reject the protocol offload, return STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL.

## Prototype

```
//Declaration

EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD EvtNetDevicePreviewPowerOffload;

// Definition

NTSTATUS EvtNetDevicePreviewPowerOffload
(
	WDFDEVICE Device
	NETPOWEROFFLOAD PowerOffload
)
{...}

```

## Remarks

Drivers are not required to implement *EvtNetDevicePreviewPowerOffload*, as NetAdapterCx already blocks protocol offloads that are not compatible with the driver's power offload capabilities: [**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities) and [**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_ns_capabilities). However, if your hardware has additional limitations that cannot be expressed in these capabilities structures, you can provide *EvtNetDevicePreviewPowerOffload* to enforce those additional limitations.

Register your implementation of this callback function by setting the appropriate member of the [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-_net_device_power_policy_event_callbacks), then calling [**NetDeviceInitSetPowerPolicyEventCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitsetpowerpolicyeventcallbacks).

Client drivers typically call **NetDeviceInitSetPowerPolicyEventCallbacks** when creating the device object, before calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

In this callback, client drivers get the chance to reject the protocol offload. For example, if the number of protocol offloads in the current protocol offload list for **Device** have already reached or exceeded the number of protocol offloads that the hardware supports, the driver can reject this protocol offload.

For more info, see [Configuring Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also