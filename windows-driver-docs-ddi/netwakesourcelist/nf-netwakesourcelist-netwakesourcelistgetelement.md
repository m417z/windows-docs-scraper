# NetWakeSourceListGetElement function

## Description

The **NetWakeSourceListGetElement** function gets a wake source from the list of wake sources for a net adapter.

## Parameters

### `List` [_In_]

A handle to a driver-allocated and initialized [**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list) structure.

### `Index` [_In_]

The zero-based index in the list for the target NETWAKESOURCE object. This function must be less than the value returned by [**NetWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetcount).

## Return value

Returns the NETWAKESOURCE object, which represents the wake source, at the specified index in the list.

## Remarks

Call [**NetWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetcount) to get the number of wake sources before calling this function.

The client driver must only call **NetWakeSourceListGetElement** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

For a code sample of working with NETWAKESOURCE objects, see [Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list)

[**NetWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/nf-netwakesourcelist-netwakesourcelistgetcount)