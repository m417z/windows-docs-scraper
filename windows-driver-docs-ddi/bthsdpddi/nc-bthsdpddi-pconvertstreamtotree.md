# PCONVERTSTREAMTOTREE callback function

## Description

The Bluetooth
**SdpConvertStreamToTree** function is used to create a Microsoft proprietary tree-based representation
of an SDP record, while leaving the original stream-based representation unmodified.

## Parameters

### `Stream`

The SDP record stream to convert into a tree-based representation.

### `Size`

The size of the source SDP record stream.

### `Node`

A pointer to the
[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node) structure that serves
as the root of the SDP tree-based representation of the SDP record.

### `tag`

Specifies a 4-byte
[pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory
allocation. For more information about pool tags, see
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Return value

Possible return values include:

STATUS_SUCCESS

STATUS_INSUFFICIENT_RESOURCES

STATUS_INVALID_PARAMETER

## Remarks

Because a tree can be traversed by evaluating pointers, the
**SdpConvertStreamToTree** function can make it easier for profile drivers to extract information from
an SDP record.

The tree representation of the SDP record that results from calling the
**SdpConvertStreamToTree** function consists of a series of interconnected
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structures. The root node contains a single
SDP_TREE_ROOT_NODE structure.

Each SDP_NODE structure contains an
[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header) structure and an
[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data) union. The header specifies the
type of data, and Bluetooth profile drivers can access links to peer SDP_NODE structures through the
[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) system structure. By evaluating this
structure's
`Node.hdr.Link.Flink`and
`Node.hdr.Link.Blink`, drivers can obtain the addresses of peer
nodes in the tree. Keep in mind that the pointers in the LIST_ENTRY structure hold addresses to other
LIST_ENTRY structures, and that Bluetooth drivers must use the
[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) memory manager macro to
extract the address of the containing node record.

By using the
[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data) union's
**sequence** and
**alternative** members, profile drivers can access sub-elements of the tree. If the data type of the
node is
**SDP_TYPE_SEQUENCE**, the node is an SDP sequence. If the data type of the node is
**SDP_TYPE_ALTERNATIVE**, the node is an SDP alternative sequence. In the first case, the sequence
member is valid and contains the information necessary to access the portion of the tree corresponding
with the sequence. In the second case, the alternative member is valid and contains the information
necessary to access the portion of the tree corresponding to the alternative. The
**sequence** or
**alternative** member, when used, contains an extra SDP_NODE_HEADER structure that is used to access
the nodes in the sequence or alternative. For example,
`node->u.sequence.Flink`points to the LIST_ENTRY structure of
the first member of the sequence represented by the node.

The remaining members of the data union contain actual data extracted from the SDP stream. For most
types, the data is directly present in the structure. However, for strings and URLs, a pointer is
provided to the actual data. The memory for the string is allocated by the
**SdpConvertStreamToTree** function call and must be freed by calling the
[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree) function for the tree.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface).

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)

[**CONTAINING_RECORD**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)

[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data)

[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header)

[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node)

[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree)