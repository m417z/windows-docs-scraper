# _SDP_TREE_ROOT_NODE structure

## Description

The SDP_TREE_ROOT_NODE structure is the root element of a tree-based representation of an SDP
record.

## Members

### `RootNode`

An
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure that represents the root node of
a tree-based representation of an SDP record.

## Remarks

Several SDP functions access or output this structure when they build a tree-based SDP record or
convert a raw SDP record stream into a tree-based record.

The
[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree) function adds
an SDP_NODE structure that contains SDP attribute information to an existing SDP_TREE_ROOT_NODE
structure.

The
[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree) function
outputs this structure as the root element of an SDP record that it converts from a stream to a
tree-based structure.

The
[SdpConvertTreeToStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconverttreetostream) function uses
an existing SDP_TREE_ROOT_NODE structure as input when it converts a tree-based representation of an SDP
record into a stream.

The
[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree) function creates an
empty SDP_TREE_ROOT_NODE structure. This is the first step in creating an SDP record as a tree. After the
SDP tree is completed, a profile driver that is using SDP to advertise its service can convert the tree
into an SDP record stream using the
**SdpConvertTreeToStream** function.

The
[SdpFindAttributeInTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfindattributeintree) function
searches a populated SDP_TREE_ROOT_NODE structure for an SDP attribute value.

## See also

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree)

[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree)

[SdpConvertTreeToStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconverttreetostream)

[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree)

[SdpFindAttributeInTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfindattributeintree)