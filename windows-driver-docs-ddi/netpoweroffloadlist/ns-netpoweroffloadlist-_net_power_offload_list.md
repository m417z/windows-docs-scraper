# NET_POWER_OFFLOAD_LIST structure

## Description

The **NET_POWER_OFFLOAD_LIST** structure represents a list of low power protocol offloads to a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Reserved`

Reserved. Client drivers must not read or write to this value directly.

## Remarks

Call [**NET_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-net_power_offload_list_init) to initialize this structure, then call [**NetDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netdevicegetpoweroffloadlist) to get the list of low power offloads to this net adapter. After you obtain the list, call [**NetPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetcount) with this structure to get the number of NETPOWEROFFLOAD objects that represents the offloads, then loop over the objects and call [**NetPowerOffloadListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetelement) to retrieve each one. Once you have obtained a NETPOWEROFFLOAD object, call [**NetPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgettype) to get the type of that offload so you can call the appropriate function to get the offload's parameters.

The client driver must only call power offload-related functions during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETPOWEROFFLOAD objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-net_power_offload_list_init)

[**NetDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netdevicegetpoweroffloadlist)

[**NetPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetcount)

[**NetPowerOffloadListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetelement)

[**NetPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgettype)