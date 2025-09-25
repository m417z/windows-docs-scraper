# _NEIGHBOR_OFFLOAD_STATE_CACHED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NEIGHBOR_OFFLOAD_STATE_CACHED structure contains the cached variables of a neighbor state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the NEIGHBOR_OFFLOAD_STATE_CACHED structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `DlDestinationAddress`

Specifies the media access control (MAC) address of the next hop (neighbor).

### `HostReachabilityDelta`

The host stack's current time minus
**HostReachabilityDelta** is the last time that the host stack confirmed neighbor reachability (see
forward reachability in RFC 2461). For information about how the offload target uses this variable, see
[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate).
**HostReachabilityDelta** is measured in units of clock ticks.

## Remarks

Cached variables are owned and maintained by the host stack. An offload target must not change the
value of a cached variable unless requested to do so by the host stack. If the value of a cached variable
changes, the host stack requests an update of the variable, which causes NDIS to call the offload
target's
[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) function.
When the host stack terminates the offload of one or more state objects by causing NDIS to call the
offload target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target does not return the value of offloaded
constant variables to the host stack.

When passed to an offload target, a NEIGHBOR_OFFLOAD_STATE_CACHED structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the NEIGHBOR_OFFLOAD_STATE_CACHED structure.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)