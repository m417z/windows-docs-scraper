# _OFFLOAD_STATE_HEADER structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The OFFLOAD_STATE_HEADER structure serves as a header in an offload state structure.

## Members

### `Length`

The total size, in bytes, of the offload state structure that includes the OFFLOAD_STATE_HEADER
member. This size includes the size of the OFFLOAD_STATE_HEADER member and the other members of the
offload state structure.

### `RecognizedOptions`

Reserved.

## Remarks

The following offload state structures include an OFFLOAD_STATE_HEADER structure:

[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const)

[PATH_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_cached)

[PATH_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_delegated)

[TCP_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_const)

[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)