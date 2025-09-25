# NET_POWER_OFFLOAD_LIST_INIT function

## Description

The **NET_POWER_OFFLOAD_LIST_INIT** function initializes a [**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list) structure.

## Parameters

### `List` [_Out_]

A handle to a driver-allocated [**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list) structure.

## Remarks

This function zeros out the memory for the **NET_POWER_OFFLOAD_LIST** structure, then fills in the **Size** member. After calling this function, call [**NetDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netdevicegetpoweroffloadlist) with the initialized structure to get the list of low power offloads to this net adapter.

The client driver must only call **NET_POWER_OFFLOAD_LIST_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETPOWEROFFLOAD objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list)

[**NetDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/nf-netpoweroffloadlist-netdevicegetpoweroffloadlist)