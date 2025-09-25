# SdpCreateNodeBoolean function

## Description

The Bluetooth
**SdpCreateNodeBoolean** function is used to allocate and initialize an
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure to a Boolean type.

## Parameters

### `bVal` [in]

The Boolean value that is used to initialize the SDP_NODE structure.

### `tag` [in]

A profile driver defined tag to associate with the node.

## Return value

If successful, this function returns a pointer to the newly allocated SDP_NODE structure. If not
successful, this function returns **NULL**.

## Remarks

The data associated with the
**SdpCreateNodeBoolean** function is copied into the node, and the original data can be freed at any
time.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface).

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)