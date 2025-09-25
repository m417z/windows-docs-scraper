# NET_WAKE_SOURCE_LIST structure

## Description

The **NET_WAKE_SOURCE_LIST** structure represents a list of wake-on-LAN (WoL) sources for a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Reserved`

Reserved. Client drivers must not read or write to this value directly.

## Remarks

Call [**NET_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-net_wake_source_list_init) to initialize this structure, then call [**NetDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netdevicegetwakesourcelist) to get the list of wake sources from this net adapter. After you obtain the list, call [**NetWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetcount) with this structure to get the number of NETWAKESOURCE objects that represents the wake sources, then loop over the objects and call [**NetWakeSourceListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetelement) to retrieve each one. Once you have obtained a NETWAKESOURCE object, call [**NetWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegettype) to get the type of that wake source so you can call the appropriate function to get the wake source's parameters.

The client driver must only call wake source-related functions during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETWAKESOURCE objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-net_wake_source_list_init)

[**NetDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netdevicegetwakesourcelist)

[**NetWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetcount)

[**NetWakeSourceListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetelement)

[**NetWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegettype)