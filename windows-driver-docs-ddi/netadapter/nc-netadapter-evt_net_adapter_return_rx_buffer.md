# EVT_NET_ADAPTER_RETURN_RX_BUFFER callback function

## Description

Implement this optional callback function to perform cleanup on a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffer for which you previously specified manual fragment allocation and attachment.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `RxReturnContext` [_In_]

A pointer to a driver-allocated context space structure.

## Prototype

```c++
//Declaration

EVT_NET_ADAPTER_RETURN_RX_BUFFER EvtNetAdapterReturnRxBuffer;

// Definition

VOID EvtNetAdapterReturnRxBuffer
(
	_In_	NETADAPTER							Adapter,
	_In_	NET_FRAGMENT_RETURN_CONTEXT_HANDLE	RxReturnContext
)
{...}

typedef EVT_NET_ADAPTER_RETURN_RX_BUFFER *PFN_NET_ADAPTER_RETURN_RX_BUFFER;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure and then calling [**NetAdapterSetDatapathCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities). Client drivers typically call **NetAdapterSetDatapathCapabilities** when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

This callback function is optional unless the net adapter client driver initializes its [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure using the [**NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_driver_managed) function. By using this initialization function, the driver tells the operating system that it is managing allocation and attachment of [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffers manually, so it must provide this callback function in this case for the operating system to invoke once the system is finished with the buffer.

### Example

In this callback function, the client driver can perform whatever cleanup or follow-up actions it needs now that the operating system has finished with this receive buffer. In the following example, the return context contains a member to track the number of indicated packets, as well as a memory object used for a lookaside buffer during receive processing. Error handling has been left out for clarity.

```c++
VOID
MyReturnRxBuffer(
	_In_	NETADAPTER							Adapter,
	_In_	NET_FRAGMENT_RETURN_CONTEXT_HANDLE	RxReturnContext
)
{
	UNREFERENCED_PARAMETER(Adapter);

	RxReturnContext->IndicatedPackets--;

	// Clean up the lookaside buffer if this is the last packet
	if(RxReturnContext->IndicatedPackets == 0)
	{
		WdfObjectDelete(RxReturnContext->LookasideBufferMemory);
	}
}
```

## See also

[**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)