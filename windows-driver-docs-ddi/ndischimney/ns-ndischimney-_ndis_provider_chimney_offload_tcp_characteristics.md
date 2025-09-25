# _NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure specifies an offload target's TCP
chimney offload-specific entry points.

## Members

### `Header`

The header of the NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure. The header is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
NDIS_OBJECT_HEADER structure contains the revision number of the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure and the size of the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure, including the header, in bytes. The
**Type** member of the header is not significant.

### `Flags`

Reserved for system use.

### `OffloadType`

The chimney offload type. The only allowable value is
**NdisTcpChimneyOffload**, which specifies a TCP chimney.

### `TcpOffloadSendHandler`

The entry point of the driver's
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function.

### `TcpOffloadReceiveHandler`

The entry point of the driver's
[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler) function.

### `TcpOffloadDisconnectHandler`

The entry point of the driver's
[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler) function.

### `TcpOffloadForwardHandler`

The entry point of the driver's
[MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler) function.

### `TcpOffloadReceiveReturnHandler`

The entry point of the driver's
[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler) function.

## Remarks

To register its TCP chimney offload-specific entry points, an offload target calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
in the context of the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. To the
**NdisSetOptionalHandlers** function, the offload target passes a pointer to the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS structure.

## See also

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler)

[MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler)

[MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler)

[MiniportTcpOffloadReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_return_handler)

[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)