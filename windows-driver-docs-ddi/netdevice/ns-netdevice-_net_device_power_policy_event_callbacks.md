# NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS structure

## Description

The **NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS** structure contains function pointers for a client driver's power policy callback functions.

## Members

### `Size`

The size of this structure, in bytes.

### `EvtDevicePreviewBitmapPattern`

A pointer to the client driver's implementation of the [*EvtNetDevicePreviewWakeSource*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source) callback function for previewing a bitmap wake pattern.

### `EvtDevicePreviewArpOffload`

A pointer to an implementation of the [*EvtNetDevicePreviewPowerOffload*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload) callback function for previewing an IPv4 ARP low power protocol offload.

### `EvtDevicePreviewNSOffload`

A pointer to an implementation of the [*EvtNetDevicePreviewPowerOffload*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload) callback function for previewing an IPv6 Neighbor Solicitation (NS) low power protocol offload.

## Remarks

Call [**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_power_policy_event_callbacks_init) to initialize this structure, then provide pointers to the callbacks your client driver implements. If your client driver does not implement one of the callbacks, set that member to **NULL**.

## See also

[Configuring Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[*EvtNetDevicePreviewWakeSource*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)

[*EvtNetDevicePreviewPowerOffload*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)

[**NET_DEVICE_POWER_POLICY_EVENT_CALLBACKS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-net_device_power_policy_event_callbacks_init)