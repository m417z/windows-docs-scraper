# _NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY structure

## Description

The NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY structure contains secret key data to verify RSS hash calculations.

## Members

### `Key`

The secret key. This member is 40 bytes (320 bits) for the **NetAdapterReceiveScalingHashTypeToeplitz** hash function.

### `Length`

The length, in bytes, of **Key**.

## Remarks

NetAdapterCx provides the secret key to NIC client drivers when it invokes the *[EvtNetAdapterReceiveScalingSetHashSecretKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_hash_secret_key)* callback function. The NIC then uses this secret key to verify its calculations for the RSS hash function.

## See also

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)

[NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_hash_type)