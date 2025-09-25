# _NDIS_TCP_OFFLOAD_EVENT_HANDLERS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_TCP_OFFLOAD_EVENT_HANDLERS structure contains the entry points for the NDIS functions for
the TCP chimney.

## Members

### `Header`

The NDIS object header, which is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

### `NdisTcpOffloadEventHandler`

The entry point for the
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate) function.

### `NdisTcpOffloadReceiveHandler`

The entry point for the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function.

### `NdisTcpOffloadSendComplete`

The entry point for the
[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete) function.

### `NdisTcpOffloadReceiveComplete`

The entry point for the
[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete) function.

### `NdisTcpOffloadDisconnectComplete`

The entry point for the
[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete) function.

### `NdisTcpOffloadForwardComplete`

The entry point for the
[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete) function.

## Remarks

An offload target copies the entry points in the NDIS_TCP_OFFLOAD_EVENT_HANDLERS structure into its
own internal data structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMGetOffloadHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismgetoffloadhandlers)

[NdisTcpOffloadDisconnectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_disconnect_complete)

[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate)

[NdisTcpOffloadReceiveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_complete)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)