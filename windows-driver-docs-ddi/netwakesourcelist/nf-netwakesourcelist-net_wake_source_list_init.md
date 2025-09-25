# NET_WAKE_SOURCE_LIST_INIT function

## Description

The **NET_WAKE_SOURCE_LIST_INIT** function initializes a [**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list) structure.

## Parameters

### `List` [_Out_]

A pointer to a driver-allocated [**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list) structure.

## Remarks

This function zeroes out the memory for the **NET_WAKE_SOURCE_LIST** structure, then fills in the **Size** member. After calling this function, call [**NetDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netdevicegetwakesourcelist) with the initialized structure to get the list of wake sources for this net adapter.

The client driver must only call **NET_WAKE_SOURCE_LIST_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETWAKESOURCE objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list)

[**NetDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netdevicegetwakesourcelist)