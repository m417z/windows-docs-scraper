# NetPowerOffloadListGetElement function

## Description

The **NetPowerOffloadListGetElement** function gets a low power protocol offload from a list of offloads to a net adapter.

## Parameters

### `List` [_In_]

A pointer to a driver-allocated and initialized [**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list) structure.

### `Index` [_In_]

The zero-based index in the list for the target NETPOWEROFFLOAD object. This function must be less than the value returned by [**NetPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetcount).

## Return value

Returns the NETPOWEROFFLOAD object, which represents the low power protocol offload, at the specified index in the list.

## Remarks

Call [**NetPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetcount) to get the number of low power protocol offloads before calling this function.

The client driver must only call **NetPowerOffloadListGetElement** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETPOWEROFFLOAD objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list)

[**NetPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netpoweroffloadlistgetcount)