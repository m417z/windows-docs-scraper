# NetAdapterInitSetDatapathCallbacks function

## Description

The **NetAdapterInitSetDatapathCallbacks** function sets a net adapter's callback functions for creating datapath packet queues.

## Parameters

### `AdapterInit` [_Inout_]

A pointer to a NETADAPTER_INIT structure that the driver obtained from a previous call to [**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate).

### `DatapathCallbacks` [_In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_DATAPATH_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_datapath_callbacks) structure that contains pointers to the adapter's datapath queue creation callback functions.

## Remarks

This is an optional function. If a client driver does not provide its own packet queue creation handlers, NetAdapterCx provides default handlers on the driver's behalf.

Call this function after calling [**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate) but before calling [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

If the driver encounters an error after the NETADAPTER_INIT allocation succeeds but before [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate) succeeds, it must call [**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree) to deallocate the NETADAPTER_INIT object.

For a code example of creating a NETADAPTER, see [Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization).

## See also

[Device initialization](https://learn.microsoft.com/windows-hardware/drivers/netcx/device-initialization)

[**NetAdapterInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitallocate)

[**NetAdapterInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitfree)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)