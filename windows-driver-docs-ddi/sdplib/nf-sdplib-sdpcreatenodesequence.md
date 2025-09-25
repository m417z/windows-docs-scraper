# SdpCreateNodeSequence function

## Description

The Bluetooth
**SdpCreateNodeSequence** function is used to create an empty sequence SDP node.

## Parameters

### `tag` [in]

A profile driver defined tag to associate with the node.

## Return value

If successful, this function returns a pointer to the newly allocated
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure. If not successful, this
function returns **NULL**.

## Remarks

After a sequence node is created by calling the
**SdpCreateNodeSequence** function, Bluetooth drivers can call the
[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode) function to insert other nodes into the sequence node or to add the
new sequence node to another sequence node.

A sequence node can be added as a top-level attribute of an SDP record by calling the
[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree) function.

## See also

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree)

[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode)