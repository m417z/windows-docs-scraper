# NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES structure

## Description

The **NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES** structure describes a net adapter's wake on LAN (WoL) capabilities for waking from a media change event.

## Members

### `Size`

The size of this structure, in bytes.

### `MediaConnect`

A boolean value that describes if the net adapter is capable of waking from a media connect event.

### `MediaDisconnect`

A boolean value that describes if the net adapter is capable of waking from a media disconnect event.

## Remarks

Call [**NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_media_change_capabilities_init) to initialize this structure, then call [**NetAdapterWakeSetMediaChangeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmediachangecapabilities) to set the net adapter's media change WoL capabilities. Client drivers typically call **NetAdapterWakeSetMediaChangeCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_media_change_capabilities_init)

[**NetAdapterWakeSetMediaChangeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmediachangecapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)