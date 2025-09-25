# SdpAppendNodeToContainerNode function

## Description

The Bluetooth
**SdpAppendNodeToContainerNode** function is used to attach an SDP node to a sequence or alternative SDP
node.

## Parameters

### `Parent` [in]

The SDP sequence or alternative node to which the
**SdpAppendNodeToContainerNode** function adds the child node.

### `Node`

The SDP node to add to the parent node.

## Return value

Possible return values include:

## Remarks

Use the
**SdpAppendNodeToContainerNode** function to insert any type of
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) into a sequence or alternative node,
including other sequences.

Do not use this function to attach attribute nodes to the top level of an SDP record. Call the
[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree) function to
perform that action. For more information about the tree structure, see
[Converting SDP Records to a
Tree Structure](https://learn.microsoft.com/previous-versions/ff536672(v=vs.85)).

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface).

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree)