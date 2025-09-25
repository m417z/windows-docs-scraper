# _NET_BUFFER_DATA structure

## Description

The NET_BUFFER_DATA structure contains information for managing the data buffers that are attached to
a NET_BUFFER structure, and it identifies the next
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in a list of NET_BUFFER
structures.

## Members

### `Next`

A pointer to the next NET_BUFFER structure in a linked list of NET_BUFFER structures. If this
structure is the last NET_BUFFER structure in the list, this member is **NULL**.

### `CurrentMdl`

A pointer to the first MDL that the current driver is using. This member provides an optimization
that improves performance by skipping over any MDLs that the current driver is not using.

### `CurrentMdlOffset`

The offset, in bytes, to the beginning of the
*used data space* in the MDL that is specified by the
**CurrentMdl** member.

### `NbDataLength`

The length, in bytes, of the used data space in the MDL chain. The maximum length is 0xFFFFFFFF
bytes.

### `MdlChain`

A pointer to a linked list of MDLs that map a data buffer. The data buffer stores the network
data.

### `DataOffset`

The offset, in bytes, from the beginning of the MDL chain to the beginning of the network data in
the MDL chain. This offset is also the size, in bytes, of the
*unused data space*.

## Remarks

The
[NET_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_header) structure contains a
NET_BUFFER_DATA structure that defines data for the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. To access the members of
NET_BUFFER_DATA, use the
[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart) and
[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) functions, and the following macros:

[NET_BUFFER_NEXT_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-next-nb)

[NET_BUFFER_FIRST_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-first-mdl)

[NET_BUFFER_DATA_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-offset)

[NET_BUFFER_DATA_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-length)

[NET_BUFFER_CURRENT_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl)

[NET_BUFFER_CURRENT_MDL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl-offset)

**Note** The C and C++ compilers use different definitions for these macros. Failure to use
the macros can cause problems when switching compilers.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_CURRENT_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl)

[NET_BUFFER_CURRENT_MDL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl-offset)

[NET_BUFFER_DATA_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-length)

[NET_BUFFER_DATA_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-offset)

[NET_BUFFER_FIRST_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-first-mdl)

[NET_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_header)

[NET_BUFFER_NEXT_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-next-nb)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)