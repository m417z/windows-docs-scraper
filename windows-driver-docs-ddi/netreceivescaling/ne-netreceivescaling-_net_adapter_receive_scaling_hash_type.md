# _NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE enumeration

## Description

The **NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE** enumeration specifies the type of receive side scaling (RSS) hash function that a NIC should use to compute the hash values for incoming packets.

## Constants

### `NetAdapterReceiveScalingHashTypeNone:0x00000000`

Unused for RSS-capable NIC client drivers.

### `NetAdapterReceiveScalingHashTypeToeplitz:0x00000001`

Indicates support for the Toeplitz hashing function.

## Remarks

Currently, **NetAdapterReceiveScalingHashTypeToeplitz** is the only hashing function available to NIC client drivers.

## See also

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)