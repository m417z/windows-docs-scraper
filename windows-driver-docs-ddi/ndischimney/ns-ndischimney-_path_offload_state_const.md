# _PATH_OFFLOAD_STATE_CONST structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The PATH_OFFLOAD_STATE_CONST structure contains the constant variables of a path state object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the PATH_OFFLOAD_STATE_CONST structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `SourceAddress`

A pointer to the source IP address of a TCP connection. If the TCP connection is over IPv4, the
address is a 4-byte IPv4 address. If the TCP connection is over IPv6, the address is a 16-byte IPv6
address. The source address bytes are always in network byte order.

### `DestinationAddress`

A pointer to the destination IP address of a TCP connection. If the TCP connection is over IPv4,
the address is a 4-byte IPv4 address. If the TCP connection is over IPv6, the address is a 16-byte IPv6
address. The destination address bytes are always in network byte order.

## Remarks

The value of each path constant variable does not change during the life of a TCP connection. Neither
the host stack nor the offload target changes the values of a path constant variable. When the host stack
terminates the offload of the path state object by causing NDIS to call the offload target's
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function, the offload target does not return the value of the offloaded
path constant variables to the host stack.

When passed to an offload target, a PATH_OFFLOAD_STATE_CONST structure is associated with an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which contains a header that is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
**Revision** member of the NDIS_OBJECT_HEADER structure, in this case, specifies the revision number of
the PATH_OFFLOAD_STATE_CONST structure.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[PATH_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_cached)

[PATH_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_delegated)