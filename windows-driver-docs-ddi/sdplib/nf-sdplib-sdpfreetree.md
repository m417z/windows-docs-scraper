# SdpFreeTree function

## Description

The Bluetooth
**SdpFreeTree** function is used to free the memory allocated for the tree-based representation of an SDP
record.

## Parameters

### `Tree` [in]

The root node of the SDP tree-based representation to be freed.

## Return value

Possible return values include:

## Remarks

Callers should perform an
**SdpFreeTree** call when the tree-based representation of an SDP record is no longer needed. The
[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree) and
[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree) functions
allocate the memory for the tree representations of SDP records that they create. The
**SdpFreeTree** function releases the memory allocated to the
[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node) structure that these
functions create and all
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structures associated with the tree
representation.

Bluetooth profile drivers can obtain a pointer to the
**SdpFreeTree** function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface) structure.

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node)

[SdpConvertStreamToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/nc-bthsdpddi-pconvertstreamtotree)

[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree)