# EVT_NET_ADAPTER_OFFLOAD_SET_RSC callback function

## Description

The *EvtNetAdapterOffloadSetRsc* callback function is implemented by the client driver to set changes in active receive segment coalescence (RSC) offload capabilities.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Offload` [_In_]

A handle to a NETOFFLOAD object that describes the adapter's offload capabilities.

## Prototype

```C++
//Declaration

EVT_NET_ADAPTER_OFFLOAD_SET_LSO EvtNetAdapterOffloadSetRsc;

// Definition

VOID EvtNetAdapterOffloadSetRsc
(
	NETADAPTER Adapter,
	NETOFFLOAD Offload
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate parameter when calling [**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities).

For more info, see [NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads).

## See also

[NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads)

[**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities)

[**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities)