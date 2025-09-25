# EVT_NET_ADAPTER_CREATE_RXQUEUE callback function

## Description

The client driver's implementation of the *EvtNetAdapterCreateRxQueue* event callback function that sets up a receive (Rx) queue.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `RxQueueInit` [_Inout_]

A pointer to a NetAdapterCx-allocated **NETRXQUEUE_INIT** structure. For more information, see the Remarks section.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```c++
//Declaration

EVT_NET_ADAPTER_CREATE_RXQUEUE EvtNetAdapterCreateRxqueue;

// Definition

NTSTATUS EvtNetAdapterCreateRxqueue
(
	_In_    NETADAPTER          Adapter,
	_Inout_ NETRXQUEUE_INIT *   RxQueueInit
)
{...}

typedef EVT_NET_ADAPTER_CREATE_RXQUEUE *PFN_NET_ADAPTER_CREATE_RXQUEUE;
```

## Remarks

To register an EVT_NET_ADAPTER_CREATE_RXQUEUE callback function, the client driver must call [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

The **NETRXQUEUE_INIT** structure is an opaque structure that is defined and allocated by NetAdapterCx, similar to [**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init).

In this callback, the client driver might call [**NetRxQueueInitGetQueueId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueueinitgetqueueid) to retrieve the identifier of the receive queue to set up. Next, the client calls [**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate) to allocate a queue. If [NetRxQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate) fails, the *EvtNetAdapterCreateRxQueue* callback function should return an error code.

NetAdapterCx calls *EvtNetAdapterCreateRxQueue* at the very end of the [power-up sequence](https://learn.microsoft.com/windows-hardware/drivers/netcx/power-up-sequence-for-a-netadaptercx-client-driver).

For a code example of implementing this callback function, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also