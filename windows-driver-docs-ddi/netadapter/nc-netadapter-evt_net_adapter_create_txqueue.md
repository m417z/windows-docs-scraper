# EVT_NET_ADAPTER_CREATE_TXQUEUE callback function

## Description

The client driver's implementation of the *EvtNetAdapterCreateTxQueue* event callback function that sets up a transmit (Tx) queue.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `TxQueueInit` [_Inout_]

A pointer to a NetAdapterCx-allocated **NETTXQUEUE_INIT** structure. For more information, see the Remarks section.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```C++
//Declaration

EVT_NET_ADAPTER_CREATE_TXQUEUE EvtNetAdapterCreateTxqueue;

// Definition

NTSTATUS EvtNetAdapterCreateTxqueue
(
	_In_    NETADAPTER          Adapter,
	_Inout_ NETTXQUEUE_INIT *   TxQueueInit
)
{...}

typedef EVT_NET_ADAPTER_CREATE_TXQUEUE *PFN_NET_ADAPTER_CREATE_TXQUEUE;
```

## Remarks

To register an *EVT_NET_ADAPTER_CREATE_TXQUEUE* callback function, the client driver must call [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

The **NETTXQUEUE_INIT** structure is an opaque structure that is defined and allocated by NetAdapterCx, similar to [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init).

In this callback, the client driver might call [NetTxQueueInitGetQueueId](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueueinitgetqueueid) to retrieve the identifier of the transmit queue to set up. Next, the client calls [**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate) to allocate a queue. If [**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate) fails, the *EvtNetAdapterCreateTxQueue* callback function should return an error code.

NetAdapterCx calls *EvtNetAdapterCreateTxQueue* at the very end of the [power-up sequence](https://learn.microsoft.com/windows-hardware/drivers/netcx/power-up-sequence-for-a-netadaptercx-client-driver).

For a code example of implementing this callback function, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also