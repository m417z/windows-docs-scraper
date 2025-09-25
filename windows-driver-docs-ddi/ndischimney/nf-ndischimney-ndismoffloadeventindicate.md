# NdisMOffloadEventIndicate function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMOffloadEventIndicate** function to indicate various events to the host stack.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. This structure identifies the offloaded state object
on which the indication is being made. Note that there is only one NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure. There is not a linked list of such structures.

The offload target supplies a valid
*OffloadBlockList* pointer when making a
**NeighborReachabilityQuery** indication. In this case, the offload target supplies a
[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const) structure, a
[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached) structure, and a
[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated) structure (in that order) immediately following the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure referenced by the
*OffloadBlockList* pointer.

An offload target must initialize the following members of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure that it passes to the
**NdisMOffloadEventIndicate** function:

* All members of the NDIS_OBJECT_HEADER structure, including
  **Type**,
  **Revision**, and
  **Size** . The offload target must initialize
  **Type** to
  **NeighborOffloadState**.
* The
  **NextBlock** pointer to a non-**NULL** value if there is a next block; otherwise, to **NULL**.
* The
  **DependentBlockList** pointer to **NULL**.
* The
  **Status** member to NDIS_STATUS_SUCCESS.

The offload target does not have to initialize any other members of the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure.

For all indications other than the
**NeighborReachabilityQuery** indication, the offload target supplies an
*OffloadBlockList* pointer that is **NULL**.

### `IndicationCode` [in]

The event being indicated is specified as one of the following INDICATE_OFFLOAD_EVENT values:

#### NeighborReachabilityQuery

Indicates that a neighbor cache entry (NCE) has become stale. For more information about NCEs,
see RFC 2461.

#### NeighborReachabilityInDoubt

Reserved.

## Remarks

The host stack uses the
**NeighborReachabilityQuery** indication to detect neighbor unreachability for IPv4 and IPv6. For a
detailed description of this indication, see
[Making a
NeighborReachabilityQuery Indication](https://learn.microsoft.com/windows-hardware/drivers/network/making-a-neighborreachabilityquery-indication).

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)