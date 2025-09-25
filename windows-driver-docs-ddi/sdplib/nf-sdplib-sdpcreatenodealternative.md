# SdpCreateNodeAlternative function

## Description

The Bluetooth
**SdpCreateNodeAlternative** function is used to create an empty alternative sequence SDP node.

## Parameters

### `tag` [in]

A profile driver defined tag to associate with the node.

## Return value

If successful, this function returns a pointer to the newly allocated
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure. If not successful, this
function returns
**NULL**.

## Remarks

After an alternative sequence node is created by calling the
**SdpCreateNodeAlternative** function, Bluetooth drivers can call the
[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode) function to insert other nodes into the alternative sequence node or
to add the new alternative sequence node to another alternative sequence node.

An alternative sequence node can be added as a top-level attribute of an SDP record by calling the
[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree) function.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface).

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree)

[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode)