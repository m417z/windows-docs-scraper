# _NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE enumeration

## Description

The **NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE** enumeration specifies the portion of received network data that an RSS-capable NIC must use to calculate an RSS hash value.

## Constants

### `NetAdapterReceiveScalingProtocolTypeNone:0x00000000`

Unused for RSS-capable NIC client drivers.

### `NetAdapterReceiveScalingProtocolTypeIPv4:0x00000001`

Indicates that the hardware can calculate hashes for IPv4 packets.

### `NetAdapterReceiveScalingProtocolTypeIPv4Options:0x00000002`

Indicates that the hardware understands IPv4 options. This constant requires that **NetAdapterReceiveScalingProtocolTypeIPv4** is set.

### `NetAdapterReceiveScalingProtocolTypeIPv6:0x00000004`

Indicates that the hardware can calculate hashes for IPv6 packets.

### `NetAdapterReceiveScalingProtocolTypeIPv6Extensions:0x00000008`

Indicates that the hardware understands IPv6 extension headers. This constant requires that **NetAdapterReceiveScalingProtocolTypeIPv6** is set.

### `NetAdapterReceiveScalingProtocolTypeTcp:0x00000010`

Indicates that the hardware supports 4-tuple TCP header hash calculation.

### `NetAdapterReceiveScalingProtocolTypeUdp:0x00000020`

Indicates that the hardware supports 4-tuple UDP header hash calculation.

## Remarks

The **ReceiveScalingProtocolTypes** member of the [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure is a bitwise OR of **NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE** constants. NIC client drivers can OR multiple values together to indicate which protocol types they support for RSS.

## See also

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)