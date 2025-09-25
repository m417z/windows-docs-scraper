# _NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure specifies a protocol driver's
generic chimney offload entry points. Generic chimney offload entry points apply to all chimney offload
types. Currently, TCP chimney offload is the only defined chimney offload type.

## Members

### `Header`

The header of the NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure. The header is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
NDIS_OBJECT_HEADER structure contains the revision number of the
NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure and the size of the
NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure, including the header, in bytes. The
**Type** member of the header is not significant.

### `Flags`

Reserved for system use.

### `InitiateOffloadCompleteHandler`

Specifies the entry point of the driver's
[ProtocolInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-initiate_offload_complete_handler) function.

### `TerminateOffloadCompleteHandler`

The entry point of the driver's
[ProtocolTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-terminate_offload_complete_handler) function.

### `UpdateOffloadCompleteHandler`

The entry point of the driver's
[ProtocolUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-update_offload_complete_handler) function.

### `InvalidateOffloadCompleteHandler`

The entry point of the driver's
[ProtocolInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-invalidate_offload_complete_handler) function.

### `QueryOffloadCompleteHandler`

The entry point of the driver's
[ProtocolQueryOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-query_offload_complete_handler) function.

### `IndicateOffloadEventHandler`

The entry point of the driver's
[ProtocolIndicateOffloadEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-indicate_offload_event_handler) function.

## Remarks

To register its generic chimney offload entry points, a protocol or intermediate driver calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
in the context of the
[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. To the
**NdisSetOptionalHandlers** function,
the protocol or intermediate driver passes a pointer to the
NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[ProtocolIndicateOffloadEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-indicate_offload_event_handler)

[ProtocolInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-initiate_offload_complete_handler)

[ProtocolInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-invalidate_offload_complete_handler)

[ProtocolQueryOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-query_offload_complete_handler)

[ProtocolSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[ProtocolTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-terminate_offload_complete_handler)

[ProtocolUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-update_offload_complete_handler)