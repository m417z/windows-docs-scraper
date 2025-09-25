# _NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES structure

## Description

An NDIS miniport driver sets up an NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES structure to define task
offload and connection offload attributes, if any, that are associated with a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES, the
**Revision** member to NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES_REVISION_1.

### `DefaultOffloadConfiguration`

A pointer to an
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure that indicates the
current offload capabilities that are provided by the miniport adapter.

### `HardwareOffloadCapabilities`

A pointer to an NDIS_OFFLOAD structure that indicates all the task offload capabilities that are
supported by the miniport adapter. These capabilities include capabilities that are currently disabled
by standardized keywords in the registry.

### `DefaultTcpConnectionOffloadConfiguration`

A pointer to an
[NDIS_TCP_CONNECTION_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_connection_offload) structure that indicates the current connection offload capabilities
that are provided by the miniport adapter.

### `TcpConnectionOffloadHardwareCapabilities`

A pointer to an NDIS_TCP_CONNECTION_OFFLOAD structure that indicates all the connection offload
capabilities that are supported by the miniport adapter. These capabilities include capabilities that are
currently disabled by standardized keywords in the registry.

## Remarks

A miniport driver that supports task offload or connection offload passes a pointer to an
NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES structure in the
*MiniportAttributes* parameter of the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. A miniport driver calls
**NdisMSetMiniportAttributes** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
during initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_TASK_OFFLOAD_HEADER](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff559004(v=vs.85))

[NDIS_TCP_CONNECTION_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_connection_offload)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)