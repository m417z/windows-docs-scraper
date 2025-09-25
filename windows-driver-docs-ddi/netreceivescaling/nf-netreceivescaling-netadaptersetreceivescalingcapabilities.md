# NetAdapterSetReceiveScalingCapabilities function

## Description

The **NetAdapterSetReceiveScalingCapabilities** function sets a net adapter's receive side scaling (RSS) capabilities.

## Parameters

### `Adapter` [_In_]

The **NETADAPTER** object the driver obtained in a previous call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities` [_In_]

A pointer to a driver-allocated and initialized [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure.

## Remarks

The client driver must call this function when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities)

[NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-net_adapter_receive_scaling_capabilities_init)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)