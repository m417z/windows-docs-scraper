# NetTxQueueCreate function

## Description

Creates a net transmit queue object.

## Parameters

### `NetTxQueueInit` [_Inout_]

A pointer to the **NETTXQUEUE_INIT** structure that the client driver received in *[EVT_NET_ADAPTER_CREATE_TXQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)*.

### `TxQueueAttributes` [_In_opt_]

A pointer to an initialized, caller-allocated [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**. However, if the client driver supplies this parameter, the **ParentObject** field must be **NULL**.

### `Configuration` [_In_]

A pointer to a caller-allocated [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure.

### `PacketQueue` [_Out_]

A pointer to a location that receives a handle to the new net transmit queue object.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client calls **NetTxQueueCreate** from within its *[EVT_NET_ADAPTER_CREATE_TXQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)* event callback function. For info on assigning context space to the new object, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

The NETPACKETQUEUE object is a standard WDF object. The framework manages its deletion, which occurs when the parent NETADAPTER object is deleted.

## See also