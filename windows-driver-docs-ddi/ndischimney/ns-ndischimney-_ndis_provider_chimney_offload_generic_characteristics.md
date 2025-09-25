# _NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure specifies the generic chimney
offload miniport entry points of an offload target or intermediate driver. Generic chimney offload entry
points pertain to all chimney offload types. Currently, TCP chimney offload is the only defined chimney
offload type.

## Members

### `Header`

The header of the NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure. The header is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
NDIS_OBJECT_HEADER structure contains the revision number of the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure and the size of the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure, including the header, in bytes. The
**Type** member of the header is not significant.

### `Flags`

Reserved for system use.

### `InitiateOffloadHandler`

The entry point of the driver's
[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler) function.

### `TerminateOffloadHandler`

The entry point of the driver's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function.

### `UpdateOffloadHandler`

The entry point of the driver's
[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) function.

### `InvalidateOffloadHandler`

The entry point of the driver's
[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler) function.

### `QueryOffloadHandler`

The entry point of the driver's
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function.

## Remarks

To register its generic chimney offload entry points, an offload target or intermediate driver calls
the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
in the context of the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. To the
**NdisSetOptionalHandlers** function, the offload target or intermediate driver passes a pointer to the
NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS structure.

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler)

[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)