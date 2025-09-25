# _SDP_NODE structure

## Description

The SDP_NODE structure holds information about an element in a tree-based representation of an SDP
record.

## Members

### `hdr`

An
[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header) structure that contains
links to peer SDP_NODE structures and the data type of the current node.

### `DataSize`

The size, in bytes, of the
[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data) union held in the
**u** member.

### `u`

An SDP_NODE_DATA union that contains the data associated with the SDP record's node.

### `Reserved`

Reserved for future use. Do not use.

## Remarks

Each SDP_NODE structure in the tree representation of an SDP record contains a SDP_NODE_HEADER
structure and an SDP_NODE_DATA union.

The header specifies the type of data. Driver developers can access links to peer SDP_NODE structures
by calling the
[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure of the header. By evaluating
`Node.hdr.Link.Flink`and
`Node.hdr.Link.Blink`, drivers can obtain the addresses of peer
nodes in the tree. Keep in mind that
**LIST_ENTRY** pointers contain the addresses of other LIST_ENTRY structures, and that the profile
drivers must use the
[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) memory manager macro to
extract the address of the containing node record.

## See also

[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)

[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data)

[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header)