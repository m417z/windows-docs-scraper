# NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_media_change_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a client driver-allocated [*NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_media_change_capabilities) structure.

## Remarks

This function zeroes out the memory for the **NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES** structure, then sets the **Size** member. After calling this function to initialize the **NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES** structure, set the remaining members of the structure according to your hardware's capabilities, then call [**NetAdapterWakeSetMediaChangeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmediachangecapabilities) to set the net adapter's media change wake on LAN (WoL) capabilities. Client drivers typically call **NetAdapterWakeSetMediaChangeCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_media_change_capabilities)

[**NetAdapterWakeSetMediaChangeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmediachangecapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)