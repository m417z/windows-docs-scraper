# EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE callback function

## Description

The *EvtNetAdapterReceiveScalingEnable* callback function is implemented by the client driver to enable receive side scaling (RSS) for a network interface controller (NIC).

## Parameters

### `Adapter` [_In_]

The **NETADAPTER** object the client driver obtained in a previous call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `HashType` [_In_]

A [**NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_hash_type) value that specifies the type of receive side scaling (RSS) hash function that a NIC should use to compute the hash values for incoming packets.

### `ProtocolType` [_In_]

A [**NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ne-netreceivescaling-_net_adapter_receive_scaling_protocol_type) value that specifies the portion of received network data that an RSS-capable NIC must use to calculate an RSS hash value.

## Return value

Returns STATUS_SUCCESS if RSS was successfully enabled. Otherwise, returns an appropriate NTSTATUS error code.

## Prototype

```cpp
//Declaration

EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE EvtNetAdapterReceiveScalingEnable;

// Definition

NTSTATUS EvtNetAdapterReceiveScalingEnable
(
	_In_ NETADAPTER Adapter,
	_In_ NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE HashType,
	_In_ NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE ProtocolType
)
{...}

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE *PFN_NET_ADAPTER_RECEIVE_SCALING_ENABLE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure and then calling [NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities). Client drivers typically call **NetAdapterSetReceiveScalingCapabilities** when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

### Example

In this callback, clients turn RSS on with the supplied information by setting the appropriate control bits in hardware.

> [!IMPORTANT]
> Client drivers should **not** clear or reset their indirection table from their *EvtNetAdapterReceiveScalingEnable* callback. The framework will set the driver's initial indirection table state.

```C++
NTSTATUS
MyEvtNetAdapterReceiveScalingEnable(
	_In_ NETADAPTER Adapter,
	_In_ NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE HashType,
	_In_ NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE ProtocolType
)
{
	NTSTATUS status = STATUS_SUCCESS;

	// Not using the hash type in this example
	UNREFERENCED_PARAMETER(HashType);

	UINT32 controlBitsEnable = MY_RSS_MULTI_CPU_ENABLE | MY_RSS_HASH_BITS_ENABLE;

	// Set the appropriate control bits for IPv4
	if(ProtocolType & NetAdapterReceiveScalingProtocolTypeIPv4)
	{
		controlBitsEnable |= MY_RSS_IPV4_ENABLE;

		if (ProtocolType & NetAdapterReceiveScalingProtocolTypeTcp)
        {
            controlBitsEnable |= MY_RSS_IPV4_TCP_ENABLE;
        }
	}

	// Repeat for IPv6
	...

	// Set the bits in hardware
	if(!MyHardwareRssSetControl(controlBitsEnable))
	{
		WdfDeviceSetFailed(Adapter->WdfDevice, WdfDeviceFailedAttemptRestart);
        return STATUS_UNSUCCESSFUL;
	}

	// Perform other tasks like restarting the Rx queue

	return STATUS_SUCCESS;
}
```

## See also

*[EvtNetAdapterReceiveScalingDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_disable)*

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)