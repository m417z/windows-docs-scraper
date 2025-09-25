# _NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure specifies a protocol or intermediate
driver's TCP chimney offload-specific entry points.

## Members

### `Header`

The header of the NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure. The header is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
NDIS_OBJECT_HEADER structure contains the revision number of the
NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure and the size of the
NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure, including the header, in bytes. The
**Type** member of the header is not significant.

### `Flags`

Reserved for system use.

### `OffloadType`

The chimney offload type. The only allowable value is
**NdisTcpChimneyOffload**, which specifies a TCP chimney.

### `TcpOffloadSendCompleteHandler`

The entry point of the driver's
[ProtocolTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_send_complete_handler) function.

### `TcpOffloadReceiveCompleteHandler`

The entry point of the driver's
[ProtocolTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_recv_complete_handler) function.

### `TcpOffloadDisconnectCompleteHandler`

The entry point of the driver's
[ProtocolTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_disconnect_complete_handler) function.

### `TcpOffloadForwardCompleteHandler`

The entry point of the driver's
[ProtocolTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_forward_complete_handler) function.

### `TcpOffloadEventHandler`

The entry point of the driver's
[ProtocolTcpOffloadEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_event_handler) function.

### `TcpOffloadReceiveIndicateHandler`

The entry point of the driver's
[ProtocolTcpOffloadReceiveIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_receive_indicate_handler) function.

## Remarks

To register its TCP chimney offload entry points, a protocol or intermediate driver calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
in the context of the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. To the
**NdisSetOptionalHandlers** function, the protocol or intermediate driver passes a pointer to the
NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[ProtocolTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_disconnect_complete_handler)

[ProtocolTcpOffloadEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_event_handler)

[ProtocolTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_recv_complete_handler)

[ProtocolTcpOffloadReceiveIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_receive_indicate_handler)

[ProtocolTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-tcp_offload_send_complete_handler)