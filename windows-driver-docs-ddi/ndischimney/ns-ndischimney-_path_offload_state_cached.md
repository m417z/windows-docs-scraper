# _PATH_OFFLOAD_STATE_CACHED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The PATH_OFFLOAD_STATE_CACHED structure contains the cached variable of a path state object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the PATH_OFFLOAD_STATE_CACHED structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `PathMtu`

The maximum transmission unit (MTU) for the path (see RFC 1191 for IPv4, and RFC 1981 for
IPv6).

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

When passed to an offload target, a PATH_OFFLOAD_STATE_CACHED structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the PATH_OFFLOAD_STATE_CACHED structure.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const)

[PATH_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_delegated)