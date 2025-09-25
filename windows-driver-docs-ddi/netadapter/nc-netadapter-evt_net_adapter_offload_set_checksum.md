# EVT_NET_ADAPTER_OFFLOAD_SET_CHECKSUM callback function

## Description

> [!NOTE]
> The *EvtNetAdapterOffloadSetChecksum* callback function is deprecated in NetAdapterCx 2.1 and later. For more information on current checksum offload functions, see [Checksum offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload).

The *EvtNetAdapterOffloadSetChecksum* callback function is implemented by the client driver to set changes in active checksum offload capabilities.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Offload` [_In_]

A handle to a NETOFFLOAD object that describes the adapter's offload capabilities.

## Prototype

```C++
//Declaration

EVT_NET_ADAPTER_OFFLOAD_SET_CHECKSUM EvtNetAdapterOffloadSetChecksum;

// Definition

VOID EvtNetAdapterOffloadSetChecksum
(
	NETADAPTER 	Adapter,
	NETOFFLOAD	Offload
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate parameter when calling [**NetAdapterOffloadSetChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteroffloadsetchecksumcapabilities).

For an example implementation of this callback, see [NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads).

## See also

[NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads)

[**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities)

[**NetAdapterOffloadSetChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteroffloadsetchecksumcapabilities)