# _NEIGHBOR_OFFLOAD_STATE_DELEGATED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NEIGHBOR_OFFLOAD_STATE_DELGATED structure contains the delegated variable of a neighbor state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the NEIGHBOR_OFFLOAD_STATE_DELEGATED structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `NicReachabilityDelta`

The NIC's current time minus the
**NicReachabilityDelta** is the last time that the offload target confirmed neighbor reachability (see
forward reachability in RFC 2461). For information about how the offload target uses this variable, see
[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate).
**NicReachabilityDelta** is measured in units of clock ticks.

## Remarks

The host stack provides initial values for the
**NicReachabilityDelta** variable when it offloads the variable to the offload target. After it's been
offloaded, the
**NicReachabilityDelta** variable is owned and maintained by the offload target. Only the offload
target can change the value of an offloaded
**NicReachabilityDelta** variable. The offload target does not notify the host stack of changes to the
values of an offloaded
**NicReachabilityDelta** variable. However, the host stack can query the value of an offloaded
**NicReachabilityDelta** variable, which causes NDIS to call the offload target's
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function.
When the host stack terminates the offload of a neighbor state object by causing NDIS to call the offload
target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target passes the value of the
**NicReachabilityDelta** variable in the terminated state object back to the host stack.

When passed to an offload target, a NEIGHBOR_OFFLOAD_STATE_DELEGATED structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the NEIGHBOR_OFFLOAD_STATE_DELEGATED structure.

## See also

[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)