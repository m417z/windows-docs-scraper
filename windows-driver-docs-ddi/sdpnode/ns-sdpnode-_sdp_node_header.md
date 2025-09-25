# _SDP_NODE_HEADER structure

## Description

The SDP_NODE_HEADER structure holds information about an element in a tree-based representation of an
SDP record.

## Members

### `Link`

A linked-list structure that is used to link peer SDP record nodes when this structure is part of
an
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure. This member is used to link the
first child of the node when the header is
**u.sequence** or
**u.alternative** part of the individual SDP_NODE structure.

### `Type`

The data type of the
[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data) union held in the
**u** member of the SDP_NODE structure.

### `SpecificType`

Extra information about the data type associated with the
**SDP_NODE_DATA** union that is associated with the SDP record element.

## Remarks

Each SDP_NODE structure in the tree representation of an SDP record contains a SDP_NODE_HEADER
structure and an
**SDP_NODE_DATA** union.

The header specifies the type of data. Driver developers can access links to peer SDP_NODE structures
by calling the
[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure of the header. By evaluating
`Node.hdr.Link.Flink`and
`Node.hdr.Link.Blink`, drivers can obtain the addresses of peer
nodes in the tree. Keep in mind that
**LIST_ENTRY** pointers contain the address of other LIST_ENTRY structures, and that the profile driver
must use the
[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) memory manager macro to
extract the address of the containing node record.

## See also

[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)

[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data)