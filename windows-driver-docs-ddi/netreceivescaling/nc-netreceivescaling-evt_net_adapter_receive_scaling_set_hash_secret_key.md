# EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY callback function

## Description

The *EvtNetAdapterReceiveScalingSetHashSecretKey* callback function is implemented by the client driver to set the hash secret key for the network interface controller (NIC).

## Parameters

### `Adapter` [_In_]

The NETADAPTER object the client driver obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `HashSecretKey` [_In_]

A pointer to a [NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_hash_secret_key) structure that contains the hash secret key for validating hash calculations.

## Return value

Returns STATUS_SUCCESS if the hash secret key was set successfully. Otherwise, returns an appropriate NTSTATUS error code.

## Prototype

```cpp
//Declaration

EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY EvtNetAdapterReceiveScalingSetHashSecretKey;

// Definition

NTSTATUS EvtNetAdapterReceiveScalingSetHashSecretKey
(
	_In_	NETADAPTER 											Adapter,
	_In_	const NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY *	HashSecretKey
)
{...}

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY *PFN_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure and then calling [NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities). Client drivers typically call **NetAdapterSetReceiveScalingCapabilities** when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

### Example

In this callback, NIC client drivers program the supplied hash secret key to their hardware for use in verifying RSS hash calculations.

```C++
NTSTATUS
MyEvtNetAdapterReceiveScalingSetHashSecretKey(
	_In_	NETADAPTER 											Adapter,
	_In_	const NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY *	HashSecretKey	
)
{
	const UINT32* key = (const UINT32*)HashSecretKey->Key;
	if(!MyHardwareRssSetHashSecretKey)
	{
		WdfDeviceSetFailed(Adapter->WdfDevice, WdfDeviceFailedAttemptRestart);
		return STATUS_UNSUCCESSFUL;
	}

	return STATUS_SUCCESS;
}
```

## See also

[NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_hash_secret_key)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)