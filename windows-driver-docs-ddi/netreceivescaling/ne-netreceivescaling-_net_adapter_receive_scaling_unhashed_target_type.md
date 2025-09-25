# _NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE enumeration

## Description

The **NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE** enumeration specifies how a net adapter handles unhashed receive side scaling (RSS) frames.

## Constants

### `NetAdapterReceiveScalingUnhashedTargetTypeUnspecified:0`

Indicates that the device does not distribute unhashed frames to a specific hash index.

### `NetAdapterReceiveScalingUnhashedTargetTypeHashIndex:1`

Indicates that unhashed frames are delivered to the queue at the specified hash index. This requires the caller to specify the **UnhashedTargetIndex** member of the [**NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure with the hash index if the hash index is non-zero.

## Remarks

## See also

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)