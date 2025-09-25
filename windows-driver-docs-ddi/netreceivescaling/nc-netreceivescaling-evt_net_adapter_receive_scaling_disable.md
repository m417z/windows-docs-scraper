# EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE callback function

## Description

The *EvtNetAdapterReceiveScalingDisable* callback function is implemented by the client driver to disable receive side scaling (RSS) for a network interface controller (NIC).

## Parameters

### `Adapter` [_In_]

The **NETADAPTER** object the client driver obtained in a previous call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Prototype

```cpp
//Declaration

EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE EvtNetAdapterReceiveScalingDisable;

// Definition

VOID EvtNetAdapterReceiveScalingDisable
(
	_In_ NETADAPTER Adapter
)
{...}

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE *PFN_NET_ADAPTER_RECEIVE_SCALING_DISABLE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_capabilities) structure and then calling [NetAdapterSetReceiveScalingCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nf-netreceivescaling-netadaptersetreceivescalingcapabilities).Client drivers typically call **NetAdapterSetReceiveScalingCapabilities** when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

### Example

In this callback, client drivers disable RSS on the NIC.

> [!IMPORTANT]
> Client drivers should **not** clear or reset their indirection table from their *EvtNetAdapterReceiveScalingDisable* callback. The framework will set the driver's initial indirection table state.

```C++
VOID
MyEvtNetAdapterReceiveScalingDisable(
	_In_ NETADAPTER Adapter
)
{
	if(!MyHardwareRssSetControl(MY_RSS_MULTI_CPU_DISABLE))
	{
		WdfDeviceSetFailed(Adapter->WdfDevice, WdfDeviceFailedAttemptRestart);
	}
}
```

## See also

*[EvtNetAdapterReceiveScalingEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_enable)*

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)