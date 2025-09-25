# SdpCreateNodeUUID32 function

## Description

The Bluetooth
**SdpCreateNodeUUID32** function is used to allocate and initialize an
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure to a 32-bit UUID type.

## Parameters

### `uuidVal4`

The 32-bit UUID value to initialize the SDP_NODE structure.

### `tag` [in]

A profile driver defined tag to associate with the node.

## Return value

If successful, this function returns a pointer to the newly allocated SDP_NODE structure. If not
successful, this function returns **NULL**.

## Remarks

After the
**SdpCreateNodeUUID32** function allocates an
[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure, it initializes the structure in
the following ways.

It ensures that the SDP_NODE structure's data type and data size fields are set appropriately.

It ensures that the pointer members of the associated
[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header) structure are initialized
to point to the node itself. This creates a valid list with only one element.

It ensures that the
*value* parameter passed to the function is copied to the appropriate element of the
[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data) union that is associated with
the SDP_NODE structure.

The data associated with the
**SdpCreateNodeUUID32** function is copied into the node, and the original data can be freed at any
time.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface) structure.

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)

[SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)

[SDP_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_data)

[SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header)