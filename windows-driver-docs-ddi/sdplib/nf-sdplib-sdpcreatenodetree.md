# SdpCreateNodeTree function

## Description

The Bluetooth
**SdpCreateNodeTree** function is used to allocate an empty root
[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node) structure.

## Parameters

### `tag` [in]

A profile driver defined tag to associate with the node.

## Return value

If successful, this function returns a pointer to the newly allocated SDP_TREE_ROOT_NODE
structure. If not successful, this function returns **NULL**.

## Remarks

Calling the
**SdpCreateNodeTree** function is the first step in building an SDP tree. After a Bluetooth profile
driver allocates a root node by using this function, the node can be populated by using calls to other
functions pointed to by the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface) structure.

When an SDP tree is no longer needed, the Bluetooth profile driver should destroy it by calling the
[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree) function.
**SdpFreeTree** frees the root node and all child nodes that have been attached to it. Individual
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structures can be freed by calling the
[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) driver support routine as long as they
are no longer part of a tree or other list.

Bluetooth profile drivers can obtain a pointer to this function through the BTHDDI_SDP_NODE_INTERFACE
structure.

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SDP_TREE_ROOT_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_tree_root_node)

[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree)